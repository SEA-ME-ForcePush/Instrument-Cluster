#!/bin/bash

# Variables
GITHUB_USER="SEA-ME-ForcePush"
GITHUB_REPO="Instrument-Cluster"
ARTIFACT_NAME="build-artifacts"
DOWNLOAD_DIR="/home/pushforce/artifacts"
TMP_DIR="/tmp/github_artifacts"
TOKEN="my_token"
EXECUTE_FILE_NAME="Instrument-Cluster"


# Create necessary directorie
if [ ! -d $DOWNLOAD_DIR ]; then
  mkdir -p $DOWNLOAD_DIR
  echo "[0] download dir[$DOWNLOAD_DIR] created"
fi

if [ ! -d $TMP_DIR ]; then
  mkdir -p $TMP_DIR
  echo "[0] temporary dir[$TMP_DIR] created"
fi

# Get the latest successful workflow run ID for the main branch
workflow_run_id=$(curl -s -H "Accept: application/vnd.github.v3+json" \
  "https://api.github.com/repos/$GITHUB_USER/$GITHUB_REPO/actions/runs?branch=main&status=success" \
  | jq -r '.workflow_runs[0].id')


# Check if the workflow_run_id is null or empty
if [ -z "$workflow_run_id" ]; then
  echo "Failed to fetch workflow run ID."
  exit 1
fi


# Get the artifact download URL
artifact_url=$(curl -s -H "Accept: application/vnd.github.v3+json" \
  "https://api.github.com/repos/$GITHUB_USER/$GITHUB_REPO/actions/runs/$workflow_run_id/artifacts" \
  | jq -r --arg ARTIFACT_NAME "$ARTIFACT_NAME" '.artifacts[] | select(.name == $ARTIFACT_NAME) | .archive_download_url')


# Check if the artifact_url is null or empty
if [ -z "$artifact_url" ]; then
  echo "Failed to fetch artifact URL."
#  exit 1
fi

# Remove old artifacts
if [ -e $DOWNLOAD_DIR ]; then
  sudo rm -rf $DOWNLOAD_DIR/*
fi

echo "[2] download the artifact!!"
# Download the artifact
curl -L -o $TMP_DIR/${ARTIFACT_NAME}.zip -H "Authorization: token $TOKEN" $artifact_url


# Check if the artifact was downloaded
if [ ! -f "$TMP_DIR/${ARTIFACT_NAME}.zip" ]; then
  echo "Failed to download artifact."
  exit 1
fi

echo "[3] get executable access to download dir"
mkdir -p $DOWNLOAD_DIR
sudo chmod 777 $DOWNLOAD_DIR

echo "[4] unzip the new artifact"
# Unzip the new artifact
unzip $TMP_DIR/${ARTIFACT_NAME}.zip -d $DOWNLOAD_DIR

echo "[5] clean up the temporary files"
# Clean up temporary files
rm -rf $TMP_DIR

echo "[6] Artifacts updated successfully."

if [ -d $DOWNLOAD_DIR/$EXECUTE_FILE_NAME ]; then
  if [ ! -n sh can_script.sh ]; then
    echo "[7] Link CAN0 and execute 'candump can0'" 
  else
    echo "Failed to execute Qt Program.. :("
  fi

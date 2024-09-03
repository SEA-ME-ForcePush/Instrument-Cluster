#!/bin/bash

# Variables
GITHUB_USER="SEA-ME-ForcePush"
GITHUB_REPO="Instrument-Cluster"
ARTIFACT_NAME="build-artifacts"
DOWNLOAD_DIR="/home/pushforce/artifacts"
TMP_DIR="/tmp/github_artifacts"
TOKEN="put_your_github_token_here"

# Create necessary directories
mkdir -p $DOWNLOAD_DIR
mkdir -p $TMP_DIR

# Get the latest successful workflow run ID for the main branch
workflow_run_id=$(curl -s -H "Accept: application/vnd.github.v3+json" \
  "https://api.github.com/repos/$GITHUB_USER/$GITHUB_REPO/actions/runs?branch=dev-ops&status=success" \
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
  exit 1
fi

# Remove old artifacts
 rm -rf $DOWNLOAD_DIR/*

# Download the artifact
curl -L -o $TMP_DIR/${ARTIFACT_NAME}.zip -H "Authorization: token $TOKEN" $artifact_url

# Check if the artifact was downloaded
if [ ! -f "$TMP_DIR/${ARTIFACT_NAME}.zip" ]; then
  echo "Failed to download artifact."
  exit 1
fi

# Unzip the new artifact
unzip $TMP_DIR/${ARTIFACT_NAME}.zip -d $DOWNLOAD_DIR

# Clean up temporary files
 rm -rf $TMP_DIR

chmod +x ./artifacts/InstrumentCluster

echo "Artifacts updated successfully."
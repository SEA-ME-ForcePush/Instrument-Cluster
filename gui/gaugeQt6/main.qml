import QtQuick 6.2
import QtQuick.Controls 6.2

ApplicationWindow {
    id: window
    width: 800
    height: 800
    visible: true

    Gauge {
        id: gauge
        maxValue: 100  // Set to match the scaled data range
        anchors.centerIn: parent
        width: 400  // Larger gauge size
        height: 400

        Behavior on value { NumberAnimation { duration: 100 } }

        // Update the digit display when the gauge value changes
        onValueChanged: speedDigit.text = gauge.value.toFixed(0) + " km/h"
    }

    // Digit display positioned below the gauge
    Text {
        id: speedDigit
        text: gauge.value.toFixed(0) + " km/h"  // Show speed with "km/h" suffix
        font.pixelSize: 40  // Make the font size larger for better visibility
        color: "white"
        anchors.top: gauge.bottom
        anchors.horizontalCenter: gauge.horizontalCenter
        anchors.topMargin: 20  // Adjust margin to control spacing below the gauge
        antialiasing: true
    }

    Connections {
        target: canHandler

        function onFrameReceived(frameId, payload) {
            if (payload.length >= 2) {
                var rawValue = payload[1];
                var scaledValue = (rawValue / 255) * 100;
                gauge.value = scaledValue;
            }
        }
    }



}

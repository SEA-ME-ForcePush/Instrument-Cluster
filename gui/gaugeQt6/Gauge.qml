import QtQuick 6.2
import QtQuick.Controls 6.2
import QtQuick.Layouts 6.2

Item {
    id: gauge
    width: 300
    height: 300

    property real minValue: 0
    property real maxValue: 250
    property real value: 0  // Bind this value to CAN data later

    Canvas {
        id: backgroundCanvas
        anchors.fill: parent

        onPaint: {
            var ctx = getContext("2d");
            var centerX = width / 2;
            var centerY = height / 2;
            var radius = Math.min(width, height) / 2 - 10;

            // Clear the canvas
            ctx.clearRect(0, 0, width, height);

            // Draw background circle
            ctx.beginPath();
            ctx.arc(centerX, centerY, radius, 0, 2 * Math.PI);
            ctx.fillStyle = "black";
            ctx.fill();

            // Draw the gauge arc
            var startAngle = -144 * Math.PI / 180;
            var endAngle = startAngle + (288 * (gauge.value - gauge.minValue) / (gauge.maxValue - gauge.minValue)) * Math.PI / 180;
            ctx.beginPath();
            ctx.arc(centerX, centerY, radius, startAngle, endAngle);
            ctx.lineWidth = 10;
            ctx.strokeStyle = "#00FF00";
            ctx.stroke();

            // Draw needle
            ctx.beginPath();
            ctx.moveTo(centerX, centerY);
            var needleAngle = startAngle + (288 * (gauge.value - gauge.minValue) / (gauge.maxValue - gauge.minValue)) * Math.PI / 180;
            ctx.lineTo(centerX + (radius - 20) * Math.cos(needleAngle), centerY + (radius - 20) * Math.sin(needleAngle));
            ctx.lineWidth = 4;
            ctx.strokeStyle = "red";
            ctx.stroke();

            // Draw center circle
            ctx.beginPath();
            ctx.arc(centerX, centerY, 8, 0, 2 * Math.PI);
            ctx.fillStyle = "#fff";
            ctx.fill();
        }

        onWidthChanged: requestPaint()
        onHeightChanged: requestPaint()
    }

    // Use property binding to trigger redraw
    onValueChanged: backgroundCanvas.requestPaint()

    RowLayout {
        id: tickMarks
        anchors.fill: parent

        Repeater {
            model: 11  // 10 ticks
            delegate: Item {
                width: 10
                height: gauge.height / 2
                rotation: 144 + index * 288 / (model - 1)
                Rectangle {
                    width: 4
                    height: 20
                    color: index * 25 <= gauge.value ? "white" : "#777776"
                    anchors.bottom: parent.bottom
                }
            }
        }
    }

    // Add this Connections element if you need to listen to signals from another source
    Connections {
        target: gauge

        function onValueChanged(newValue) {
            backgroundCanvas.requestPaint();  // Trigger repaint when value changes
        }
    }
}

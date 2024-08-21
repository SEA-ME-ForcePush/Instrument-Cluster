import QtQuick 2.7
import QtQuick.Controls 2.0

ApplicationWindow {
    id: window
    width: 800
    height: 800
    visible: true

    Gauge {
        id: gauge
        value: speedController.speed  // Continuously update based on speedController.speed
        maximumValue: 250
        anchors {
            fill: parent
            margins: window.height * 0.2
        }

        Behavior on value { NumberAnimation { duration: 100 }}

        Component.onCompleted: {
            forceActiveFocus();
        }

        Keys.onSpacePressed: speedController.updateSpeed()
        Keys.onReleased: {
            if (event.key === Qt.Key_Space) {
                event.accepted = true;
            }
        }
    }
}


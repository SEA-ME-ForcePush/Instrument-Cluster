import QtQuick 6.2
import QtQuick.Controls 6.2

ApplicationWindow {
    id: window
    width: 800
    height: 800
    visible: true

    Gauge {
        id: gauge
        value: speedController.speed  // Continuously update based on speedController.speed
        maxValue: 250
        anchors.fill: parent
        anchors.margins: window.height * 0.2

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

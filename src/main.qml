import QtQuick 2.7
import QtQuick.Controls 2.0

ApplicationWindow {
    id: window
    width: 800
    height: 800
    visible: true

    // Include the Gauge component from Gauge.qml
    Gauge {
        id: gauge
        maximumValue: 300
        anchors.fill: parent
        anchors.margins: window.height * 0.2

        Behavior on value { NumberAnimation { duration: 100 }}

        Component.onCompleted: {
            forceActiveFocus();
        }
    }
}

import QtQuick 2.6
import QtQuick.Window 2.2

Window {
    visible: true;
    title: qsTr("edit")
    width: 1404;
    height: 1872;

    Rectangle {
        anchors.fill: parent
        color: "white"

        Image {
            anchors.fill: parent
            source: "file:///home/root/everyones_an_epidemiologist.png"
        }
    }

}

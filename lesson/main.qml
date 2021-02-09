import QtQuick 2.14
import QtQuick.Window 2.14

//导入包
import QtQuick.Controls 2.14

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Button {
        text: "debug test"
        onClicked: {
            //在资源文件qml中进行输出信息
            console.debug("debug click me");
            console.error("error click me")
        }
    }
}

import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import todoppinterface.TodoInterface

Window {
    // width: 640
    // height: 480
    width: 360
    height: 640
    // color: "#FFF5F2"

    visible: true
    title: qsTr(TodoInterface.myAppName)

    ListView {
        clip: true
        anchors
        {
            top: topBar.bottom
            bottom: parent.bottom
            right: parent.right
            left: parent.left
            // margins: 20
        }
        // anchors.fill: parent
        width: parent.width
        // height: parent.height * 8 / 10
        spacing: 5
        model: TodoInterface
        // model: ListModel {
        //     ListElement {
        //         completed: false
        //         description: "TodoPPInterface.taskItemText()"
        //         priority: "A"
        //     }
        //     ListElement {
        //         completed: true
        //         description: "Do this important thing and this at this place"
        //         priority: "B"
        //     }
        //     ListElement {
        //         completed: false
        //         description: "Do this important thing and this at this place"
        //         priority: "A"
        //     }
        // }
        delegate: Rectangle {
            id: delegate
            // required property string description
            // required property bool completed
            // required property string priority
            required property string description
            required property bool completed
            required property string priority
            required property int index
            clip: true

            height: 100
            border.width: 1
            // color: "#f5babb"
            width: ListView.view.width   // Make sure delegate fills width of list

            TapHandler
            {

            }

            RowLayout {
                // anchors.fill: parent
                width: parent.width
                height: parent.height * 0.8
                // spacing: 5

                CheckBox {
                    id: isCompletedCheckBox
                    checked: completed
                    onClicked: TodoInterface.toggleCompletion(index)
                }

                Text {
                    text: description
                    wrapMode: Text.Wrap
                    // color: "#064232"
                    font.pixelSize: 20
                    font.strikeout: (completed)
                    Layout.fillWidth: true  // This is the key for wrapping in RowLayout
                }


            }
            RoundButton
            {
                flat: true
                width: 20
                height: 20
                icon
                {

                    name: "edit-delete"
                    width: 15
                    height: 15
                }
                // font.pixelSize: 10
                // text: priority
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                anchors.rightMargin: 30
                onClicked: TodoInterface.deleteTask(index)
                // anchors.horizontalCenter: parent
                // anchors.horizontalCenterOffset: parent.
            }


            Text
            {
                font.pixelSize: 10
                text: priority
                anchors.bottom: parent.bottom
                anchors.right: parent.right
                anchors.rightMargin: 60
                // anchors.horizontalCenter: parent
                // anchors.horizontalCenterOffset: parent.
            }
            // on

        }
    }



    // ColumnLayout
    // {
    // anchors.fill: parent
    // spacing: 5
    // Button
    // {
    //     text: "Add task"

    // }

    // }

    RoundButton
    {
        // radius: 100
        height: 60
        width: 60
        anchors
        {
            bottom: parent.bottom
            right: parent.right
            margins: 15
        }
        // flat: true
        // text: "ClickMe"
        icon
        {

            name: "list-add"
            width: 40
            height: 40
        }

        onClicked:
        {
            TodoInterface.setmyAppName("NewName")
            icon.name = "window-close"
            newTaskPage.visible = !newTaskPage.visible

        }
    }
    Rectangle
    {
        id: sideMenu
        height: parent.height
        width: parent.width /2
        visible: false
    }
    Rectangle
    {
        id: newTaskPage
        // visible: false
        height: parent.height /2
        width: parent.width
        visible: false
        TextArea
        {
            id: newTaskDesc
            height: parent.height * 3 /4
            width: parent.width
            anchors.top: parent.top

        }
        Button
        {
            text: "Add New Task"
            onClicked: TodoInterface.addTask(newTaskDesc.text)
            anchors.bottom: parent.bottom
        }
    }

    RowLayout
    {
        id: topBar
        width: parent.width
        anchors
        {
            // margins: 10
            top: parent.top
            right: parent.right
            left: parent.left
        }

        // height: parent.height * 2 / 10
        // TextArea
        // {
        //     id: newTaskText
        //     text: "Write New Task Text Here"
        // }
        // Button
        // {
        //     text: "Add task"
        //     onClicked:
        // }
        // TextField {
        //     id: taskField
        //     placeholderText: "Enter task"
        // }
        Button {
            // text: "Search"
            // icon.name: "menu"
            text: "Menu"
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
            flat: true
            onClicked: {
                sideMenu.visible = !sideMenu.visible
            }
        }

        Button {
            // text: "Search"
            icon.name: "system-search"
            Layout.alignment: Qt.AlignRight | Qt.AlignTop
            flat: true
            // onClicked: todoModel.addTask(taskField.text)
        }

    }

}

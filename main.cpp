#include <QGuiApplication>
#include <QQmlApplicationEngine>
// #include "todopp_interface.h"
#include "todo_model.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    // TodoPPInterface todo_interface{&app};
    // todo_interface.setmyAppName("The_Best_App_In_World");
    // qmlRegisterSingletonInstance("todoppinterface.TodoInterface", 1, 0, "TodoInterface", &todo_interface);
    TodoModel the_real_model{&app};
    qmlRegisterSingletonInstance("todoppinterface.TodoInterface", 1, 0, "TodoInterface", &the_real_model);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    // engine.loadFromModule("TodoPP_GUI", "MyImport");

    engine.loadFromModule("TodoPP_GUI", "Main");

    return app.exec();
}

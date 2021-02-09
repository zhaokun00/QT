#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
 //   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    /*
        QT最小应用步骤:
        1.定义QML引擎
        2.加载资源文件
        3.QT应用主事件循环
    */
    QGuiApplication app(argc, argv);

    //1.定义QML引擎
    QQmlApplicationEngine engine;

    const QUrl url(QStringLiteral("qrc:/main.qml"));

    #if 0
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    #endif

    //2.加载资源文件
    engine.load(url);

    //3.QT应用主事件循环
    return app.exec();
}

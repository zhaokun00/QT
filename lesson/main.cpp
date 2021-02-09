#include <QGuiApplication>
#include <QQmlApplicationEngine>
//要使用打印信息，包含以下头文件信息
#include<iostream>
#include <QDebug>

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

    //在源文件中输出打印信息
    {
        int i  = 100;
        //C++中标准的字符串类型
        std::string s = "QT";
        //QT中的字符串类型
        QString str = "QT";

        //c++标准的的输出信息
        std::cout << "debug std cout i = " << i << "str = " << s << std::endl;
        //QT中标准的输出信息，不能输出C++中的字符串类型
        qDebug() << "debug std cout i = " << i << "str = " << str ;
    }

    return app.exec();
}

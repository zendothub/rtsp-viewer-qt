// #include "mainwindow.h"
// #include <QApplication>
// #include <QDebug>
// #include <QIcon>

// int main(int argc, char *argv[]) {
//     QApplication a(argc, argv);
//     a.setWindowIcon(QIcon(":/icons/app_icon.png"));    // Hardcoded RTSP stream settings
//     QString rtspUrl = argv[1]; // RTSP Stream URL
//     QString windowTitle = argv[2];  // Window Title
//     int latency = 5;  // Lower buffer latency (in milliseconds)
//     bool sync = false; // Sync disabled (for real-time streaming)
//     int protocol = 0;  // 0 = UDP (faster), 4 = TCP (more stable)

//     qDebug() << "Launching RTSP Player with Hardcoded Settings:";
//     qDebug() << "RTSP URL: " << rtspUrl;
//     qDebug() << "Window Title: " << windowTitle;
//     qDebug() << "Latency: " << latency << "ms";
//     qDebug() << "Sync: " << (sync ? "Enabled" : "Disabled");
//     qDebug() << "Protocol: " << (protocol == 0 ? "UDP" : "TCP");

//     MainWindow w(rtspUrl, windowTitle, latency, sync, protocol);
//     w.show();

//     return a.exec();
// }



//below code for both rtsp_url and web_url


#include "mainwindow.h"
#include <QApplication>
#include <QIcon>
#include <QDebug>
#include <QCoreApplication>

int main(int argc, char *argv[]) {
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon(":/icons/app_icon.png"));    // Hardcoded RTSP stream settings

    if (argc < 5) {
        qDebug() << "Usage: rtsp_player <rtsp_url> <web_url> <drone_name>";
        return -1;
    }

    QString rtspUrl = argv[1]; // RTSP Stream URL
    QString webUrl = argv[2];  // Web URL
    QString droneName = argv[3]; // Drone Name
    QString cookie = argv[4];

    qDebug() << "Launching RTSP Player with Hardcoded Settings:";
    qDebug() << "RTSP URL: " << rtspUrl;
    qDebug() << "Web URL: " << webUrl;
    qDebug() << "Drone Name: " << droneName;
    qDebug() << "Cookie: " << cookie;

    MainWindow w(rtspUrl, webUrl, droneName, cookie);

    // MainWindow w(rtspUrl, webUrl, droneName);
    w.show();

    return a.exec();
}

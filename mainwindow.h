// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include <QMediaPlayer>
// #include <QVideoWidget>

// class MainWindow : public QMainWindow {
//     Q_OBJECT

// public:
//     explicit MainWindow(const QString &rtspUrl, const QString &windowTitle, int latency, bool sync, int protocol, QWidget *parent = nullptr);
//     ~MainWindow();

// private:
//     QMediaPlayer *player;
//     QVideoWidget *videoWidget;
// };

// #endif // MAINWINDOW_H



//full screen enabled




// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QMainWindow>
// #include <QVideoWidget>
// #include <QMediaPlayer>

// class MainWindow : public QMainWindow {
//     Q_OBJECT

// public:
//     explicit MainWindow(const QString &rtspUrl, const QString &windowTitle, int latency, bool sync, int protocol, QWidget *parent = nullptr);
//     ~MainWindow();

// protected:
//     // Add the declaration of resizeEvent here
//     void resizeEvent(QResizeEvent *event) override;

// private:
//     QMediaPlayer *player;
//     QVideoWidget *videoWidget;
// };

// #endif // MAINWINDOW_H


//below code for both rtsp_url and web_url


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QWebEngineView>  // For rendering Angular project
#include <QVBoxLayout>
#include <QHBoxLayout>  // For the horizontal layout
#include <QPushButton>   // For the reload button
#include <QResizeEvent>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(const QString &rtspUrl, const QString &webUrl, const QString &droneName, QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
    QWebEngineView *webView;
    QWidget *centralWidget;
    QHBoxLayout *layout;
   

    void handleRTSPError();
    // void handleRTSPBuffering(int percent);
    void handleRTSPStateChange(QMediaPlayer::State state);
};

#endif // MAINWINDOW_H

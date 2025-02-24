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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(const QString &rtspUrl, const QString &windowTitle, int latency, bool sync, int protocol, QWidget *parent = nullptr);
    ~MainWindow();

protected:
    // Add the declaration of resizeEvent here
    void resizeEvent(QResizeEvent *event) override;

private:
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};

#endif // MAINWINDOW_H

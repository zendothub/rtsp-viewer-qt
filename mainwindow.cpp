// #include "mainwindow.h"
// #include <QVBoxLayout>
// #include <QDebug>
// #include <QMediaPlayer>
// #include <QVideoWidget>

// MainWindow::MainWindow(const QString &rtspUrl, const QString &windowTitle, int latency, bool sync, int protocol, QWidget *parent)
//     : QMainWindow(parent) {
//     // Set fixed window size to 800x800
//     this->setFixedSize(800, 800);

//     // Set window title
//     this->setWindowTitle(windowTitle);

//     // Create layout
//     QWidget *centralWidget = new QWidget(this);
//     QVBoxLayout *layout = new QVBoxLayout(centralWidget);

//     // Create video widget
//     videoWidget = new QVideoWidget(this);
//     videoWidget->setFixedSize(800, 800);
//     layout->addWidget(videoWidget);

//     // Create media player
//     player = new QMediaPlayer(this);
//     player->setVideoOutput(videoWidget);

//     // Set RTSP URL
//     qDebug() << "Playing RTSP Stream: " << rtspUrl;
//     player->setMedia(QUrl(rtspUrl));

//     // Lower buffer latency
//     player->setPlaybackRate(1.0); // Normal speed
//     player->play();

//     // Set the central widget
//     setCentralWidget(centralWidget);

//     // Handle RTSP stream errors (Qt 5 uses `error()`)
//     connect(player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), this, [=](QMediaPlayer::Error error) {
//         qDebug() << "RTSP Stream Error: " << error << player->errorString();
//     });

//     // Handle buffering status
//     connect(player, &QMediaPlayer::bufferStatusChanged, this, [=](int percent) {
//         qDebug() << "Buffering: " << percent << "%";
//     });

//     // Handle media status updates
//     connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
//         if (status == QMediaPlayer::InvalidMedia) {
//             qDebug() << "Error: Invalid RTSP stream.";
//         } else if (status == QMediaPlayer::LoadingMedia) {
//             qDebug() << "Loading RTSP stream...";
//         } else if (status == QMediaPlayer::BufferedMedia) {
//             qDebug() << "RTSP Stream Buffered!";
//         }
//     });

//     // Handle playback state changes (for Qt 5 compatibility)
//     connect(player, &QMediaPlayer::stateChanged, this, [=](QMediaPlayer::State state) {
//         if (state == QMediaPlayer::PlayingState) {
//             qDebug() << "Streaming Live!";
//         }
//     });
// }

// MainWindow::~MainWindow() {
//     player->stop();
// }



#include "mainwindow.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QKeyEvent>

MainWindow::MainWindow(const QString &rtspUrl, const QString &windowTitle, int latency, bool sync, int protocol, QWidget *parent)
    : QMainWindow(parent) {
    // Set initial window size to 800x800, but allow resizing and the maximize button to work
    this->resize(800, 800); // Use resize instead of setFixedSize for resizable window

    // Set window title
    this->setWindowTitle(windowTitle);

    // Create layout
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    // Create video widget
    videoWidget = new QVideoWidget(this);
    videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // Ensure it resizes with the window
    layout->addWidget(videoWidget);

    // Create media player
    player = new QMediaPlayer(this);
    player->setVideoOutput(videoWidget);

    // Set RTSP URL
    qDebug() << "Playing RTSP Stream: " << rtspUrl;
    player->setMedia(QUrl(rtspUrl));

    // Lower buffer latency
    player->setPlaybackRate(1.0); // Normal speed
    player->play();

    // Set the central widget
    setCentralWidget(centralWidget);

    // Handle RTSP stream errors
    connect(player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), this, [=](QMediaPlayer::Error error) {
        qDebug() << "RTSP Stream Error: " << error << player->errorString();
    });

    // Handle buffering status
    connect(player, &QMediaPlayer::bufferStatusChanged, this, [=](int percent) {
        qDebug() << "Buffering: " << percent << "%";
    });

    // Handle media status updates
    connect(player, &QMediaPlayer::mediaStatusChanged, this, [=](QMediaPlayer::MediaStatus status) {
        if (status == QMediaPlayer::InvalidMedia) {
            qDebug() << "Error: Invalid RTSP stream.";
        } else if (status == QMediaPlayer::LoadingMedia) {
            qDebug() << "Loading RTSP stream...";
        } else if (status == QMediaPlayer::BufferedMedia) {
            qDebug() << "RTSP Stream Buffered!";
        }
    });

    // Handle playback state changes
    connect(player, &QMediaPlayer::stateChanged, this, [=](QMediaPlayer::State state) {
        if (state == QMediaPlayer::PlayingState) {
            qDebug() << "Streaming Live!";
        }
    });
}

MainWindow::~MainWindow() {
    player->stop();
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    // Make sure the video widget resizes with the window
    videoWidget->resize(event->size());
    QMainWindow::resizeEvent(event); // Call the base class resizeEvent
}

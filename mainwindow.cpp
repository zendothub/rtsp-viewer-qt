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



//full screen support

// #include "mainwindow.h"
// #include <QVBoxLayout>
// #include <QDebug>
// #include <QMediaPlayer>
// #include <QVideoWidget>
// #include <QKeyEvent>

// MainWindow::MainWindow(const QString &rtspUrl, const QString &windowTitle, int latency, bool sync, int protocol, QWidget *parent)
//     : QMainWindow(parent) {
//     // Set initial window size to 800x800, but allow resizing and the maximize button to work
//     this->resize(800, 800); // Use resize instead of setFixedSize for resizable window

//     // Set window title
//     this->setWindowTitle(windowTitle);

//     // Create layout
//     QWidget *centralWidget = new QWidget(this);
//     QVBoxLayout *layout = new QVBoxLayout(centralWidget);

//     // Create video widget
//     videoWidget = new QVideoWidget(this);
//     videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // Ensure it resizes with the window
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

//     // Handle RTSP stream errors
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

//     // Handle playback state changes
//     connect(player, &QMediaPlayer::stateChanged, this, [=](QMediaPlayer::State state) {
//         if (state == QMediaPlayer::PlayingState) {
//             qDebug() << "Streaming Live!";
//         }
//     });
// }

// MainWindow::~MainWindow() {
//     player->stop();
// }

// void MainWindow::resizeEvent(QResizeEvent *event) {
//     // Make sure the video widget resizes with the window
//     videoWidget->resize(event->size());
//     QMainWindow::resizeEvent(event); // Call the base class resizeEvent
// }



//below code for both rtsp_url and web_url

#include "mainwindow.h"
#include <QVBoxLayout>
#include <QDebug>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QWebEngineView>
#include <QResizeEvent>
#include <QPushButton>
#include <QWebEngineProfile>
#include <QWebEngineCookieStore>
#include <QNetworkCookie>
// MainWindow::MainWindow(const QString &rtspUrl, const QString &webUrl, const QString &droneName, QWidget *parent)
//     : QMainWindow(parent), player(new QMediaPlayer(this)), videoWidget(new QVideoWidget(this)), 
//       webView(new QWebEngineView(this)) {
    
//     // Set initial window size to 900x900
//     this->resize(900, 900);
//     this->setWindowTitle(droneName); // Set the window title to the drone name

//     // Create central widget and layout
//     centralWidget = new QWidget(this);
//     layout = new QHBoxLayout(centralWidget);

//     // Create video widget (for RTSP stream)
//     videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding); // Ensure it resizes
//     layout->addWidget(videoWidget, 1);  // Right side for RTSP stream

//     // Create WebEngineView widget (for web URL)
//     webView->setUrl(QUrl(webUrl));
//     layout->addWidget(webView, 1);  // Left side for web view

//     // Set the central widget
//     setCentralWidget(centralWidget);

//     // Create media player and set RTSP stream
//     player->setVideoOutput(videoWidget);
//     player->setMedia(QUrl(rtspUrl));

//     // Handle RTSP stream errors
//     connect(player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), this, &MainWindow::handleRTSPError);

 

//     // Handle playback state changes
//     connect(player, &QMediaPlayer::stateChanged, this, &MainWindow::handleRTSPStateChange);

//     // Start playing the stream
//     player->play();

    
// }


MainWindow::MainWindow(const QString &rtspUrl, const QString &webUrl, const QString &droneName, const QString &cookie, QWidget *parent)
    : QMainWindow(parent), player(new QMediaPlayer(this)), videoWidget(new QVideoWidget(this)), 
      webView(new QWebEngineView(this)), cookie(cookie) {
    
    // Set initial window size
    this->resize(900, 900);
    this->setWindowTitle(droneName);

    // Create central widget and layout
    centralWidget = new QWidget(this);
    layout = new QHBoxLayout(centralWidget);

    // Video Widget
    videoWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    layout->addWidget(videoWidget, 1);

    // Web View
    QWebEngineProfile *profile = QWebEngineProfile::defaultProfile();
    QWebEngineCookieStore *cookieStore = profile->cookieStore();

    // Set cookie
    QNetworkCookie qCookie;
    qCookie.setName("connect.sid");       // Change this to match the cookie name
    qCookie.setValue(cookie.toUtf8());
    qCookie.setDomain(QUrl(webUrl).host());
    qCookie.setPath("/");
    qCookie.setSecure(true);
    qCookie.setHttpOnly(true);

    cookieStore->setCookie(qCookie, QUrl(webUrl));

    webView->setUrl(QUrl(webUrl));
    layout->addWidget(webView, 1);

    setCentralWidget(centralWidget);

    // Set up the media player
    player->setVideoOutput(videoWidget);
    player->setMedia(QUrl(rtspUrl));

    connect(player, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), this, &MainWindow::handleRTSPError);
    connect(player, &QMediaPlayer::stateChanged, this, &MainWindow::handleRTSPStateChange);

    player->play();
}


MainWindow::~MainWindow() {
    player->stop();
}

void MainWindow::resizeEvent(QResizeEvent *event) {
    // Make sure the video widget and web view resize properly
    videoWidget->resize(event->size().width() / 2, event->size().height());
    webView->resize(event->size().width() / 2, event->size().height());

    QMainWindow::resizeEvent(event); // Call the base class resizeEvent
}

void MainWindow::handleRTSPError() {
    qDebug() << "RTSP Stream Error: " << player->errorString();
    // reloadButton->setVisible(true);  // Show the reload button if there's an error
}



void MainWindow::handleRTSPStateChange(QMediaPlayer::State state) {
    if (state == QMediaPlayer::StoppedState) {
        // reloadButton->setVisible(true);  // Show reload button if stream stops
    }
}

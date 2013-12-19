#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QTextStream>

class QNetworkAccessManager;

class Updater : public QObject
{
    Q_OBJECT
    
public:
    Updater();
    void run();
    void checkNewestVersion();
    bool download();
    bool overlap();
    void printUsage();
    void timeout();
    ~Updater();

public slots:
    void onCheck();
    
private:
    enum State {
        READY = 0,
        CHK_VERSION,
        DOWNLOAD_NEW,
        OVERLAP,
        CHK_ERROR = -100,
        DOWNLOAD_ERROR,
        OVERLAP_ERROR,
        UNKNOWN_ERROR
    };

    QNetworkAccessManager *manager_;
    State state_;
    QTimer *timer_;
    QTextStream output;
};

#endif // MAINWINDOW_H

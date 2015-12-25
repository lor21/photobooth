#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDir>

MainWindow::MainWindow(QString path, QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
  , m_watch(QStringList(path), this)
{
    ui->setupUi(this);
    connect(&m_watch, &QFileSystemWatcher::directoryChanged, this, &MainWindow::directoryChanged);
    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    displayLatestFileInPath(path);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::directoryChanged(QString path)
{
    qDebug() << "Directory Changed" << path;
    displayLatestFileInPath(path);
}

void MainWindow::displayLatestFileInPath(QString path)
{
    QDir d(path);
    QStringList files = d.entryList(QStringList("*.jpg"), QDir::Files, QDir::Time);

    if(files.size())
    {
        qDebug() << "Will display" << QString("%1/%2").arg(path).arg(files.first());
        ui->lblDisplay->setPixmap(QPixmap(QString("%1/%2").arg(path).arg(files.first())));
    }

    if(files.size() > 3)
    {
        ui->lblLast1->setPixmap(QPixmap(QString("%1/%2").arg(path).arg(files[1])));
        ui->lblLast2->setPixmap(QPixmap(QString("%1/%2").arg(path).arg(files[2])));
        ui->lblLast3->setPixmap(QPixmap(QString("%1/%2").arg(path).arg(files[3])));
    }
}

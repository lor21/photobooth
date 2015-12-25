#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QString path, QWidget *parent = 0);
    ~MainWindow();

public slots:
    void directoryChanged(QString path);
    void displayLatestFileInPath(QString path);

private:
    Ui::MainWindow *ui;
    QFileSystemWatcher m_watch;
};

#endif // MAINWINDOW_H

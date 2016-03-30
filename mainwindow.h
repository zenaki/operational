#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QMessageBox>
#include <QtWebKitWidgets/QtWebKitWidgets>
#include <QSettings>

#include <add_marker.h>

#define CODEC "UTF-8"

namespace Ui {
class MainWindow;
}

class add_marker;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void setMap();
    void on_actionAdd_Marker_triggered();
    void writePluginConfg();

private:
    Ui::MainWindow *ui;

    add_marker *AddMarker;
};

#endif // MAINWINDOW_H

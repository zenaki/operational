#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->writePluginConfg();
    this->ui->webView->settings()->setAttribute(QWebSettings::JavascriptEnabled, true);
    this->setMap();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMap()
{
    QString fileName = ":/new/Google_Maps_API/gmap.html";
    if(!QFile(fileName).exists()) {
        QMessageBox::critical(this, tr("Attention !!"),
        "File not found: " + fileName);
        return;
    } else {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::information(this, tr("Sorry .."),
            "Cannot Set Map ..\n" + file.errorString());
            return;
        }
        QTextStream out(&file);
        QString output = out.readAll();

        // display contents
        this->ui->webView->setHtml(output);
    }
}

void MainWindow::on_actionAdd_Marker_triggered()
{
    AddMarker = new add_marker(this);
    AddMarker->setWindowTitle("Add Marker");
    AddMarker->setModal(true);
    AddMarker->exec();
    if(AddMarker->accept == 0) return;

    QString Latitude = AddMarker->Latitude;
    QString Longitude = AddMarker->Longitude;
    QString BoardName = AddMarker->BoardName;
    QString SerialNumber = AddMarker->SerialNumber;

    int pin_length = this->ui->webView->page()->mainFrame()->evaluateJavaScript("pin.length").toInt();
    int env_length = this->ui->webView->page()->mainFrame()->evaluateJavaScript("env.length").toInt();

    QString index;
    index = QString::number(pin_length);
    this->ui->webView->page()->mainFrame()->evaluateJavaScript(QString("pin[%1] = %2;").arg(index).arg(Latitude));
    pin_length++;
    index = QString::number(pin_length);
    this->ui->webView->page()->mainFrame()->evaluateJavaScript(QString("pin[%1] = %2;").arg(index).arg(Longitude));
    index = QString::number(env_length);
    this->ui->webView->page()->mainFrame()->evaluateJavaScript(QString("env[%1] = '%2';").arg(index).arg(BoardName));
    env_length++;
    index = QString::number(env_length);
    this->ui->webView->page()->mainFrame()->evaluateJavaScript(QString("env[%1] = '%2';").arg(index).arg(SerialNumber));

    this->ui->webView->page()->mainFrame()->evaluateJavaScript("initMarker();");
}

void MainWindow::writePluginConfg()
{
    QString temp;
    QSettings confg(QDir::currentPath() + "/plugin.cfg", QSettings::IniFormat);
    confg.setIniCodec(CODEC);

    confg.beginGroup("PLUGIN");
        temp = "Operational";
        confg.setValue("PLUGIN_NAME", temp);
        temp = "operational";
        confg.setValue("PLUGIN_EXEC", temp);
    confg.endGroup();
}

#include "add_marker.h"
#include "ui_add_marker.h"

add_marker::add_marker(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add_marker)
{
    ui->setupUi(this);
    accept = 0;
}

add_marker::~add_marker()
{
    accept = 0;
    delete ui;
}

void add_marker::on_pbAddMarker_clicked()
{
    Latitude = this->ui->Latitude->text();
    Longitude = this->ui->Longitude->text();
    BoardName = this->ui->BoardName->text();
    SerialNumber = this->ui->SerialNumber->text();

    if (!Latitude.isEmpty() && !Longitude.isEmpty()) {
        if (BoardName.isEmpty()) BoardName = "N/A";
        if (SerialNumber.isEmpty()) SerialNumber = "N/A";
        accept = 1;
        close();
    } else {
        QMessageBox::information(this, tr("Sorry .."),
        "Latitude and Longitude cannot be null ..");
    }
}

void add_marker::on_pbCancel_clicked()
{
    accept = 0;
    close();
}

#ifndef ADD_MARKER_H
#define ADD_MARKER_H

#include <QDialog>
#include <QMessageBox>

namespace Ui {
class add_marker;
}

class add_marker : public QDialog
{
    Q_OBJECT

public:
    explicit add_marker(QWidget *parent = 0);
    ~add_marker();

    QString Latitude;
    QString Longitude;
    QString BoardName;
    QString SerialNumber;

    int accept;
private slots:
    void on_pbAddMarker_clicked();

    void on_pbCancel_clicked();

private:
    Ui::add_marker *ui;
};

#endif // ADD_MARKER_H

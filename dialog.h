#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTimer>

extern int dht11_dat[5];
extern int dht11temp, fd, adcg, adcr, smoke, doors, pir;
extern int lgh, lgt; //last good humidity and temperature

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
    void update();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H

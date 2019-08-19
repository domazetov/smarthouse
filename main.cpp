#include "dialog.h"
#include <QApplication>
#include <wiringPiI2C.h>
#include <wiringPi.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    wiringPiSetup();

    return a.exec();
}

#include "dialog.h"
#include "ui_dialog.h"

#include <QTimer>
#include <QTime>
#include <QDate>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QScrollBar>

#include <wiringPiI2C.h>
#include <wiringPi.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define LED         21
#define DHTPIN		7
#define PIRPIN		25
#define ADCADDRESS	0x48
#define SERVOLEFT	4
#define SERVORIGHT	5
#define GASHIGHVAL  190
#define RAINVAL     80

int dht11_dat[5] = {0,0,0,0,0};
int dht11temp, fd, adcg, adcr, smoke, doors=0, pir=0, ledstate=0;
int logstartup=0, motionsensor=1, rainsensor=0;
int lgh, lgt;

void closedoors(void);
void opendoors(void);

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(1000);

    if (wiringPiSetup () == -1) exit (1);
    fd = wiringPiI2CSetup(ADCADDRESS);

    pinMode(PIRPIN, INPUT);
    pinMode(SERVOLEFT, OUTPUT);
    pinMode(SERVORIGHT, OUTPUT);
    pinMode(LED, OUTPUT);
    this->setWindowTitle("Smart House System Monitor");
    closedoors();
    digitalWrite(LED, LOW);
    ui->checkBox->setChecked(true);
}

Dialog::~Dialog()
{
    logger("System shutdown...");
    delete ui;
}

int bmptemp(void)
{
    FILE *ft;
    char value[10];
    ft=fopen("/sys/bus/iio/devices/iio:device0/in_temp_input","r");
    if(ft==NULL) return 0;
    int i=0;
    for(i=0;i<10;i++)
    fscanf(ft,"%s", value);
    fclose(ft);
    int temp=atoi(value)/1000;
    return temp;
}

int raspberrytemp(void)
{
    FILE *ft;
    char value[10];
    ft=fopen("/sys/class/thermal/thermal_zone0/temp","r");
    if(ft==NULL) return 0;
    int i=0;
    for(i=0;i<10;i++)
    fscanf(ft,"%s", value);
    fclose(ft);
    int temp = atoi(value)/1000;
    return temp;
}

double bmppres(void)
{
    FILE *ft;
    char value[100];
    ft=fopen("/sys/bus/iio/devices/iio:device0/in_pressure_input","r");
    if(ft==NULL) return 0;
    int i=0;
    for(i=0;i<20;i++)
    fscanf(ft,"%s", value);
    fclose(ft);
    double pres=atof(value)*10;
    return pres;
};

int dht11(void)
{
    int laststate = HIGH;
    int counter = 0;
    int j = 0, i;

    dht11_dat[0] = dht11_dat[1] = dht11_dat[2] = dht11_dat[3] = dht11_dat[4] = 0;

    pinMode(DHTPIN, OUTPUT);
    digitalWrite(DHTPIN, LOW);
    delay(18);
    digitalWrite(DHTPIN, HIGH);
    delayMicroseconds(40);
    pinMode(DHTPIN, INPUT);

    for ( i=0; i< 85; i++)
    {
        counter = 0;
        while (digitalRead(DHTPIN) == laststate)
        {
            counter++;
            delayMicroseconds(1);
            if (counter == 255)
            {
                break;
            }
        }
        laststate = digitalRead(DHTPIN);

        if (counter == 255) break;

        if ((i >= 4) && (i%2 == 0))
        {
            dht11_dat[j/8] <<= 1;
            if (counter > 25)
            {
                dht11_dat[j/8] |= 1;
            }
            j++;
        }
    }

    if ((j >= 40) && (dht11_dat[4] == ((dht11_dat[0] + dht11_dat[1] + dht11_dat[2] + dht11_dat[3]) & 0xFF)) )
    {
        if(dht11_dat[2]>=0 && dht11_dat[2]<=50)
        {
            lgh = dht11_dat[0];
            lgt = dht11_dat[2];
        }
        dht11temp=lgt;
        return dht11_dat[0];
    }
    else
    {
        dht11temp=lgt;
        return lgh;
    }
}

int adcgas(void)
{
    wiringPiI2CReadReg8(fd, ADCADDRESS + 2) ; //dummy
    adcg = wiringPiI2CReadReg8(fd, ADCADDRESS + 2) ;
    return adcg;
}

int adcrain(void)
{
    wiringPiI2CReadReg8(fd, ADCADDRESS + 3) ; //dummy
    adcr = wiringPiI2CReadReg8(fd, ADCADDRESS + 3) ;
    adcr = abs(adcr-255);
    return adcr;
}

void Dialog::logger(char logdata[])
{
    QFile file0("/home/pi/SHSM/log.txt");
    if(!file0.open(QIODevice::Append | QIODevice::Text))
    {
        QMessageBox::information(this, "error", file0.errorString());
    }
    QString logtime = QTime::currentTime().toString("hh:mm:ss");
    QString logdate = QDate::currentDate().toString("dd.MM.yyyy");

    QTextStream out(&file0);
    out << logdate << " @ " << logtime << " : " << logdata << "\n";
    file0.close();

    QFile file("/home/pi/SHSM/log.txt");
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "error", file.errorString());
    }
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
    file.close();

    QScrollBar *sb = ui->textBrowser->verticalScrollBar();
    sb->setValue(sb->maximum());
}

void Dialog::pircontrol()
{
    if(!(ui->checkBox->isChecked()))
    {
        motionsensor = 0;
        if(digitalRead(PIRPIN)==1)
        {
            ui->label_7->setText("MOTION DETECTED");
            if(doors==0 && pir==0)
            {
                ui->label_10->setText("OPENED");
                logger("Motion detected, doors are opened");
                opendoors();
                doors=1;
            }
            pir=1;
        }
        else
        {
            ui->label_7->setText("NO MOTION");
            if(doors==1 && pir==1)
            {
                ui->label_10->setText("CLOSED");
                logger("No more motion, doors are closed");
                closedoors();
                doors=0;
            }
            pir=0;
        }
    }
    else
    {
        ui->label_7->setText("SENSOR DISABLED");
        if(motionsensor == 0)
        {
            logger("Motion sensor disabled");
            motionsensor = 1;
        }
    }
}

void Dialog::gascontrol()
{
    if((adcg>GASHIGHVAL) && smoke!=1)
    {
        if(doors==0)
        {
            ui->label_10->setText("OPENED");
            opendoors();
            doors=3;
        }
        logger("Combustible gas or smoke detected");
        smoke=1;
    }
    if(adcg>GASHIGHVAL){
        ledstate=~ledstate;
        digitalWrite(LED, ledstate);
        ui->label_17->setText("EMERGENCY");
    }

    if(adcg<GASHIGHVAL && smoke==1)
    {
        digitalWrite(LED, LOW);
        ledstate=0;
        ui->label_17->setText("OFF");
        smoke=0;
        doors=1;
    }
}

void Dialog::raincontrol()
{
    if(adcr > RAINVAL)
    {
        if(rainsensor == 0)
        {
        logger("It's probably raining outside");
        rainsensor = 1;
        }
    }
    else
    {
        rainsensor = 0;
    }
}

void Dialog::styler()
{
    QString st = QString (
                 "QProgressBar::chunk {"
                 "background-color: #eb3443;"
                 "}");

    st.append("QProgressBar {"
              "border: 1px solid #a6a6a6;"
              "text-align: center;"
              "font: italic 12pt Sans Serif;"
              "background: #d4d4d4;"
              "}");

    QString st2 = QString (
                 "QProgressBar::chunk {"
                 "background-color: #8a3af2;"
                 "}");

    st2.append("QProgressBar {"
              "border: 1px solid #a6a6a6;"
              "text-align: center;"
              "font: italic 12pt Sans Serif;"
              "background: #d4d4d4;"
              "}");

    QString st3 = QString (
                 "QProgressBar::chunk {"
                 "background-color: #0f9fff;"
                 "}");

    st3.append("QProgressBar {"
              "border: 1px solid #a6a6a6;"
              "text-align: center;"
              "font: italic 12pt Sans Serif;"
              "background: #d4d4d4;"
              "}");

    QString st4 = QString (
                 "QProgressBar::chunk {"
                 "background-color: #35f02b;"
                 "}");

    st4.append("QProgressBar {"
              "border: 1px solid #a6a6a6;"
              "text-align: center;"
              "font: italic 12pt Sans Serif;"
              "background: #d4d4d4;"
              "}");

    QString st5 = QString (
                 "QProgressBar::chunk {"
                 "background-color: #347deb;"
                 "}");

    st5.append("QProgressBar {"
              "border: 1px solid #a6a6a6;"
              "text-align: center;"
              "font: italic 12pt Sans Serif;"
              "background: #d4d4d4;"
              "}");

    ui->progressBar->setStyleSheet(st);
    ui->progressBar_2->setStyleSheet(st2);
    ui->progressBar_3->setStyleSheet(st2);
    ui->progressBar_4->setStyleSheet(st3);
    ui->progressBar_5->setStyleSheet(st3);
    ui->progressBar_6->setStyleSheet(st4);
    ui->progressBar_7->setStyleSheet(st5);

}

void Dialog::update()
{ 
    if(logstartup==0)
    {
        logger("System startup...");
        logstartup=1;
    }

    ui->progressBar->setValue(raspberrytemp());
    ui->progressBar_2->setValue(bmptemp());
    ui->progressBar_3->setValue(bmppres());
    ui->progressBar_4->setValue(dht11());
    ui->progressBar_5->setValue(dht11temp);
    ui->progressBar_6->setValue(adcgas());
    ui->progressBar_7->setValue(adcrain());

    pircontrol();
    gascontrol();
    raincontrol();
    styler();
    ui->label_12->setText(QTime::currentTime().toString("hh:mm:ss"));
    ui->label_14->setText(QDate::currentDate().toString("dd.MM.yyyy"));
}

void opendoors(void)
{
    digitalWrite (SERVOLEFT, HIGH) ; delay (2) ;
    digitalWrite (SERVOLEFT,  LOW) ; delay (18) ;
    digitalWrite (SERVORIGHT, HIGH) ; delay (1) ;
    digitalWrite (SERVORIGHT,  LOW) ; delay (19) ;
    digitalWrite (SERVOLEFT, HIGH) ; delay (2) ;
    digitalWrite (SERVOLEFT,  LOW) ; delay (18) ;
    digitalWrite (SERVORIGHT, HIGH) ; delay (1) ;
    digitalWrite (SERVORIGHT,  LOW) ; delay (19) ;
    digitalWrite (SERVOLEFT, HIGH) ; delay (2) ;
    digitalWrite (SERVOLEFT,  LOW) ; delay (18) ;
    digitalWrite (SERVORIGHT, HIGH) ; delay (1) ;
    digitalWrite (SERVORIGHT,  LOW) ; delay (19) ;
    digitalWrite (SERVOLEFT, HIGH) ; delay (2) ;
    digitalWrite (SERVOLEFT,  LOW) ; delay (18) ;
    digitalWrite (SERVORIGHT, HIGH) ; delay (1) ;
    digitalWrite (SERVORIGHT,  LOW) ; delay (19) ;
}

void closedoors(void)
{
    digitalWrite (SERVOLEFT, HIGH) ; delay (1) ;
    digitalWrite (SERVOLEFT,  LOW) ; delay (19) ;
    digitalWrite (SERVORIGHT, HIGH) ; delay (2) ;
    digitalWrite (SERVORIGHT,  LOW) ; delay (18) ;
    digitalWrite (SERVOLEFT, HIGH) ; delay (1) ;
    digitalWrite (SERVOLEFT,  LOW) ; delay (19) ;
    digitalWrite (SERVORIGHT, HIGH) ; delay (2) ;
    digitalWrite (SERVORIGHT,  LOW) ; delay (18) ;
    digitalWrite (SERVOLEFT, HIGH) ; delay (1) ;
    digitalWrite (SERVOLEFT,  LOW) ; delay (19) ;
    digitalWrite (SERVORIGHT, HIGH) ; delay (2) ;
    digitalWrite (SERVORIGHT,  LOW) ; delay (18) ;
    digitalWrite (SERVOLEFT, HIGH) ; delay (1) ;
    digitalWrite (SERVOLEFT,  LOW) ; delay (19) ;
    digitalWrite (SERVORIGHT, HIGH) ; delay (2) ;
    digitalWrite (SERVORIGHT,  LOW) ; delay (18) ;
}

void Dialog::on_pushButton_clicked()
{
    if(doors==0)
    {
        ui->label_10->setText("OPENED");
        logger("Doors are opened");
        opendoors();
        doors=1;
        ui->checkBox->setChecked(true);
    }
    else
    {
        QMessageBox::warning(this,tr("WARNING"),tr("DOORS ARE ALREADY OPENED!"));
    }
}

void Dialog::on_pushButton_2_clicked()
{
    if(doors==1)
    {
        ui->label_10->setText("CLOSED");
        logger("Doors are closed");
        closedoors();
        doors=0;
    }
    else if(doors==3)
    {
        QMessageBox::warning(this,tr("WARNING"),tr("DOORS CAN'T BE CLOSED NOW!"));
    }
    else
    {
        QMessageBox::warning(this,tr("WARNING"),tr("DOORS ARE ALREADY CLOSED!"));
    }
}

void Dialog::on_pushButton_3_clicked()
{    
    QMessageBox::information(this,tr("ABOUT"),tr("SMART HOUSE SYSTEM MONITOR\nVersion 1.0\nNebojša Domazetov\ngithub.com/domazetov"));
}

void Dialog::on_pushButton_4_clicked()
{
    if(ledstate==0)
    {
        ui->label_17->setText("ON");
        logger("Lights are turned on");
        digitalWrite(LED, HIGH);
        ledstate=1;
    }
    else
    {
        QMessageBox::warning(this,tr("WARNING"),tr("LIGHT IS ALREADY ON!"));
    }
}

void Dialog::on_pushButton_5_clicked()
{
    if(ledstate==1)
    {
        ui->label_17->setText("OFF");
        logger("Lights are turned off");
        digitalWrite(LED, LOW);
        ledstate=0;
    }
    else
    {
        QMessageBox::warning(this,tr("WARNING"),tr("LIGHT IS ALREADY OFF!"));
    }
}

void Dialog::on_pushButton_6_clicked()
{
    QFile file0("/home/pi/SHSM/log.txt");
    if(!file0.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::information(this, "error", file0.errorString());
    }
    QTextStream out(&file0);
    out << "";
    file0.close();

    logger("New log started");
}

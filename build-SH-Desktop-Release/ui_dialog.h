/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QProgressBar *progressBar_6;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QProgressBar *progressBar;
    QFrame *line_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QProgressBar *progressBar_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QProgressBar *progressBar_2;
    QFrame *line_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QProgressBar *progressBar_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QProgressBar *progressBar_5;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QLabel *label_7;
    QCheckBox *checkBox;
    QFrame *line;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QLabel *label_10;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QFrame *line_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(512, 278);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(512, 278));
        Dialog->setMaximumSize(QSize(512, 278));
        layoutWidget = new QWidget(Dialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 11, 494, 257));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setFrameShape(QFrame::Panel);
        label_6->setFrameShadow(QFrame::Raised);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(label_6);

        progressBar_6 = new QProgressBar(layoutWidget);
        progressBar_6->setObjectName(QStringLiteral("progressBar_6"));
        progressBar_6->setStyleSheet(QLatin1String("font: italic 12pt \"Sans Serif\";\n"
"\n"
"background-color: #e6176a;\n"
""));
        progressBar_6->setMinimum(0);
        progressBar_6->setMaximum(300);
        progressBar_6->setValue(0);
        progressBar_6->setTextVisible(true);
        progressBar_6->setInvertedAppearance(false);

        horizontalLayout_6->addWidget(progressBar_6);


        formLayout->setLayout(0, QFormLayout::LabelRole, horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setFrameShape(QFrame::Panel);
        label->setFrameShadow(QFrame::Raised);
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        progressBar = new QProgressBar(layoutWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setStyleSheet(QLatin1String("font: italic 12pt \"Sans Serif\";\n"
"\n"
"background-color: #e6176a;\n"
""));
        progressBar->setValue(0);
        progressBar->setTextVisible(true);
        progressBar->setInvertedAppearance(false);

        horizontalLayout->addWidget(progressBar);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        line_4 = new QFrame(layoutWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(1, QFormLayout::SpanningRole, line_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFrameShape(QFrame::Panel);
        label_3->setFrameShadow(QFrame::Raised);
        label_3->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        progressBar_3 = new QProgressBar(layoutWidget);
        progressBar_3->setObjectName(QStringLiteral("progressBar_3"));
        progressBar_3->setStyleSheet(QLatin1String("font: italic 12pt \"Sans Serif\";\n"
"\n"
"background-color: #e6176a;\n"
""));
        progressBar_3->setMinimum(950);
        progressBar_3->setMaximum(1050);
        progressBar_3->setValue(1000);
        progressBar_3->setTextVisible(true);
        progressBar_3->setInvertedAppearance(false);

        horizontalLayout_3->addWidget(progressBar_3);


        formLayout->setLayout(2, QFormLayout::LabelRole, horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFrameShape(QFrame::Panel);
        label_2->setFrameShadow(QFrame::Raised);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_2);

        progressBar_2 = new QProgressBar(layoutWidget);
        progressBar_2->setObjectName(QStringLiteral("progressBar_2"));
        progressBar_2->setStyleSheet(QLatin1String("font: italic 12pt \"Sans Serif\";\n"
"\n"
"background-color: #e6176a;\n"
""));
        progressBar_2->setValue(0);
        progressBar_2->setTextVisible(true);
        progressBar_2->setInvertedAppearance(false);

        horizontalLayout_2->addWidget(progressBar_2);


        formLayout->setLayout(2, QFormLayout::FieldRole, horizontalLayout_2);

        line_3 = new QFrame(layoutWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(3, QFormLayout::SpanningRole, line_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFrameShape(QFrame::Panel);
        label_4->setFrameShadow(QFrame::Raised);
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_4->addWidget(label_4);

        progressBar_4 = new QProgressBar(layoutWidget);
        progressBar_4->setObjectName(QStringLiteral("progressBar_4"));
        progressBar_4->setStyleSheet(QLatin1String("font: italic 12pt \"Sans Serif\";\n"
"\n"
"background-color: #e6176a;\n"
""));
        progressBar_4->setMinimum(0);
        progressBar_4->setMaximum(100);
        progressBar_4->setValue(0);
        progressBar_4->setTextVisible(true);
        progressBar_4->setInvertedAppearance(false);

        horizontalLayout_4->addWidget(progressBar_4);


        formLayout->setLayout(4, QFormLayout::LabelRole, horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFrameShape(QFrame::Panel);
        label_5->setFrameShadow(QFrame::Raised);
        label_5->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(label_5);

        progressBar_5 = new QProgressBar(layoutWidget);
        progressBar_5->setObjectName(QStringLiteral("progressBar_5"));
        progressBar_5->setStyleSheet(QLatin1String("font: italic 12pt \"Sans Serif\";\n"
"\n"
"background-color: #e6176a;\n"
""));
        progressBar_5->setValue(0);
        progressBar_5->setTextVisible(true);
        progressBar_5->setInvertedAppearance(false);

        horizontalLayout_5->addWidget(progressBar_5);


        formLayout->setLayout(4, QFormLayout::FieldRole, horizontalLayout_5);

        line_2 = new QFrame(layoutWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setMaximumSize(QSize(16777215, 3));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(5, QFormLayout::SpanningRole, line_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setFrameShape(QFrame::Panel);
        label_8->setFrameShadow(QFrame::Raised);
        label_8->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_8);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setFrameShape(QFrame::Panel);
        label_7->setFrameShadow(QFrame::Raised);
        label_7->setAlignment(Qt::AlignCenter);

        horizontalLayout_7->addWidget(label_7);

        checkBox = new QCheckBox(layoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        horizontalLayout_7->addWidget(checkBox);


        formLayout->setLayout(6, QFormLayout::SpanningRole, horizontalLayout_7);

        line = new QFrame(layoutWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(7, QFormLayout::SpanningRole, line);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setFrameShape(QFrame::Panel);
        label_9->setFrameShadow(QFrame::Raised);
        label_9->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_9);

        label_10 = new QLabel(layoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFrameShape(QFrame::Panel);
        label_10->setFrameShadow(QFrame::Raised);
        label_10->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(label_10);

        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_8->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_8->addWidget(pushButton_2);


        formLayout->setLayout(8, QFormLayout::SpanningRole, horizontalLayout_8);

        line_5 = new QFrame(layoutWidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(9, QFormLayout::SpanningRole, line_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_11 = new QLabel(layoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFrameShape(QFrame::Panel);
        label_11->setFrameShadow(QFrame::Raised);
        label_11->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_11);

        label_12 = new QLabel(layoutWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setFrameShape(QFrame::Panel);
        label_12->setFrameShadow(QFrame::Raised);
        label_12->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_12);

        label_13 = new QLabel(layoutWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setFrameShape(QFrame::Panel);
        label_13->setFrameShadow(QFrame::Raised);
        label_13->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_13);

        label_14 = new QLabel(layoutWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setFrameShape(QFrame::Panel);
        label_14->setFrameShadow(QFrame::Raised);
        label_14->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(label_14);

        pushButton_3 = new QPushButton(layoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_9->addWidget(pushButton_3);


        formLayout->setLayout(10, QFormLayout::SpanningRole, horizontalLayout_9);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        label_6->setText(QApplication::translate("Dialog", "GAS SENSOR ADC:", nullptr));
        progressBar_6->setFormat(QApplication::translate("Dialog", "%v", nullptr));
        label->setText(QApplication::translate("Dialog", "RPI CPU TEMP:", nullptr));
        progressBar->setFormat(QApplication::translate("Dialog", "%p\302\260C", nullptr));
        label_3->setText(QApplication::translate("Dialog", "ROOM PRESSURE:", nullptr));
        progressBar_3->setFormat(QApplication::translate("Dialog", "%vhPa", nullptr));
        label_2->setText(QApplication::translate("Dialog", "ROOM TEMP 1:", nullptr));
        progressBar_2->setFormat(QApplication::translate("Dialog", "%p\302\260C", nullptr));
        label_4->setText(QApplication::translate("Dialog", "ROOM HUMIDITY: ", nullptr));
        progressBar_4->setFormat(QApplication::translate("Dialog", "%v%", nullptr));
        label_5->setText(QApplication::translate("Dialog", "ROOM TEMP 2:", nullptr));
        progressBar_5->setFormat(QApplication::translate("Dialog", "%p\302\260C", nullptr));
        label_8->setText(QApplication::translate("Dialog", "MOTION SENSOR:", nullptr));
        label_7->setText(QApplication::translate("Dialog", "NO MOTION", nullptr));
        checkBox->setText(QApplication::translate("Dialog", "DISABLE SENSOR", nullptr));
        label_9->setText(QApplication::translate("Dialog", "DOOR STATUS:", nullptr));
        label_10->setText(QApplication::translate("Dialog", "CLOSED", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "OPEN", nullptr));
        pushButton_2->setText(QApplication::translate("Dialog", "CLOSE", nullptr));
        label_11->setText(QApplication::translate("Dialog", "TIME:", nullptr));
        label_12->setText(QString());
        label_13->setText(QApplication::translate("Dialog", "DATE:", nullptr));
        label_14->setText(QString());
        pushButton_3->setText(QApplication::translate("Dialog", "ABOUT", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H

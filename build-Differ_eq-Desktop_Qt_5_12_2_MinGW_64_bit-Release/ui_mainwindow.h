/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QWidget *tab1;
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLineEdit *X0;
    QLabel *label_2;
    QLineEdit *Y0;
    QLabel *label_3;
    QLineEdit *X;
    QLabel *label_4;
    QLineEdit *N;
    QLabel *label_7;
    QCheckBox *euler;
    QLabel *label_8;
    QCheckBox *checkBox_2;
    QLabel *label_9;
    QCheckBox *checkBox_3;
    QLabel *label_10;
    QCheckBox *exact;
    QGridLayout *gridLayout_2;
    QCustomPlot *plotter;
    QLabel *label_5;
    QCheckBox *Bug;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_4;
    QCustomPlot *widget;
    QSlider *verticalSlider;
    QCustomPlot *widget_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(916, 615);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setToolTipDuration(0);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setDocumentMode(false);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout_2 = new QHBoxLayout(tab);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(22);
        label_6->setFont(font1);
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);

        tabWidget->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        tab1->setCursor(QCursor(Qt::ArrowCursor));
        gridLayout_3 = new QGridLayout(tab1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFormAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(tab1);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        label->setMaximumSize(QSize(50, 50));
        QFont font2;
        font2.setPointSize(16);
        label->setFont(font2);
        label->setTextFormat(Qt::RichText);
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label->setWordWrap(false);
        label->setIndent(20);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        X0 = new QLineEdit(tab1);
        X0->setObjectName(QString::fromUtf8("X0"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(X0->sizePolicy().hasHeightForWidth());
        X0->setSizePolicy(sizePolicy2);
        X0->setMaximumSize(QSize(50, 50));
        QFont font3;
        font3.setKerning(true);
        X0->setFont(font3);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, X0);

        label_2 = new QLabel(tab1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(50, 50));
        label_2->setFont(font2);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2->setIndent(20);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        Y0 = new QLineEdit(tab1);
        Y0->setObjectName(QString::fromUtf8("Y0"));
        sizePolicy2.setHeightForWidth(Y0->sizePolicy().hasHeightForWidth());
        Y0->setSizePolicy(sizePolicy2);
        Y0->setMaximumSize(QSize(50, 50));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, Y0);

        label_3 = new QLabel(tab1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);
        label_3->setMaximumSize(QSize(50, 50));
        label_3->setFont(font2);
        label_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3->setIndent(20);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        X = new QLineEdit(tab1);
        X->setObjectName(QString::fromUtf8("X"));
        sizePolicy2.setHeightForWidth(X->sizePolicy().hasHeightForWidth());
        X->setSizePolicy(sizePolicy2);
        X->setMaximumSize(QSize(50, 50));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, X);

        label_4 = new QLabel(tab1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMaximumSize(QSize(50, 50));
        label_4->setFont(font2);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4->setIndent(20);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_4);

        N = new QLineEdit(tab1);
        N->setObjectName(QString::fromUtf8("N"));
        sizePolicy2.setHeightForWidth(N->sizePolicy().hasHeightForWidth());
        N->setSizePolicy(sizePolicy2);
        N->setMaximumSize(QSize(50, 50));

        formLayout_2->setWidget(3, QFormLayout::FieldRole, N);

        label_7 = new QLabel(tab1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy2.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy2);
        label_7->setMaximumSize(QSize(110, 50));
        label_7->setTextFormat(Qt::RichText);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_7);

        euler = new QCheckBox(tab1);
        euler->setObjectName(QString::fromUtf8("euler"));
        sizePolicy1.setHeightForWidth(euler->sizePolicy().hasHeightForWidth());
        euler->setSizePolicy(sizePolicy1);
        euler->setMaximumSize(QSize(50, 50));
        QFont font4;
        font4.setPointSize(14);
        euler->setFont(font4);
        euler->setMouseTracking(false);
        euler->setIconSize(QSize(14, 19));
        euler->setChecked(false);
        euler->setTristate(false);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, euler);

        label_8 = new QLabel(tab1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy3);
        label_8->setMaximumSize(QSize(110, 50));
        label_8->setTextFormat(Qt::RichText);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_8);

        checkBox_2 = new QCheckBox(tab1);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        QSizePolicy sizePolicy4(QSizePolicy::Maximum, QSizePolicy::Ignored);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(checkBox_2->sizePolicy().hasHeightForWidth());
        checkBox_2->setSizePolicy(sizePolicy4);
        checkBox_2->setMaximumSize(QSize(50, 50));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, checkBox_2);

        label_9 = new QLabel(tab1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy3.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy3);
        label_9->setMaximumSize(QSize(110, 50));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_9);

        checkBox_3 = new QCheckBox(tab1);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        sizePolicy4.setHeightForWidth(checkBox_3->sizePolicy().hasHeightForWidth());
        checkBox_3->setSizePolicy(sizePolicy4);
        checkBox_3->setMaximumSize(QSize(50, 50));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, checkBox_3);

        label_10 = new QLabel(tab1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy3.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy3);
        label_10->setMaximumSize(QSize(110, 50));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_10);

        exact = new QCheckBox(tab1);
        exact->setObjectName(QString::fromUtf8("exact"));
        sizePolicy4.setHeightForWidth(exact->sizePolicy().hasHeightForWidth());
        exact->setSizePolicy(sizePolicy4);
        exact->setMaximumSize(QSize(50, 50));

        formLayout_2->setWidget(7, QFormLayout::FieldRole, exact);


        gridLayout_3->addLayout(formLayout_2, 1, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        plotter = new QCustomPlot(tab1);
        plotter->setObjectName(QString::fromUtf8("plotter"));
        plotter->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(plotter->sizePolicy().hasHeightForWidth());
        plotter->setSizePolicy(sizePolicy5);
        plotter->setCursor(QCursor(Qt::CrossCursor));

        gridLayout_2->addWidget(plotter, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 0, 1, 1);

        label_5 = new QLabel(tab1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setTextFormat(Qt::RichText);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_5, 0, 0, 1, 1);

        Bug = new QCheckBox(tab1);
        Bug->setObjectName(QString::fromUtf8("Bug"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("MV Boli"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        Bug->setFont(font5);

        gridLayout_3->addWidget(Bug, 0, 1, 1, 1);

        tabWidget->addTab(tab1, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        horizontalLayout_3 = new QHBoxLayout(tab_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_11 = new QLabel(tab_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setMinimumSize(QSize(50, 50));
        label_11->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(label_11);

        pushButton_3 = new QPushButton(tab_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setMaximumSize(QSize(20, 20));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        widget = new QCustomPlot(tab_3);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy5.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(widget);

        verticalSlider = new QSlider(tab_3);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_4->addWidget(verticalSlider);

        widget_2 = new QCustomPlot(tab_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy5.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy5);

        horizontalLayout_4->addWidget(widget_2);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_6->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(X0, Y0);
        QWidget::setTabOrder(Y0, X);
        QWidget::setTabOrder(X, N);
        QWidget::setTabOrder(N, euler);
        QWidget::setTabOrder(euler, checkBox_2);
        QWidget::setTabOrder(checkBox_2, checkBox_3);
        QWidget::setTabOrder(checkBox_3, exact);
        QWidget::setTabOrder(exact, Bug);
        QWidget::setTabOrder(Bug, tabWidget);
        QWidget::setTabOrder(tabWidget, pushButton_3);
        QWidget::setTabOrder(pushButton_3, verticalSlider);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Assignment by Vitaliy Korbashov ", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p>This Program implements the solution for the Variant 10<br/>To view it just proceed to the next tabs</p><p><br/></p><p><br/></p><p align=\"center\">Made by</p><p align=\"center\">Vitaliy Korbashov,BS18-04</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Descrpition", nullptr));
#ifndef QT_NO_TOOLTIP
        tab1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "<html><head/><body><p>	X<span style=\" vertical-align:sub;\">0</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        X0->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Y<span style=\" vertical-align:sub;\">0</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        Y0->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "X", nullptr));
#ifndef QT_NO_TOOLTIP
        X->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_4->setText(QApplication::translate("MainWindow", "N", nullptr));
#ifndef QT_NO_TOOLTIP
        N->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_7->setText(QApplication::translate("MainWindow", "<html><head/><body>\n"
"\n"
"<p style=\"line-height:0.2\">Euler</p>\n"
"<p>(orange)</p>\n"
"</body></html>", nullptr));
        euler->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p style=\"line-height:0.2\">Imp. Euler </p><p>(Red)</p></body></html>", nullptr));
        checkBox_2->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p style=\"line-height:0.2\">Runge-Kutta </p><p>(Green)</p></body></html>", nullptr));
        checkBox_3->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p style=\"line-height:0.2\">Main graph</p><p>(Black)</p></body></html>", nullptr));
        exact->setText(QString());
        label_5->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Differential equation: y</span><span style=\" font-size:12pt; vertical-align:super;\">'</span><span style=\" font-size:12pt;\">= -y</span><span style=\" font-size:12pt; vertical-align:super;\">2</span><span style=\" font-size:12pt;\">/3 -2/(3x</span><span style=\" font-size:12pt; vertical-align:super;\">2</span><span style=\" font-size:12pt;\">)</span></p></body></html>", nullptr));
        Bug->setText(QApplication::translate("MainWindow", "Buggy Features", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "Main graph", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Error graphs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

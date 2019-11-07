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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
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
    QCheckBox *Bug;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radio_graph;
    QRadioButton *radio_error;
    QSpacerItem *verticalSpacer_5;
    QSpacerItem *verticalSpacer_6;
    QLabel *label_X0;
    QLineEdit *X0;
    QLabel *label_2;
    QLineEdit *Y0;
    QLabel *label_X;
    QLineEdit *X;
    QLabel *label_4;
    QLineEdit *N;
    QSpacerItem *verticalSpacer_3;
    QSpacerItem *verticalSpacer_4;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_7;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *euler;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_4;
    QCheckBox *exact;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QHBoxLayout *horizontalLayout_5;
    QCustomPlot *plotter;
    QWidget *page_2;
    QHBoxLayout *horizontalLayout_6;
    QCustomPlot *eplotter;
    QWidget *tab_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_4;
    QCustomPlot *KEK;
    QSlider *verticalSlider;
    QCustomPlot *widget_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(916, 717);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_6 = new QVBoxLayout(centralwidget);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font1;
        font1.setPointSize(10);
        tabWidget->setFont(font1);
        tabWidget->setToolTipDuration(0);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideMiddle);
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
        QFont font2;
        font2.setPointSize(22);
        font2.setBold(false);
        font2.setWeight(50);
        label_6->setFont(font2);
        label_6->setScaledContents(true);
        label_6->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_6);

        tabWidget->addTab(tab, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        tab1->setCursor(QCursor(Qt::ArrowCursor));
        gridLayout_3 = new QGridLayout(tab1);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout_2->setLabelAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        formLayout_2->setFormAlignment(Qt::AlignHCenter|Qt::AlignTop);
        formLayout_2->setHorizontalSpacing(0);
        formLayout_2->setVerticalSpacing(10);
        Bug = new QCheckBox(tab1);
        Bug->setObjectName(QString::fromUtf8("Bug"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Bug->sizePolicy().hasHeightForWidth());
        Bug->setSizePolicy(sizePolicy1);
        Bug->setMaximumSize(QSize(150, 16777215));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MV Boli"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        Bug->setFont(font3);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, Bug);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        formLayout_2->setItem(0, QFormLayout::FieldRole, horizontalSpacer);

        radio_graph = new QRadioButton(tab1);
        radio_graph->setObjectName(QString::fromUtf8("radio_graph"));
        sizePolicy1.setHeightForWidth(radio_graph->sizePolicy().hasHeightForWidth());
        radio_graph->setSizePolicy(sizePolicy1);
        radio_graph->setMaximumSize(QSize(120, 20));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, radio_graph);

        radio_error = new QRadioButton(tab1);
        radio_error->setObjectName(QString::fromUtf8("radio_error"));
        sizePolicy1.setHeightForWidth(radio_error->sizePolicy().hasHeightForWidth());
        radio_error->setSizePolicy(sizePolicy1);
        radio_error->setMaximumSize(QSize(120, 20));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, radio_error);

        verticalSpacer_5 = new QSpacerItem(10, 80, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout_2->setItem(2, QFormLayout::LabelRole, verticalSpacer_5);

        verticalSpacer_6 = new QSpacerItem(10, 80, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout_2->setItem(2, QFormLayout::FieldRole, verticalSpacer_6);

        label_X0 = new QLabel(tab1);
        label_X0->setObjectName(QString::fromUtf8("label_X0"));
        sizePolicy1.setHeightForWidth(label_X0->sizePolicy().hasHeightForWidth());
        label_X0->setSizePolicy(sizePolicy1);
        label_X0->setMaximumSize(QSize(80, 50));
        QFont font4;
        font4.setPointSize(16);
        font4.setBold(false);
        font4.setWeight(50);
        label_X0->setFont(font4);
        label_X0->setTextFormat(Qt::RichText);
        label_X0->setScaledContents(true);
        label_X0->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_X0->setWordWrap(false);
        label_X0->setIndent(20);

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_X0);

        X0 = new QLineEdit(tab1);
        X0->setObjectName(QString::fromUtf8("X0"));
        sizePolicy1.setHeightForWidth(X0->sizePolicy().hasHeightForWidth());
        X0->setSizePolicy(sizePolicy1);
        X0->setMaximumSize(QSize(65, 50));
        QFont font5;
        font5.setPointSize(10);
        font5.setKerning(true);
        X0->setFont(font5);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, X0);

        label_2 = new QLabel(tab1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy1.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy1);
        label_2->setMaximumSize(QSize(80, 50));
        label_2->setFont(font4);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_2->setIndent(20);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_2);

        Y0 = new QLineEdit(tab1);
        Y0->setObjectName(QString::fromUtf8("Y0"));
        sizePolicy1.setHeightForWidth(Y0->sizePolicy().hasHeightForWidth());
        Y0->setSizePolicy(sizePolicy1);
        Y0->setMaximumSize(QSize(65, 50));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, Y0);

        label_X = new QLabel(tab1);
        label_X->setObjectName(QString::fromUtf8("label_X"));
        sizePolicy1.setHeightForWidth(label_X->sizePolicy().hasHeightForWidth());
        label_X->setSizePolicy(sizePolicy1);
        label_X->setMaximumSize(QSize(80, 50));
        label_X->setFont(font4);
        label_X->setTextFormat(Qt::RichText);
        label_X->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_X->setIndent(22);

        formLayout_2->setWidget(5, QFormLayout::LabelRole, label_X);

        X = new QLineEdit(tab1);
        X->setObjectName(QString::fromUtf8("X"));
        sizePolicy1.setHeightForWidth(X->sizePolicy().hasHeightForWidth());
        X->setSizePolicy(sizePolicy1);
        X->setMaximumSize(QSize(65, 50));
        X->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, X);

        label_4 = new QLabel(tab1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);
        label_4->setMaximumSize(QSize(80, 50));
        label_4->setFont(font4);
        label_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_4->setIndent(22);

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_4);

        N = new QLineEdit(tab1);
        N->setObjectName(QString::fromUtf8("N"));
        sizePolicy1.setHeightForWidth(N->sizePolicy().hasHeightForWidth());
        N->setSizePolicy(sizePolicy1);
        N->setMaximumSize(QSize(65, 50));
        N->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        N->setDragEnabled(false);

        formLayout_2->setWidget(6, QFormLayout::FieldRole, N);

        verticalSpacer_3 = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        formLayout_2->setItem(7, QFormLayout::LabelRole, verticalSpacer_3);

        verticalSpacer_4 = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::MinimumExpanding);

        formLayout_2->setItem(7, QFormLayout::FieldRole, verticalSpacer_4);

        label_7 = new QLabel(tab1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);
        label_7->setMaximumSize(QSize(110, 50));
        label_7->setTextFormat(Qt::RichText);
        label_7->setIndent(0);

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_7);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);

        euler = new QCheckBox(tab1);
        euler->setObjectName(QString::fromUtf8("euler"));
        sizePolicy1.setHeightForWidth(euler->sizePolicy().hasHeightForWidth());
        euler->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(euler);


        formLayout_2->setLayout(8, QFormLayout::FieldRole, horizontalLayout_7);

        label_8 = new QLabel(tab1);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setMaximumSize(QSize(110, 50));
        label_8->setTextFormat(Qt::RichText);
        label_8->setIndent(0);

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_8);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));

        formLayout_2->setLayout(9, QFormLayout::FieldRole, horizontalLayout_8);

        label_9 = new QLabel(tab1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy2.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy2);
        label_9->setMaximumSize(QSize(110, 50));
        label_9->setIndent(0);

        formLayout_2->setWidget(10, QFormLayout::LabelRole, label_9);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        formLayout_2->setLayout(10, QFormLayout::FieldRole, horizontalLayout_9);

        label_10 = new QLabel(tab1);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy2.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy2);
        label_10->setMaximumSize(QSize(110, 50));
        label_10->setIndent(0);

        formLayout_2->setWidget(11, QFormLayout::LabelRole, label_10);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        exact = new QCheckBox(tab1);
        exact->setObjectName(QString::fromUtf8("exact"));
        sizePolicy1.setHeightForWidth(exact->sizePolicy().hasHeightForWidth());
        exact->setSizePolicy(sizePolicy1);

        horizontalLayout_10->addWidget(exact);


        formLayout_2->setLayout(11, QFormLayout::FieldRole, horizontalLayout_10);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Ignored);

        formLayout_2->setItem(12, QFormLayout::LabelRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Ignored);

        formLayout_2->setItem(12, QFormLayout::FieldRole, verticalSpacer_2);


        gridLayout_3->addLayout(formLayout_2, 0, 1, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        stackedWidget = new QStackedWidget(tab1);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy3);
        stackedWidget->setCursor(QCursor(Qt::CrossCursor));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        horizontalLayout_5 = new QHBoxLayout(page);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        plotter = new QCustomPlot(page);
        plotter->setObjectName(QString::fromUtf8("plotter"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(plotter->sizePolicy().hasHeightForWidth());
        plotter->setSizePolicy(sizePolicy4);
        plotter->setMaximumSize(QSize(16777215, 16777215));
        plotter->setCursor(QCursor(Qt::CrossCursor));

        horizontalLayout_5->addWidget(plotter);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        horizontalLayout_6 = new QHBoxLayout(page_2);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        eplotter = new QCustomPlot(page_2);
        eplotter->setObjectName(QString::fromUtf8("eplotter"));

        horizontalLayout_6->addWidget(eplotter);

        stackedWidget->addWidget(page_2);

        gridLayout_2->addWidget(stackedWidget, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);

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


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        KEK = new QCustomPlot(tab_3);
        KEK->setObjectName(QString::fromUtf8("KEK"));
        sizePolicy3.setHeightForWidth(KEK->sizePolicy().hasHeightForWidth());
        KEK->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(KEK);

        verticalSlider = new QSlider(tab_3);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_4->addWidget(verticalSlider);

        widget_2 = new QCustomPlot(tab_3);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy3.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy3);

        horizontalLayout_4->addWidget(widget_2);


        verticalLayout_3->addLayout(horizontalLayout_4);


        horizontalLayout_3->addLayout(verticalLayout_3);

        tabWidget->addTab(tab_3, QString());

        verticalLayout_6->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(X0, Y0);
        QWidget::setTabOrder(Y0, X);
        QWidget::setTabOrder(X, N);
        QWidget::setTabOrder(N, tabWidget);
        QWidget::setTabOrder(tabWidget, verticalSlider);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Assignment by Vitaliy Korbashov ", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\">This Program implements the solution for the Variant 10</p><p align=\"center\">Differential equation: y<span style=\" vertical-align:super;\">'</span>= -y<span style=\" vertical-align:super;\">2</span>/3 -2/(3x<span style=\" vertical-align:super;\">2</span>)</p><p align=\"center\"><br/></p><p align=\"center\"><br/></p><p align=\"center\"><br/></p><p align=\"center\"><br/></p><p align=\"center\">Made by</p><p align=\"center\">Vitaliy Korbashov,BS18-04</p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Descrpition", nullptr));
#ifndef QT_NO_TOOLTIP
        tab1->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        Bug->setText(QApplication::translate("MainWindow", "Interactions", nullptr));
        radio_graph->setText(QApplication::translate("MainWindow", "Graphs", nullptr));
        radio_error->setText(QApplication::translate("MainWindow", "Errors ", nullptr));
        label_X0->setText(QApplication::translate("MainWindow", "<html><head/><body><p>	X<span style=\" vertical-align:sub;\">0</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        X0->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Y<span style=\" vertical-align:sub;\">0</span></p></body></html>", nullptr));
#ifndef QT_NO_TOOLTIP
        Y0->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label_X->setText(QApplication::translate("MainWindow", "X", nullptr));
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
        label_9->setText(QApplication::translate("MainWindow", "<html><head/><body><p style=\"line-height:0.2\">Runge-Kutta </p><p>(Green)</p></body></html>", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "<html><head/><body><p style=\"line-height:0.2\">Main graph</p><p>(Black)</p></body></html>", nullptr));
        exact->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("MainWindow", "Main\\Error graphs", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Total Error", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

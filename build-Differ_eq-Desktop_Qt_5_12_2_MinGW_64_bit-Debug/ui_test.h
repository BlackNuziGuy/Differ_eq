/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_TEST
{
public:

    void setupUi(QDialog *TEST)
    {
        if (TEST->objectName().isEmpty())
            TEST->setObjectName(QString::fromUtf8("TEST"));
        TEST->resize(400, 300);

        retranslateUi(TEST);

        QMetaObject::connectSlotsByName(TEST);
    } // setupUi

    void retranslateUi(QDialog *TEST)
    {
        TEST->setWindowTitle(QApplication::translate("TEST", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TEST: public Ui_TEST {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H

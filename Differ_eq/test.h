#ifndef TEST_H
#define TEST_H

#include <QDialog>

namespace Ui {
class TEST;
}

class TEST : public QDialog
{
    Q_OBJECT

public:
    explicit TEST(QWidget *parent = nullptr);
    ~TEST();

private:
    Ui::TEST *ui;
};

#endif // TEST_H

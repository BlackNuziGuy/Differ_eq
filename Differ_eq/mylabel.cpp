#include "mylabel.h"
#include <string>

MyLabel::MyLabel(QLabel *parent) : QLabel(parent)
{

}

void MyLabel::set_int(int x)
{
    this->setText( QString::number(x) );
}


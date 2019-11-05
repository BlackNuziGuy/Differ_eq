#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel:public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QLabel *parent = nullptr);


signals:

public slots:
    void set_int(int);

};

#endif // MYLABEL_H

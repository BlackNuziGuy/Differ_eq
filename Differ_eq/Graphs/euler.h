#ifndef EULER_H
#define EULER_H
#include <Graph.h>

class Euler : public Graph
{


public:

    Euler(QCustomPlot *);
    QColor color();

    void Calculate(double x0, double y0, double X, int N);
    double func(double x, double c);
    double errorfunc(double xi, double xi_1, double y(double, double), double c);

    void visible(bool x);

};

#endif // EULER_H

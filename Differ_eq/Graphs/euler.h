#ifndef EULER_H
#define EULER_H
#include <Graph.h>

class Euler : public Graph
{


public:

    Euler(QCustomPlot *);
    QColor color();

    void Calculate(double x0, double y0, double X, int N);
    static double func(double , double );
    double errorfunc(double xi, double xi_1, double c);

};

#endif // EULER_H

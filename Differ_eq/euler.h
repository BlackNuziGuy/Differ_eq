#ifndef EULER_H
#define EULER_H
#include <Graph.h>

class Euler
{
public:
    Euler();
    QCustomPlot *graph;
    virtual void AddGraph(QCustomPlot *element);
    virtual void Calculate(double x0, double y0, double X, int N);
    virtual void Visibile(bool x);
    virtual double func(double x, double c);
};

#endif // EULER_H

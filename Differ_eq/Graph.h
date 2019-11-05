#ifndef GRAPH_H
#define GRAPH_H
#include <qcustomplot.h>
#include <math.h>


class Graph
{
public:
    void Calculate(double x0, double y0, double X, int N);
    void Visibile(bool x);
    double func(double x, double c);
};


#endif // GRAPH_H

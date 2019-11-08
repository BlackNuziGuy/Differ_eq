#ifndef EXACT_GRAPH_H
#define EXACT_GRAPH_H
#include <Graph.h>

class Exact : public Graph
{


public:

    Exact(QCustomPlot *);
//    virtual ~Exact();

    QColor color();

    void Calculate(double x0, double y0, double X, int N);
    double func(double x, double c);

    void visible(bool x);

private:
    double errorfunc(double xi, double xi_1, double y(double, double), double c);
};

#endif // EXACT_GRAPH_H

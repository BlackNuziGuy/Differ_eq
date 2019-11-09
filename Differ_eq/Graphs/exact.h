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
    static double func(double x, double c);



private:
//    double errorfunc(double xi, double xi_1, double c);
};

#endif // EXACT_GRAPH_H

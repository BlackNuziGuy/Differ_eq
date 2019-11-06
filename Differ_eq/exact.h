#ifndef EXACT_GRAPH_H
#define EXACT_GRAPH_H
#include <Graph.h>

class Exact : public Graph
{
public:

    Exact(QCustomPlot *);

    void Calculate(double x0, double y0, double X, int N);
    double func(double x, double c);

    void Visibile(bool x);
};

#endif // EXACT_GRAPH_H

#ifndef EXACT_GRAPH_H
#define EXACT_GRAPH_H
#include <Graph.h>

class Exact_Graph : public Graph
{
public:

    Exact_Graph(QCustomPlot *);

    void Calculate(double x0, double y0, double X, int N);
    void Visibile(bool x);
    double func(double x, double c);

};

#endif // EXACT_GRAPH_H

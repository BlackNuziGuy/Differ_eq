#ifndef EXACT_GRAPH_H
#define EXACT_GRAPH_H
#include <Graph.h>

class Exact_Graph : public Graph
{
public:
    QCustomPlot *graph;
    virtual void AddGraph(QCustomPlot *element);
    virtual void Calculate(double x0, double y0, double X, int N);
    virtual void Visibile(bool x);
    virtual double func(double x, double c);
};

#endif // EXACT_GRAPH_H

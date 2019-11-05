#ifndef MAIN_GRAPH_H
#define MAIN_GRAPH_H
#include <qcustomplot.h>
#include "exact_graph.h"
#include "kunkka.h"
#include "imp_euler.h"
#include "euler.h"

class Main_Graph
{
public:
    static QCustomPlot* graph;
    Exact_Graph exact;
    Euler euler;
    Main_Graph();
    void AddGraph(QCustomPlot *element);
    void Zoom(double, double);
};

#endif // MAIN_GRAPH_H

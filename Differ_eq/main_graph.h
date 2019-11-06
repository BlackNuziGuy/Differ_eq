#ifndef MAIN_GRAPH_H
#define MAIN_GRAPH_H
#include <qcustomplot.h>
#include "exact.h"
#include "kunkka.h"
#include "imp_euler.h"
#include "euler.h"



class Main_Graph
{
public:

    QCustomPlot* graph;
    Euler euler;
    Exact exact;



    Main_Graph(QCustomPlot *element);
    void Zoom(double, double, double);
    void Caculate_all(double x0, double y0, double X, int N);
};

#endif // MAIN_GRAPH_H

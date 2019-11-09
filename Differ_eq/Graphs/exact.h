#ifndef EXACT_GRAPH_H
#define EXACT_GRAPH_H
#include <Graph.h>

class Exact : public Graph{

public:
    Exact(QCustomPlot *gr):Graph(gr){
        color = QColor(0,0,0);
        graph->setPen(color);
        graph->setName("Analytical");
    }

    void Calculate(double x0, double y0, double X, int N);

};

#endif // EXACT_GRAPH_H

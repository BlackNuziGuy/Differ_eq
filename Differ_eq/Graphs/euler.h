#ifndef EULER_H
#define EULER_H
#include <Graph.h>

class Euler : public Graph{

public:
    Euler(QCustomPlot *gr) :Graph(gr){
        color = QColor(255,87,51);
        graph->setPen(color);
        graph->setName("Euler");
    }


    void Calculate(double x0, double y0, double X, int N);
    double errorfunc(double xi, double xi_1, double c);
};

#endif // EULER_H

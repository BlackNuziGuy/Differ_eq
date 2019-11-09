#ifndef KUNKKA_H
#define KUNKKA_H
#include "Graph.h"

class Kunkka : public Graph{

public:
    Kunkka(QCustomPlot *gr):Graph(gr){
        color = QColor(0,0,200);
        graph->setPen(color);
        graph->setName("Runge-Kutta");
    }

    void Calculate(double x0, double y0, double X, int N);
    double errorfunc(double xi, double xi_1, double c);
};

#endif // KUNKKA_H

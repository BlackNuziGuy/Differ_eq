#ifndef KUNKKA_H
#define KUNKKA_H
#include "Graph.h"

class Kunkka : public Graph
{
public:
    Kunkka(QCustomPlot * gr);

    QColor color();

    void Calculate(double x0, double y0, double X, int N);
    static double func(double , double );
    double errorfunc(double xi, double xi_1, double c);


};

#endif // KUNKKA_H

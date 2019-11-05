#ifndef EULER_H
#define EULER_H
#include <Graph.h>

class Euler : public Graph
{

public:

    Euler(QCustomPlot * graph);


    void Calculate(double x0, double y0, double X, int N);
    void Visibile(bool x);
    double func(double x, double c);


};

#endif // EULER_H

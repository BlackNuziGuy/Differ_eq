#ifndef GRAPH_H
#define GRAPH_H
#include <qcustomplot.h>
#include <math.h>


class Graph
{

public:
    QCustomPlot *graph;

    virtual void Calculate(double, double, double , int);
    double func(double x, double c);



    double round_nplaces(double value, int to){
        double places = pow(10.0, to);
        return round(value * places) / places;
}
    bool cmpd(double A, double B, double epsilon = 0.001){
        return (fabs(A - B) < epsilon);
    }

    void Visibile(bool x);
};


#endif // GRAPH_H

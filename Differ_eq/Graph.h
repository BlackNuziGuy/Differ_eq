#ifndef GRAPH_H
#define GRAPH_H
#include <qcustomplot.h>
#include <math.h>


class Graph
{


public:

    QCPGraph *graph;

    Graph(QCustomPlot *gr){

        graph = gr->addGraph();
    }

//    virtual ~Graph();

    virtual void Calculate(double, double, double , int) = 0;
    double func(double x, double c);
    virtual double errorfunc(double xi, double xi_1, double y(double, double), double c) = 0;
    virtual void Visibile(bool x) = 0;


    double round_nplaces(double value, int to){
        double places = pow(10.0, to);
        return round(value * places) / places;
}
    bool cmpd(double A, double B, double epsilon = 0.001){
        return (fabs(A - B) < epsilon);
    }

};


#endif // GRAPH_H

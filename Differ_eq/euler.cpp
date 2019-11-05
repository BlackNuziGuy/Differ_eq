#include "euler.h"


//QCustomPlot Euler::*graph;


Euler::Euler()
{

}


void Euler::AddGraph(QCustomPlot *element)
{
    graph = element;
}



// Consider a differential equation
// dy/dx=(x + y + xy)
double Euler::func(double x, double y)
{
    return ( -y*y/3 - 2.0/(3*x*x) );
}


void Euler::Calculate(double x0, double y0, double X, int N){

    double h = (X-x0)/N;

    // Iterating till the point at which we
    // need approximation
    QVector<double> x(N+1), y(N+1);

    int i = 0;
    y[i] = y0;
    x[i] = x0;

    double xe = x0,ye = y0;

    for (i = 1; i<=N; i++) {
        ye  += h * func(xe, ye);
        xe  += h;

        y[i] = ye;
        x[i] = xe;
    }

    graph->addGraph();
//    graph->graph(1)->setAntialiased(false);

    graph->graph(1)->setData(x, y);

    //Hide initially
    graph->graph(1)->setVisible(0);

    graph->graph(1)->setPen(QPen(QColor(255,87,51)));

    graph->replot();

}

void Euler::Visibile(bool x){

    graph->graph(1)->setVisible(x);

    graph->replot();

}


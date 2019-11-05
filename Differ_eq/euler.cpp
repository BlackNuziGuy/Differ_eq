#include "euler.h"


Euler::Euler(QCustomPlot * gr)
{
    Euler::graph = gr;
}



double Euler::func(double x, double y)
{
    return ( -y*y/3 - 2.0/(3*x*x) );
}


void Euler::Calculate(double x0, double y0, double X, int N){

    QVector<double> x(N+1), y(N+1);
    double h = (X-x0)/N;
    double xe = x0,ye = y0;
    int i = 0;

    y[i] = y0;
    x[i] = x0;


    for (i = 1; i<=N; i++) {
        ye  += h * func(xe, ye);
        xe  += h;

        y[i] = ye;
        x[i] = xe;
    }

    graph->graph(1)->setData(x, y);
    graph->graph(1)->setPen(QPen(QColor(255,87,51)));//Yellowish


    graph->replot();
}

void Euler::Visibile(bool x){

    graph->graph(1)->setVisible(x);

    graph->replot();

}


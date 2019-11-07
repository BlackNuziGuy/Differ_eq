#include "euler.h"



Euler::Euler(QCustomPlot * gr) : Graph(gr)
{
    graph->setPen(QPen(color()));
}



double Euler::func(double x, double y)
{
    return ( -y*y/3 - 2.0/(3*x*x) );
}


double Euler::errorfunc(double xi, double xi_1, double y(double, double), double c)
{
    return ( y(xi_1,c) - y(xi,c) - (xi_1 - xi)*func(xi, y(xi,c) ) );
}

QColor Euler::color(){
    return QColor(255,87,51);
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

    graph->setData(x, y);

}

void Euler::visible(bool x){

    graph->setVisible(x);


}


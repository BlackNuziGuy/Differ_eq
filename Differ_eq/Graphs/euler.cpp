#include "Graphs/euler.h"

double Euler::errorfunc(double xi, double xi_1, double c){
    return ( (y_f(xi_1,c) - y_f(xi,c)) - (xi_1 - xi)*derivative(xi, y_f(xi,c) ) );
}

void Euler::Calculate(double x0, double y0, double X, int N){

    QVector<double> x(N+1), y(N+1);
    double h = (X-x0)/N;
    double xe = x0,ye = y0;
    int i = 0;

    y[i] = y0;
    x[i] = x0;

    for (i = 1; i<=N; i++) {
        ye  += h * derivative(xe, ye);
        xe  += h;

        y[i] = ye;
        x[i] = xe;
    }

    graph->setData(x, y);
}

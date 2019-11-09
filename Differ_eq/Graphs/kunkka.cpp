#include "Graphs/kunkka.h"

double Kunkka::errorfunc(double xi, double xi_1, double c){
    double h = xi_1 - xi, y = y_f(xi,c),y1, y2, y3, y4;

    y1 = h * derivative(xi , y);
    y2 = h * derivative(xi + h/2.0, y + y1/2.0);
    y3 = h * derivative(xi + h/2.0, y + y2/2.0);
    y4 = h * derivative(xi + h    , y + y3    );

    y4 = ( y1 + 2*y2+ 2*y3 + y4)/6.0;

    return ( (y_f(xi_1,c) - y) - y4 );
}


void Kunkka::Calculate(double x0, double y0, double X, int N){

    QVector<double> x(N+1), y(N+1);
    double h = (X-x0)/N;
    double y1, y2, y3, y4;

    x[0] = x0; y[0] = y0;

    for(int i=1; i<=N; i++){

        y1 = h * derivative(x[i-1] , y[i-1]);
        y2 = h * derivative(x[i-1] + h/2.0, y[i-1] + y1/2.0);
        y3 = h * derivative(x[i-1] + h/2.0, y[i-1] + y2/2.0);
        y4 = h * derivative(x[i-1] + h    , y[i-1] + y3    );

        x[i]=x[i-1] + h;
        y[i] = y[i-1] + ( y1 + 2*y2+ 2*y3 + y4)/6.0;
    }

    graph->setData(x, y);
}

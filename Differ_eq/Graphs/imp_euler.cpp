#include "Graphs/imp_euler.h"

Imp_Euler::Imp_Euler(QCustomPlot * gr) : Graph(gr){graph->setPen(color());}
QColor Imp_Euler::color(){  return QColor(0,200,51);}


double Imp_Euler::errorfunc(double xi, double xi_1, double c){

    double k1,k2, h = xi_1 - xi, y = y_f(xi,c) ,y1, ya, y2;

    k1= h * derivative(xi, y);    //calculate slope or dy/dx at x0,y0
    y1= y + k1;                    //calculate new y, which is y0+h*dy/dx
    k2= h * derivative(xi, y1); //calculate slope or dy/dx at x0,new y
    ya=(k1+k2)/2.0;        //calculate the average of the slopes at y0 and new y

    return ( (y_f(xi_1,c) - y) - ya);
}

//y_f(xi) - (xi_1 - xi) * derivative(xe, ye)

void Imp_Euler::Calculate(double x0, double y0, double X, int N){

    QVector<double> x(N+1), y(N+1);
    double h = (X-x0)/N;
    double ya, k1,k2, y1,y2;

    for (int i = 0; i<=N; i++) {
        {
            k1= h * derivative(x0, y0);    //calculate slope or dy/dx at x0,y0
            y1=y0+k1;                    //calculate new y, which is y0+h*dy/dx
            k2= h * derivative(x0, y1); //calculate slope or dy/dx at x0,new y
            ya=(k1+k2)/2.0;        //calculate the average of the slopes at y0 and new y
            y2=y0+ya;              //calculate new y, which is y0+h*average(dy/dx)

            y[i] = y0;
            x[i] = x0;

            x0=x0+h;                //calculate new x.
            y0=y2;                //pass this new y as y0 in the next iteration.
        }
    }

    graph->setData(x, y);
}

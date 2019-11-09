#include "Graphs/exact.h"

Exact::Exact(QCustomPlot * gr) : Graph(gr){ graph->setPen(QPen(color()));}
QColor Exact::color(){return (QColor( 0,0,0,255) );}
//double Exact::errorfunc(double xi, double xi_1, double c){return xi + xi_1 + y_fs(0,0) + c;}//USELESS BUT NECESSARY; VERY KOSTIL

void Exact::Calculate(double x0, double y0, double X, int N){

    int i1 = 0,i2 = 0; //To account for Gaps ( there are 2 asymptotes)
    double c = constant(x0,y0); //Const and value to start stepping from

    //Plot a bit more
    double val =  std::max(abs(x0),abs(X)); val *= 2;
    double x_v = -val; X = val;
    N = 99999;//For the best precision
    double h = (X-x_v)/N;
    QVector<double> x(N+1), y(N+1);//N steps + 1 final point


    for(int i = 0; i<=N; i++){

        x[i] = x_v;
        y[i] = y_f(x[i],c);

        //Find assymtote
        if( abs(x[i] - 0) < abs(x[i1] - 0) )
            i1 = i;
        if( abs(x[i] + c*c*c) < abs(x[i2] + c*c*c) )
            i2 = i;

        x_v+=h;

    }

    //DESTROY the assymptote
    if ( (-val)<0 && 0<X)
        y[i1] = std::numeric_limits<double>::quiet_NaN();
    if ( (-val)<(-c*c*c) && (-c*c*c)<X  )
        y[i2] = std::numeric_limits<double>::quiet_NaN();

    graph->setData(x,y);
}

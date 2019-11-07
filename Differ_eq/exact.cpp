#include "exact.h"


Exact::Exact(QCustomPlot * gr) : Graph(gr)
{
    graph->setPen(QPen(color()));//Yellowish
}

//USELESS BUT NECESSARY; VERY KOSTIL
double Exact::errorfunc(double xi, double xi_1, double (*y)(double, double), double c){
    return xi + xi_1 + y(0,0) + c;
}

QColor Exact::color(){
    return (QColor( 0,0,0,255) );
}

double Exact::func( double x, double c){
   return (1/x + 1/(x + c*pow(pow(x,2),1/3.0)) );
}

void Exact::Calculate(double x0, double y0, double X, int N){

    //For the best precision
    N = 99999;
    double h = (X-x0)/N; //step
//    N = (X-x0)/h;
//    N = 3000;
//    if ( (X-x0) > 50)
//        N = ( (X-x0) > 100)? 5000:3100;

    int i1 = 0,i2 = 0; //To account for Gaps
    QVector<double> x(N+1), y(N+1);//N steps + 1 final point
    double c, x_v = x0; //Const and value to start stepping from


    //Constant coefficent calculation
    if (x0>=0)
        c = (y0*pow(x0,4/3.0)-2*pow(x0,1/3.0))/(1-x0*y0);
    else
        c = (y0*pow(pow(x0,4),1/3.0)-2*( -pow(-x0,1/3.0)) )/(1-x0*y0);//C kostil


    for(int i = 0; i<=N; i++){

        x[i] = x_v;
        y[i] = func(x[i],c);

        //Find assymtote
        if( abs(x[i] - 0) < abs(x[i1] - 0) )
            i1 = i;
        if( abs(x[i] + c*c*c) < abs(x[i2] + c*c*c) )
            i2 = i;

        x_v+=h;
    }

    //Create the assymptote
    if ( x0<0 && 0<X)
        y[i1] = std::numeric_limits<double>::quiet_NaN();
    if ( x0<(-c*c*c) && (-c*c*c)<X  )
        y[i2] = std::numeric_limits<double>::quiet_NaN();

    //assign data
    graph->setData(x, y);
    graph->setPen(QPen( color() ) ) ;//Black


}


void Exact::visible(bool x){
    graph->setVisible(x);
}

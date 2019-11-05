#include "exact_graph.h"
#include "Graph.h"


Exact_Graph::Exact_Graph(QCustomPlot * gr)
{
    Exact_Graph::graph = gr;
}


double Exact_Graph::func( double x, double c){
   return (1/x + 1/(x + c*pow(pow(x,2),1/3.0)) );
}


//Graphs 0-2
void Exact_Graph::Calculate(double x0, double y0, double X, int N){

//    qDebug("X: %f",graph->xAxis->pixelToCoord( (QCursor::pos()).x() ));
//    graph->graph()->selectTest()

    //For best precision
    N = 3000;
    if ( (X-x0) > 50)
        N = ( (X-x0) > 100)? 5000:3100;

    int i1 = 0,i2 = 0; //To account for Gaps
    QVector<double> x(N+1), y(N+1);//N steps + 1 final point
    double h = (X-x0)/N; //step
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

    //Create the assymptote graph
    if ( x0<0 && 0<X)
        y[i1] = std::numeric_limits<double>::quiet_NaN();
    if ( x0<(-c*c*c) && (-c*c*c)<X  )
        y[i2] = std::numeric_limits<double>::quiet_NaN();

    // create the graph and assign data to it
    graph->graph(0)->setData(x, y);
    graph->graph(0)->setPen(QPen(QColor(0,0,0,255) ) ) ;//Black

    graph->replot();

}


void Exact_Graph::Visibile(bool x){

    graph->graph(0)->setVisible(x);

    graph->replot();

}

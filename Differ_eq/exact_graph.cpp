#include "exact_graph.h"
#include "Graph.h"


//QCustomPlot Exact_Graph::*graph;

double round_nplaces(double value, int to)
{
    double places = pow(10.0, to);
    return round(value * places) / places;
}

bool cmpd(double A, double B, double epsilon = 0.001)
{
    return (fabs(A - B) < epsilon);
}

void Exact_Graph::AddGraph(QCustomPlot *element)
{
    graph = element;
}


double Exact_Graph::func( double x, double c){
   return (1/x + 1/(x + c*pow(pow(x,2),1/3.0)) );
}


//Graphs 0-2
void Exact_Graph::Calculate(double x0, double y0, double X, int N){

//    qDebug("X: %f",graph->xAxis->pixelToCoord( (QCursor::pos()).x() ));

//    graph->graph()->selectTest()

    int i1 = 0,i2 = 0; //Account for Gaps

    N = (int) 3000; //For best precision ("PUREST Kostil"

    if ( (X-x0) > 50)
        N = ( (X-x0) > 100)? 5000:3100;

    double h = (X-x0)/N; //step

    double c,x_v;

//    qDebug("N:%d  h:%f",N, h);

    //C kostil
    if (x0>=0)
        c = (y0*pow(x0,4/3.0)-2*pow(x0,1/3.0))/(1-x0*y0);//Constant coefficent
    else
        c = (y0*pow(pow(x0,4),1/3.0)-2*( -pow(-x0,1/3.0)) )/(1-x0*y0);//Constant coefficent


    QVector<double> x(N+1), y(N+1);
    x_v = x0;

    for(int i = 0; i<=N; i++){
        x[i] = x_v;

//        if ( cmpd(0,x[i],h*10) || cmpd(-c*c*c,x[i],h*10)){
//            y[i] = qQNaN();
//            qDebug("WHAT!!!!");
//        }
//        else

        //Find assymtote
        if( abs(x[i] - 0) < abs(x[i1] - 0) )
            i1 = i;

        if( abs(x[i] + c*c*c) < abs(x[i2] + c*c*c) )
            i2 = i;

        y[i] = func(x[i],c);

        x_v+=h;
    }

//    qDebug("%f %f",x[i1], x[i2]);


    if ( x0<0 && 0<X)
        y[i1] = std::numeric_limits<double>::quiet_NaN();
    if ( x0<(-c*c*c) && (-c*c*c)<X  )
        y[i2] = std::numeric_limits<double>::quiet_NaN();


//    for( int j = N/10; j>0; j--  ){
//        y[i1+j] = y[i2+j] = std::numeric_limits<double>::quiet_NaN();
//        y[i1-j] = y[i2-j] = std::numeric_limits<double>::quiet_NaN();
//    }


//    QVector<double> x2(size), y2(size);
//    //Plot positive
//    QVector<double> x(size), y(size);
//    for (int i=0; i<n; ++i)
//        for ( double j = 0; j < n; j+=1) {
//             int ind = i*n + (int)(j);

//             if ( i == 0 &&  cmpd(j,0)){
//                 x[0] = eps;
//                 y[0] = func(eps,c);
//                 continue;
//             }

//             x[ind] = i + (j/n);

//             if (c!=0.0 && cmpd(round_nplaces(x[ind],3),round_nplaces(-c*c*c,3)))
//                 y[ind] = qQNaN();
//             else
//                y[ind] = func(x[ind],c);

//        }

//    kostil = false;


//    QVector<double> x1(size), y1(size);
//    //Plot negative
//    for (int i=0; i<n; ++i)
//        for ( double j = 0; j < n; j+=1) {
//             int ind = i*n + (int)(j);

//             if ( i == 0 && cmpd(j,0) ){
//                 x1[0] = -eps;
//                 y1[0] = func(-eps,c);
//                 continue;
//             }

//             x1[ind] = -i - (j/n);

//             if ( c!=0.0 && cmpd(round_nplaces(x1[ind],3),round_nplaces(-c*c*c,3))  ){
//                 y1[ind] = qQNaN();

//             }
//                y1[ind] = func(x1[ind],c);

//        }

    // create graphs and assign data to them:
    graph->addGraph();
    graph->graph(0)->setAntialiased(false);
    graph->graph(0)->setPen(QPen(QColor(0,0,0,255) ) ) ;
//    graph->graph(0)->setLineStyle(QCPGraph::lsStepCenter);


    graph->graph(0)->setData(x, y);
//    graph->graph(1)->setData(x1, y1);
//    graph->graph(2)->setData(x2,y2);


    //Hide initially
    graph->graph(0)->setVisible(0);
//    graph->graph(1)->setVisible(0);
//    graph->graph(2)->setVisible(0);


    graph->replot();

}


void Exact_Graph::Visibile(bool x){

    graph->graph(0)->setVisible(x);

    graph->replot();

}

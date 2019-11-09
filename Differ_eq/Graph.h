#ifndef GRAPH_H
#define GRAPH_H
#include <qcustomplot.h>
#include <math.h>


class Graph
{
public:

    QCPGraph *graph;
    QColor color;

    Graph(QCustomPlot *gr){
        graph = gr->addGraph();
        graph->setAdaptiveSampling(false);
    }

//    virtual ~Graph();

    virtual void Calculate(double, double, double , int) = 0;
    virtual double errorfunc(double , double , double ){qDebug("YOU BAFFUN!");exit(228);}
    virtual void visible(bool x){ graph->setVisible(x);}

    //Necesasry calculation functions
    double y_f( double x, double c){return (1/x + 1/(x + c*pow(pow(x,2),1/3.0)) ); }
    double derivative(double x, double y){return ( -y*y/3 - 2.0/(3*x*x) );}
    double constant(double x0, double y0){
        //Constant coefficent calculation
        if (x0>=0)
            return (y0*pow(x0,4/3.0)-2*pow(x0,1/3.0))/(1-x0*y0);
        else
            return (y0*pow(pow(x0,4),1/3.0)-2*( -pow(-x0,1/3.0)) )/(1-x0*y0);//C kostil
    }


    bool cmpd(double A, double B, double epsilon = 0.001){
        return (fabs(A - B) < epsilon);
    }
    double find_biggest_error(double x0, double y0, double X, int N)
    {
        //SHOULD IT BE THE ABSOLUTE VALUE??????!!!!

        double err = 0;
        double h = (X-x0)/N;
        double c = constant(x0,y0);//Tricky

        //Go over every x value
        while(x0<=X){

            double cur_err = errorfunc(x0, x0+h, c);
            if ( abs(cur_err)> abs(err)) err  = cur_err;
            x0 += h;
        }

        return err;
    }


};


#endif // GRAPH_H

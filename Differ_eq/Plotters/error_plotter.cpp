#include "Plotters/error_plotter.h"

//Error_Plotter::Error_Plotter(QCustomPlot *cp, Main_Plotter *pl)

void Error_Plotter::Zoom(double X0, double X){
    grid->xAxis->setRange(X0, X);
    grid->yAxis->setRange(-100,100);

    grid->replot();
}


void Error_Plotter::Caculate_all(double x0, double y0, double X, int N)
{
    //Necessary calculations
    double h = (X-x0)/N;
    double c = graphs[0]->constant(x0,y0);//Tricky
    QVector< QVector<double> > xv(graphs.size()), yv(graphs.size());//Two vectors of corresponding values for each graph

    //Go over every x value
    while(x0<=X){

        //Do it for each graph
        for( int i = 0; i<ergraphs.size(); i++){
            xv[i].append(x0);
            yv[i].append(graphs[i]->errorfunc(x0, x0+h,c));
        }

        x0 += h;
    }

    //Add error data
    for( int i = 0; i<ergraphs.size(); i++){
        ergraphs[i]->setData(xv[i],yv[i]);
        grid->replot();
    }


    grid->replot();
}



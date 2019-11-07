#include "error_plotter.h"

Error_Plotter::Error_Plotter(QCustomPlot *cp, Main_Plotter *pl) : Plotter(cp)
{

    //Magic
    graphs = QVector<Graph*>(pl->to_plot);
    graphs.remove(0);


    //Generate new graphs automatically
    for (int i = 0; i < graphs.size(); i++){
        ergraphs.append( grid->addGraph() );
        ergraphs[i]->setPen( graphs[i]->color() );
    }


}

void Error_Plotter::Zoom(double X0, double X)
{
    grid->xAxis->setRange(X0, X);
    grid->yAxis->rescale(true);

    grid->replot();
}

void Error_Plotter::Caculate_all(double x0, double y0, double X, int N)
{
    //Necessary calculations
    double h = (X-x0)/N;
    double c;
    if (x0>=0)
        c = (y0*pow(x0,4/3.0)-2*pow(x0,1/3.0))/(1-x0*y0);
    else
        c = (y0*pow(pow(x0,4),1/3.0)-2*( -pow(-x0,1/3.0)) )/(1-x0*y0);//C kostil


    //Two vectors of corresponding values for each graph
    QVector< QVector<double> > xv(graphs.size()), yv(graphs.size());

    while(x0<=X){

        //Do it for each graph
        for( int i = 0; i<ergraphs.size(); i++){
            xv[i].append(x0);
            yv[i].append(graphs[i]->errorfunc(x0, x0+h, &y, c));
        }


        x0 += h;
    }

    for( int i = 0; i<ergraphs.size(); i++){
        ergraphs[i]->setData(xv[i],yv[i]);
        grid->replot();
    }


    grid->replot();
}



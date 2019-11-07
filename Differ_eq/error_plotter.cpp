#include "error_plotter.h"

Error_Plotter::Error_Plotter(QCustomPlot *cp, Main_Plotter *gr) : Plotter(cp)
{
    eulerErr = graph->addGraph();
    graph->addGraph();
    graph->addGraph();


    exact = gr->exact;
    euler = gr->euler;
}

void Error_Plotter::Zoom(double X0, double X)
{
    graph->xAxis->setRange(X0, X);
    graph->yAxis->rescale(true);

    graph->replot();
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


    //Add other ones
    QVector<Graph*> graphs   = {euler};
    QVector<QCPGraph*> ergraphs = {eulerErr};

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
        graph->replot();
    }


    eulerErr->setVisible(true); //REMOVE!!!!

    graph->replot();
}



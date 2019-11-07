#include "main_plotter.h"
#include <math.h>
#include <QMainWindow>

Main_Plotter::Main_Plotter(QCustomPlot * element) : Plotter(element)
{

    euler = new Euler(element);
    exact = new Exact(element);

}


void Main_Plotter::Zoom(double x1, double x2, double y)
{
    // set axes ranges, so we see all data:
    graph->xAxis->setRange(x1 , x2);
    y = abs(y);
    y = (y<=10)?10:y;
    graph->yAxis->setRange(-y , y);

    graph->replot();
}


//USING OOP, but weird....!!!!
void Main_Plotter::Caculate_all(double x0, double y0, double X, int N)
{
    Graph *sas[] = {exact, euler}; /// ADD other ones later!!!
    for (auto gr : sas ){
        gr->Calculate(x0, y0, X, N);
        graph->replot();
    }

    graph->replot();
}



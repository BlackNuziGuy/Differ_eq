#include "main_plotter.h"
#include <math.h>
#include <QMainWindow>

Main_Plotter::Main_Plotter(QCustomPlot * element) : Plotter(element)
{
    //Add other ones later; Remember order for the "visible" toggle function

    to_plot = {new Exact(element), new Euler(element) };

}


void Main_Plotter::Zoom(double x1, double x2, double y)
{
    // set axes ranges, so we see all data:
    grid->xAxis->setRange(x1 , x2);
    y = abs(y);
    y = (y<=10)?10:y;
    grid->yAxis->setRange(-y , y);

    grid->replot();
}


//USING OOP, but weird....!!!!
void Main_Plotter::Caculate_all(double x0, double y0, double X, int N)
{

    for (auto gr : to_plot ){
        gr->Calculate(x0, y0, X, N);
        grid->replot();
    }

    grid->replot();
}



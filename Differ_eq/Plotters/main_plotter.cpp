#include "Plotters/main_plotter.h"
#include <math.h>
#include <QMainWindow>

void Main_Plotter::Zoom(double x1, double x2, double y)
{
    // set axes ranges, so we see all data:
    grid->xAxis->setRange(x1 , x2);
    y = abs(y);
    y = (y<=10)?10:y;
    grid->yAxis->setRange(-y , y);

    grid->replot();
}


void Main_Plotter::Caculate_all(double x0, double y0, double X, int N){

    for (auto gr : to_plot ){
        gr->Calculate(x0, y0, X, N);
        grid->replot();
    }

    grid->replot();
}



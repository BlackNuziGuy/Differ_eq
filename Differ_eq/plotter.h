#ifndef PLOTTER_H
#define PLOTTER_H
#include <qcustomplot.h>

class Plotter
{
public:
    QCustomPlot* grid;

    Plotter(QCustomPlot *element){
        grid = element;

        //Set interactions and appearance
        grid->xAxis->ticker()->setTickStepStrategy( QCPAxisTicker::tssReadability);
        grid->xAxis->setLabel("x");
        grid->yAxis->setLabel("y");
    }

    void Zoom(double, double, double);
    void Caculate_all(double x0, double y0, double X, int N);
};

#endif // PLOTTER_H

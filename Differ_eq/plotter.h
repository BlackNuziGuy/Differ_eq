#ifndef PLOTTER_H
#define PLOTTER_H
#include <qcustomplot.h>

class Plotter
{
public:
    QCustomPlot* graph;

    Plotter(QCustomPlot *element){
        graph = element;

        //Set interactions and appearance
        graph->xAxis->ticker()->setTickStepStrategy( QCPAxisTicker::tssReadability);
        graph->xAxis->setLabel("x");
        graph->yAxis->setLabel("y");
    }

    void Zoom(double, double, double);
    void Caculate_all(double x0, double y0, double X, int N);
};

#endif // PLOTTER_H

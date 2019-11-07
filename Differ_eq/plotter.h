#ifndef PLOTTER_H
#define PLOTTER_H
#include <qcustomplot.h>

class Plotter{

public:
    QCustomPlot* grid;

    Plotter(QCustomPlot *element){
        grid = element;

        //Set interactions and appearance
        grid->xAxis->ticker()->setTickStepStrategy( QCPAxisTicker::tssReadability);
        grid->xAxis->setLabel("x");
        grid->yAxis->setLabel("y");
    }
//    virtual ~Plotter();


    virtual void Zoom(double, double, double) = 0;
    virtual void Caculate_all(double x0, double y0, double X, int N) = 0;
};
#endif // PLOTTER_H

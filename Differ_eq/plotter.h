#ifndef PLOTTER_H
#define PLOTTER_H
#include <qcustomplot.h>
#include "Graph.h"

class Plotter{

public:
    QCustomPlot* grid;

    Plotter(QCustomPlot *element){
        grid = element;

        grid->xAxis->setLabel("x");
        grid->yAxis->setLabel("y");

        grid->legend->setVisible(true);
    }


    virtual void Zoom(double, double, double) = 0;
    virtual void Caculate_all(double x0, double y0, double X, int N) = 0;
};
#endif // PLOTTER_H

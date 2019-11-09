#ifndef TOTERROR_GRAPH_H
#define TOTERROR_GRAPH_H

#include "Plotters/error_plotter.h"

class TotError_Plotter : public Error_Plotter
{
public:
    TotError_Plotter(QCustomPlot *cp, Main_Plotter *pl) : Error_Plotter(cp, pl){
        grid->xAxis->setLabel("N");
        grid->yAxis->setLabel("Error");
    }

    void Caculate_all(double x0, double y0, double X, int N0, int Nmax);

    void Zoom(double x0, double x1){
        grid->xAxis->setRange(x0,x1);
        grid->yAxis->setRange(-1,100);

        grid->replot();
        grid->replot();
    }

private:
    void Zoom(double, double,double) override{}
};

#endif // TOTERROR_GRAPH_H

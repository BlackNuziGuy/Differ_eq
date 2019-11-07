#ifndef TOTERROR_GRAPH_H
#define TOTERROR_GRAPH_H

#include "plotter.h"
#include "main_plotter.h"


class TotError_Plotter : public Plotter
{
public:
    TotError_Plotter(QCustomPlot *gr,Main_Plotter *pl);
    void Caculate_all(double x0, double y0, double X, int N) override;
    void Zoom(double, double);

private:
    void Zoom(double, double, double) override{}
};

#endif // TOTERROR_GRAPH_H

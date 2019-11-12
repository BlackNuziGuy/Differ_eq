#ifndef PLOTTER_H
#define PLOTTER_H
#include <qcustomplot.h>
#include "Graph.h"

class Plotter{

public:
    QCustomPlot* grid;
    QVector<Graph*> graphs;

    Plotter(QCustomPlot *element){
        grid = element;

        QFont kfont("Newyork",20);
        kfont.setStyleHint(QFont::SansSerif);
        kfont.setPointSize(20);

        grid->xAxis->setLabel("X");
        grid->yAxis->setLabel("Y");
        grid->xAxis->setLabelFont(kfont);
        grid->yAxis->setLabelFont(kfont);

        QFont pfont("Newyork",14);
        pfont.setStyleHint(QFont::SansSerif);
        pfont.setPointSize(14);

        grid->legend->setVisible(true);
        grid->legend->setFont(pfont);
        grid->setFont(pfont);

        grid->xAxis->setTickLabelFont(pfont);
        grid->yAxis->setTickLabelFont(pfont);
        grid->yAxis->setTickLabelFont(pfont);
        grid->xAxis->setTickLabelFont(pfont);

    }


    virtual void Zoom(double, double, double) = 0;
    virtual void Caculate_all(double x0, double y0, double X, int N) = 0;
};
#endif // PLOTTER_H

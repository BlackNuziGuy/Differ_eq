#ifndef MAIN_GRAPH_H
#define MAIN_GRAPH_H
#include "plotter.h"
#include "Graphs/exact.h"
#include "Graphs/kunkka.h"
#include "Graphs/imp_euler.h"
#include "Graphs/euler.h"



class Main_Plotter : public Plotter
{
public:
    QVector<Graph*>to_plot;


    Main_Plotter(QCustomPlot *element);
//    virtual ~Main_Plotter();



    void Zoom(double, double, double);
    void Caculate_all(double x0, double y0, double X, int N);
};

#endif // MAIN_GRAPH_H

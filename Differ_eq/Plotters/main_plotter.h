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
    //Add new graphs here; REMEMBER the order for the "visible" toggle functions
    Main_Plotter(QCustomPlot * element) : Plotter(element){
    graphs = {new Exact(element), new Euler(element), new Imp_Euler(element), new Kunkka(element)} ;}

    void Zoom(double, double, double);
    void Caculate_all(double x0, double y0, double X, int N);
};


#endif // MAIN_GRAPH_H

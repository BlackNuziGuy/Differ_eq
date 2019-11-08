#ifndef ERROR_GRAPH_H
#define ERROR_GRAPH_H

#include "plotter.h"
#include "Plotters/main_plotter.h"


class Error_Plotter : public Plotter
{
public:
    Error_Plotter(QCustomPlot *gr,Main_Plotter *pl);
    virtual ~Error_Plotter(){}

    QVector<Graph*> graphs;
    QVector<QCPGraph*> ergraphs;


    static double y( double x, double c){
        return (1/x + 1/(x + c*pow(pow(x,2),1/3.0)) );
    }



    void Zoom(double, double);
    void Caculate_all(double x0, double y0, double X, int N) override;

private:
    void Zoom(double, double,double) override{}
};
#endif // ERROR_GRAPH_H

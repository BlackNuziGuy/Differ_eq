#ifndef ERROR_GRAPH_H
#define ERROR_GRAPH_H

#include "plotter.h"
#include "Plotters/main_plotter.h"


class Error_Plotter : public Plotter
{
public:
    Error_Plotter(QCustomPlot *cp,Main_Plotter *pl) : Plotter(cp){

        //Magic
        graphs = QVector<Graph*>(pl->to_plot);
        graphs.remove(0);

        //Generate new graphs automatically
        for (int i = 0; i < graphs.size(); i++){
            ergraphs.append( grid->addGraph() );
            ergraphs[i]->setPen( graphs[i]->color );
            ergraphs[i]->setName( graphs[i]->graph->name() );
        }

    }


    virtual ~Error_Plotter(){}


    void Zoom(double, double);
    void Caculate_all(double x0, double y0, double X, int N) override;

    QVector<QCPGraph*> ergraphs;

private:
    void Zoom(double, double,double) override{}

protected:
    QVector<Graph*> graphs;
};
#endif // ERROR_GRAPH_H

#include "main_graph.h"
#include <math.h>
#include <QMainWindow>

Main_Graph::Main_Graph(QCustomPlot * element) : euler(element), exact(element)
{
    graph = element;

    //For each method
    graph->addGraph();
    graph->addGraph();
    graph->addGraph();
    graph->addGraph();


    graph->setInteraction(QCP::iSelectPlottables, true);
    graph->xAxis->ticker()->setTickStepStrategy( QCPAxisTicker::tssReadability);


    graph->xAxis->setLabel("x");
    graph->yAxis->setLabel("y");
}




void Main_Graph::Zoom(double x1, double x2)
{
    // set axes ranges, so we see all data:
    graph->xAxis->setRange((x1 > 0)? -1:x1 , x2);
    graph->yAxis->setRange((x1 > 0)? -1:x1 , x2);

    graph->replot();
}

void Main_Graph::Caculate_all(double x0, double y0, double X, int N)
{


}



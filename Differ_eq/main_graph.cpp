#include "main_graph.h"
#include <math.h>
#include <QMainWindow>

Main_Graph::Main_Graph()
{
}

QCustomPlot* Main_Graph::graph;


void Main_Graph::AddGraph(QCustomPlot *element)
{

    graph = element;

    graph->setInteraction(QCP::iSelectPlottables, true);

    graph->setInteractions(graph->interactions() | QCP::iRangeDrag);
    graph->setInteraction(QCP::iRangeZoom,true);
    graph->xAxis->ticker()->setTickStepStrategy( QCPAxisTicker::tssReadability);

    exact.AddGraph(element);
    euler.AddGraph(element);
}


void Main_Graph::Zoom(double x1, double x2)
{
    // set axes ranges, so we see all data:
    graph->xAxis->setRange(x1, x2);
    graph->yAxis->setRange((x1 > 0)? 0:x1 , x2);

    graph->replot();
}



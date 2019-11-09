#include "Plotters/toterror_plotter.h"

void TotError_Plotter::Caculate_all(double x0, double y0, double X, int N0, int Nmax){

    //Necessary calculations
    QVector< QVector<double> > xv(graphs.size()), yv(graphs.size());//Two vectors of corresponding values for each graph

    for (int j = N0; j <= Nmax; ++j) {

        //Do it for each graph
        for( int i = 0; i<ergraphs.size(); i++){
            xv[i].append(j);
            yv[i].append(graphs[i]->find_biggest_error(x0, y0,X,j) );
        }
    }


    //Add error data
    for( int i = 0; i<ergraphs.size(); i++){
        ergraphs[i]->setData(xv[i],yv[i]);
        grid->replot();
    }

    grid->replot();
}


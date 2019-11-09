#ifndef IMP_EULER_H
#define IMP_EULER_H
#include "Graph.h"

class Imp_Euler : public Graph{

public:
    Imp_Euler(QCustomPlot *gr):Graph(gr){
        color = QColor(0,200,51);
        graph->setPen(color);
        graph->setName("Imroved. Euler");
    }

    void Calculate(double x0, double y0, double X, int N);
    double errorfunc(double xi, double xi_1, double c);
};

#endif // IMP_EULER_H

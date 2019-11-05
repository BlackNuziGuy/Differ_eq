#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <main_graph.h>

Main_Graph MGraph;
double X0,Y0,X;
int N;
static bool X0_f = false,Y0_f = false,X_f = false,N_f = false;



void MainWindow::Set_Theme(){

    //Enable Dark Mode
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists())
    {
        printf("Unable to set stylesheet, file not found\n");
    }
    else
    {
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }

}

void MainWindow::Set_Appearance(Ui::MainWindow *ui){

    //Field input
    QDoubleValidator *sas = new QDoubleValidator(-1000, 1000, 3);
    ui->X->setValidator(sas);
    ui->X0->setValidator(sas);
    ui->Y0->setValidator(sas);

    ui->N->setValidator(new QIntValidator(1,99999));

    ui->exact->setEnabled(false);
    ui->euler->setEnabled(false);
}




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    Set_Theme();
    ui->setupUi(this);
    Set_Appearance(ui);

    MGraph.AddGraph(ui->Main_graph);
    MGraph.graph->xAxis->setLabel("x");
    MGraph.graph->yAxis->setLabel("y");
    //ADD LEGEND

//    connect(MGraph.graph, MGraph.graph->graph(0)->selected(), ui->TEST, ui->TEST->setText())

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_checkBox_toggled(bool checked)
{
    if (checked)
        MGraph.graph->setInteractions(MGraph.graph->interactions() | QCP::iRangeDrag);
    else
        MGraph.graph->setInteractions(MGraph.graph->interactions() ^ QCP::iRangeDrag);

    MGraph.graph->setInteraction(QCP::iRangeZoom,checked);
}


void MainWindow::on_euler_toggled(bool checked)
{
    MGraph.euler.Visibile(checked);
}

void MainWindow::on_exact_toggled(bool checked)
{
    MGraph.exact.Visibile(checked);
}





void MainWindow::do_stuff(){

    if (X0_f && Y0_f && N_f && X_f && X>X0){


        MGraph.exact.Calculate(X0, Y0, X, N);
        MGraph.exact.Visibile(true);

        MGraph.euler.Calculate(X0, Y0, X, N);
        MGraph.euler.Visibile(true);

        MGraph.Zoom(X0, X);
//        MGraph.graph->yAxis->rescale(true);


        ui->exact->setEnabled(true);
        ui->exact->setChecked(true);

        ui->euler->setEnabled(true);
        ui->euler->setChecked(true);

    }

}


void MainWindow::on_X0_textChanged(const QString &arg1)
{

    if (arg1.isEmpty()){
        X0_f = false;
    }
    else{
        X0_f = true;
        X0 = arg1.toDouble();

        do_stuff();

    }

}

void MainWindow::on_Y0_textChanged(const QString &arg1)
{

    if (arg1.isEmpty()){
        Y0_f = false;
    }
    else{
        Y0_f = true;
        Y0 = arg1.toDouble();

        do_stuff();


    }

}

void MainWindow::on_N_textChanged(const QString &arg1)
{
    if (arg1.isEmpty()){
        N_f = false;
    }
    else if ( arg1.toInt() != 0 ){
        N_f = true;
        N = arg1.toInt();

        do_stuff();
    }
}

void MainWindow::on_X_textChanged(const QString &arg1)
{

    if (arg1.isEmpty())
        X_f = false;
    else{
        X = arg1.toDouble();
        X_f = true;

        do_stuff();

    }



}

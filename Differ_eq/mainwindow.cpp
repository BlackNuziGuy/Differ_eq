#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>


void MainWindow::Set_Appearance(){

    //Enable Dark Mode
    QFile f(":qdarkstyle/style.qss");
    if (!f.exists()){
        printf("Unable to set stylesheet, file not found\n");
    }else{
        f.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&f);
        qApp->setStyleSheet(ts.readAll());
    }


    //Filter input
    QDoubleValidator *sas = new QDoubleValidator(-100, 100, 3);
    ui->X->setValidator(sas);
    ui->X0->setValidator(sas);
    ui->Y0->setValidator(sas);
    ui->N->setValidator(new QIntValidator(1,99999));


    //Disable some elements
    ui->exact->setEnabled(false);
    ui->euler->setEnabled(false);
    ui->Bug->setEnabled(false);


    //HANDY!!!
    ui->X0->setFocus();
}

//void MainWindow::Connect_Things()
//{
//    connect(ui->euler,SIGNAL(toggled(bool)), &(MGraph->euler), SLOT(Visibile(bool)));
//}



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Set_Appearance();
//    Connect_Things();

    MGraph = new Main_Graph(ui->plotter);


    //ADD LEGEND; Allow to choose graph by legend
    //Add function that connects
    //Change on_text_change_func
    //Add the feature to display value
    //    qDebug("X: %f",graph->xAxis->pixelToCoord( (QCursor::pos()).x() ));
    //    graph->graph()->selectTest()

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Bug_toggled(bool checked)
{
    //Drag
    if (checked)
        MGraph->graph->setInteractions(MGraph->graph->interactions() | QCP::iRangeDrag);
    else
        MGraph->graph->setInteractions(MGraph->graph->interactions() ^ QCP::iRangeDrag);

    //Scale
    MGraph->graph->setInteraction(QCP::iRangeZoom,checked);
}


void MainWindow::on_euler_toggled(bool checked)
{
    MGraph->euler.Visibile(checked);
}

void MainWindow::on_exact_toggled(bool checked)
{
    MGraph->exact.Visibile(checked);
}


void MainWindow::do_stuff(){

    if (X0_f && Y0_f && N_f && X_f && X>X0){

        if (X0 == 1.0 && Y0 == 4.0 && X == 8.0 && N == 8.0 )
            ui->Bug->setEnabled(true);


        MGraph->exact.Calculate(X0, Y0, X, N);

        MGraph->euler.Calculate(X0, Y0, X, N);


        MGraph->Zoom(X0, X,Y0);


        ui->exact->setEnabled(true);
        ui->exact->setChecked(true);

        ui->euler->setEnabled(true);
        ui->euler->setChecked(true);
    }
    else{
        ui->euler->setDisabled(true);
        ui->exact->setDisabled(true);
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

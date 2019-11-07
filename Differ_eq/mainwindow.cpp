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
    QDoubleValidator *sas = new QDoubleValidator(-100, 100, 2);
    ui->X->setValidator(sas);
    ui->X->setMaxLength(7);
    ui->X0->setValidator(sas);
    ui->X0->setMaxLength(7);
    ui->Y0->setValidator(sas);
    ui->Y0->setMaxLength(7);
    ui->N->setValidator(new QIntValidator(1,99999));


    //Disable some elements
    ui->exact->setEnabled(false);
    ui->euler->setEnabled(false);
    ui->Bug->setEnabled(true);

    //Make checked
    ui->radio_graph->setChecked(true);

    //HANDY!!!
    ui->X0->setFocus();
}




MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    Set_Appearance();
//    Connect_Things();

    MPlot = new Main_Plotter(ui->plotter);
    EPlot = new Error_Plotter(ui->eplotter, MPlot);


    //ADD LEGEND; Allow to choose graph by legend
    //Add function that connects??
    //Change on_text_change_func
    //Add threads
    //Add an ability to show 'precise' value
    //    qDebug("X: %f",graph->xAxis->pixelToCoord( (QCursor::pos()).x() ));
    //    graph->graph()->selectTest()
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Bug_toggled(bool checked)
{
    Plotter *sas[] = {MPlot, EPlot};

    for (auto Plot:sas){

        //Drag
        if (checked)
            Plot->graph->setInteractions(Plot->graph->interactions() | QCP::iRangeDrag);
        else
            Plot->graph->setInteractions(Plot->graph->interactions() ^ QCP::iRangeDrag);


        Plot->graph->setInteraction(QCP::iRangeZoom,checked); //Scale
        Plot->graph->setInteraction(QCP::iSelectPlottables, checked);//Selection
    }
}


void MainWindow::on_euler_toggled(bool checked)
{
    MPlot->euler->Visibile(checked);
    MPlot->graph->replot();
}
void MainWindow::on_exact_toggled(bool checked)
{
    MPlot->exact->Visibile(checked);
    MPlot->graph->replot();
}

void MainWindow::do_stuff(){

    if (X0_f && Y0_f && N_f && X_f && X>X0){

        //Change color to black
        QString text = "<html><head/><body><p>	X<span style=\" vertical-align:sub;\">0</span></p></body></html>";
        ui->label_X0->setText("<font color=#ffffff>"+text+"</font>");
        ui->label_X->setText("<font color=#ffffff>X</font>");



//        if (X0 == 1.0 && Y0 == 4.0 && X == 8.0 && N == 8.0 )
//            ui->Bug->setEnabled(true);


        MPlot->Caculate_all(X0, Y0, X, N);
        EPlot->Caculate_all(X0, Y0, X, N);

        EPlot->Zoom(X0,X);
        MPlot->Zoom(X0, X,Y0);


        ui->exact->setEnabled(true);
        ui->exact->setChecked(true);

        ui->euler->setEnabled(true);
        ui->euler->setChecked(true);

    }
    else{

        if (X0_f && X_f && X<=X0){

            QString text = "<html><head/><body><p>	X<span style=\" vertical-align:sub;\">0</span></p></body></html>";
            ui->label_X0->setText("<font color=#ff0000>"+text+"</font>");
            ui->label_X->setText("<font color=#ff0000>X</font>");
        }

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


void MainWindow::on_radio_error_toggled()
{

    ui->stackedWidget->setCurrentIndex( !ui->stackedWidget->currentIndex() );

    //resize
    ui->page->resize(ui->gridLayout_2->geometry().width(),ui->gridLayout_2->geometry().height());
    ui->page_2->resize(ui->gridLayout_2->geometry().width(),ui->gridLayout_2->geometry().height());


}


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
    ui->X0->setValidator(sas);
    ui->Y0->setValidator(sas);

    QIntValidator *syas = new QIntValidator(1,9999);
    ui->N->setValidator(syas);
    ui->N0->setValidator(syas);
    ui->Nmax->setValidator(syas);


    //Disable some elements
    ui->exact->setEnabled(false);
    ui->euler->setEnabled(false);
    ui->Bug->setEnabled(true);

    //Make checked
    ui->radio_graph->setChecked(true);

    //HANDY!!!
    ui->X0->setFocus();
}

void MainWindow::do_stuff(){

    if (X0_f && Y0_f && N_f && X_f && X>X0){

        //Change color to black
        QString text = "<html><head/><body><p>	X<span style=\" vertical-align:sub;\">0</span></p></body></html>";
        ui->label_X0->setText("<font color=#ffffff>"+text+"</font>");
        ui->label_X->setText("<font color=#ffffff>X</font>");


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

void MainWindow::set_graph_visibility(int ind, bool c){

    MPlot->to_plot[ind]->visible(c);
    EPlot->ergraphs[ind -1]->setVisible(c);

    MPlot->grid->replot();
    EPlot->grid->replot();
}

void MainWindow::change_value(bool *b, double *v, QString arg1){
    if (arg1.isEmpty())
        *b = false;
    else{
        *v = arg1.toDouble();
        *b = true;

        do_stuff();
    }
}



MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    Set_Appearance();

    MPlot = new Main_Plotter(ui->plotter);
    EPlot = new Error_Plotter(ui->eplotter, MPlot);


    //ADD LEGEND; Allow to choose graph by legend
    //Add threads
    //Add an ability to show 'precise' value
    //    qDebug("X: %f",graph->xAxis->pixelToCoord( (QCursor::pos()).x() ));
    //    graph->graph()->selectTest()
}
MainWindow::~MainWindow(){delete ui;}


//Use the index from MPlot constructor for graphs with errors
void MainWindow::on_euler_toggled(bool checked){set_graph_visibility(1, checked);}
void MainWindow::on_exact_toggled(bool checked){MPlot->to_plot[0]->visible(checked);MPlot->grid->replot();}
void MainWindow::on_radio_error_toggled(){ui->stackedWidget->setCurrentIndex( !ui->stackedWidget->currentIndex() );}
void MainWindow::on_Bug_toggled(bool checked)
{
    Plotter *sas[] = {MPlot, EPlot};

    for (auto Plot:sas){
        //Drag
        if (checked)
            Plot->grid->setInteractions(Plot->grid->interactions() | QCP::iRangeDrag);
        else
            Plot->grid->setInteractions(Plot->grid->interactions() ^ QCP::iRangeDrag);

        Plot->grid->setInteraction(QCP::iRangeZoom,checked); //Scale
        Plot->grid->setInteraction(QCP::iSelectPlottables, checked);//Selection
    }
}


void MainWindow::on_X0_textChanged(const QString &arg1){change_value(&X0_f,&X0,arg1);}
void MainWindow::on_Y0_textChanged(const QString &arg1){change_value(&Y0_f,&Y0,arg1);}
void MainWindow::on_X_textChanged(const QString &arg1) {change_value(&X_f,&X,arg1);}
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




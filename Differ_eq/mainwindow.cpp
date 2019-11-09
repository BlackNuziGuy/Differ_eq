#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    Set_Appearance();

    MPlot = new Main_Plotter(ui->plotter);
    EPlot = new Error_Plotter(ui->eplotter, MPlot);
    TEPlot = new TotError_Plotter(ui->Tot_plot, MPlot);

    graph_check_boxes = { ui->euler, ui->imp_euler, ui->exact, ui->kunkka};

    //ADD LEGEND; Allow to choose graph by legend
    //Add threads
    //Add an ability to show 'precise' value
    //    qDebug("X: %f",graph->xAxis->pixelToCoord( (QCursor::pos()).x() ));
    //    graph->graph()->selectTest()
}
MainWindow::~MainWindow(){delete ui;}


//The only button...... and radioBUTTON (pun intended) functions
void MainWindow::on_FIND_clicked()
{
    if (N0_f && Nmax_f && Nmax > N0 && X0_f && Y0_f && X_f && X>X0){

    TEPlot->Caculate_all(X0, Y0, X, N0, Nmax);
    TEPlot->Zoom(N0,Nmax);

    ui->FIND->setDisabled(true);
    }
}
void MainWindow::on_radio_error_toggled(){
    ui->stackedWidget->setCurrentIndex( !ui->stackedWidget->currentIndex() );
    ui->exact->setDisabled(ui->stackedWidget->currentIndex());
}


//Checkboxes; !!Use the index from MPlot constructor for graphs with errors!!
void MainWindow::on_exact_toggled(bool checked){MPlot->to_plot[0]->visible(checked);MPlot->grid->replot();}
void MainWindow::on_euler_toggled(bool checked){set_graph_visibility(1, checked);MPlot->grid->replot();}
void MainWindow::on_imp_euler_toggled(bool checked){ set_graph_visibility(2,checked);MPlot->grid->replot();}
void MainWindow::on_kunkka_toggled(bool checked){set_graph_visibility(3,checked);MPlot->grid->replot();}
void MainWindow::on_Bug_toggled(bool checked)
{
    Plotter *sas[] = {MPlot, EPlot, TEPlot};

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


//Text fields
void MainWindow::on_X0_textChanged(const QString &arg1){change_value(&X0_f,&X0,arg1);}
void MainWindow::on_Y0_textChanged(const QString &arg1){change_value(&Y0_f,&Y0,arg1);}
void MainWindow::on_X_textChanged(const QString &arg1) {change_value(&X_f,&X,arg1);}
void MainWindow::on_N_textChanged(const QString &arg1)
{
    if (arg1.isEmpty() || arg1.toInt() == 0){
        N_f = false;
    }
    else{
        N_f = true;
        N = arg1.toInt();

        do_stuff();
    }
}
void MainWindow::on_N0_textChanged(const QString &arg1){

    if (arg1.isEmpty() /*|| arg1.toInt() == 0*/){
        N0_f = false;
    }
    else{
        N0_f = true;
        N0 = arg1.toInt();

    }

    do_stuff_for_toterr();
}
void MainWindow::on_Nmax_textChanged(const QString &arg1){

    if (arg1.isEmpty() /*|| arg1.toInt() == 0*/){
        Nmax_f = false;
    }
    else{
        Nmax_f = true;
        Nmax = arg1.toInt();
    }

    do_stuff_for_toterr();
}


//Helper functions
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
    QIntValidator *syas = new QIntValidator(1,9999);

    ui->X->setValidator(sas);
    ui->X0->setValidator(sas);
    ui->Y0->setValidator(sas);
    ui->N->setValidator(new QIntValidator(1,99999));
    ui->N0->setValidator(syas);
    ui->Nmax->setValidator(syas);


    //Disable some elements

    for (auto box : graph_check_boxes )
        box->setDisabled(true);
    ui->FIND->setDisabled(true);

    ui->radio_graph->setChecked(true);//Make main graph selected initially

    ui->X0->setFocus();//HANDY!!!
}
void MainWindow::do_stuff_for_toterr()
{
    QString N0_t = "<html><head/><body><p><span style=\" font-size:16pt;\">N</span><span style=\" font-size:16pt; vertical-align:sub;\">0</span></p></body></html>";
    QString Nmax_t = "<html><head/><body><p><span style=\" font-size:16pt;\">N</span><span style=\" font-size:16pt; vertical-align:sub;\">max</span></p></body></html>";


     if (N0_f && Nmax_f && X0_f && Y0_f && X_f &&!(Nmax <= N0 || Nmax==0 || N0==0)){

         ui->FIND->setEnabled(true);

         ui->label_N0->setText("<font color=#ffffff>"+N0_t+"</font>");
         ui->label_Nmax->setText("<font color=#ffffff>"+Nmax_t+"</font>");
     }
     else{

         ui->FIND->setDisabled(true);

         if( N0_f && Nmax_f &&(Nmax <= N0 || Nmax==0 || N0==0)){

             ui->label_N0->setText("<font color=#ff0000>"+N0_t+"</font>");
             ui->label_Nmax->setText("<font color=#ff0000>"+Nmax_t+"</font>");

         }
     }
}
void MainWindow::do_stuff(){

    do_stuff_for_toterr();

    if (X0_f && Y0_f && N_f && X_f && X>X0){

        //Change color to black
        QString text = "<html><head/><body><p>	X<span style=\" vertical-align:sub;\">0</span></p></body></html>";
        ui->label_X0->setText("<font color=#ffffff>"+text+"</font>");
        ui->label_X->setText("<font color=#ffffff>X</font>");


        MPlot->Caculate_all(X0, Y0, X, N);
        EPlot->Caculate_all(X0, Y0, X, N);

        EPlot->Zoom(X0,X);
        MPlot->Zoom(X0, X,Y0);

        for (auto box : graph_check_boxes ){
            box->setEnabled(true);
            box->setChecked(true);
        }

    }
    else{

        //Change color to red
        if (X0_f && X_f && X<=X0){
            QString text = "<html><head/><body><p>	X<span style=\" vertical-align:sub;\">0</span></p></body></html>";
            ui->label_X0->setText("<font color=#ff0000>"+text+"</font>");
            ui->label_X->setText("<font color=#ff0000>X</font>");
        }

        ui->FIND->setDisabled(true);
        for (auto box : graph_check_boxes )
            box->setDisabled(true);

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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);

    MPlot = new Main_Plotter(ui->plotter);
    EPlot = new Error_Plotter(ui->eplotter, MPlot);
    TEPlot = new TotError_Plotter(ui->Tot_plot, MPlot);

    QVector<QWidget*> kek = { ui->SET, ui->Save, ui->Z1, ui->Z2, ui->l14,ui->l13, ui->X_val, ui->Y_val  };
    graph_check_boxes = { ui->euler, ui->imp_euler, ui->exact, ui->kunkka, ui->Teuler, ui->Timp_euler, ui->TKunkka};
    plots = {MPlot, EPlot, TEPlot};

    Set_Appearance();

//    for (auto p : plots){
//        QCustomPlot*plot = p->grid;
        connect(MPlot->grid->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
        connect(MPlot->grid->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));

        connect(EPlot->grid->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
        connect(EPlot->grid->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));
//}

    for (auto el: kek)
        el->hide();
}
MainWindow::~MainWindow(){delete ui;}


//The only button...... and radioBUTTON (pun intended) functions
void MainWindow::on_FIND_clicked()
{
    if (N0_f && Nmax_f && Nmax > N0 && X0_f && Y0_f && X_f && X>X0){

    TEPlot->Caculate_all(X0, Y0, X, N0, Nmax);
    TEPlot->Zoom(N0,Nmax);

    TEPlot->grid->yAxis->setRange(-0.5,80);
    TEPlot->grid->replot();

    ui->FIND->setDisabled(true);
    }
}
void MainWindow::on_radio_error_toggled(){
    ui->stackedWidget->setCurrentIndex( !ui->stackedWidget->currentIndex() );
    ui->exact->setDisabled(ui->stackedWidget->currentIndex());
}


//Checkboxes; !!Use the index from EPlot constructor for the all graphs,but the exact one!!
void MainWindow::on_euler_toggled(bool checked)     {set_graph_visibility(0,checked);}
void MainWindow::on_imp_euler_toggled(bool checked) {set_graph_visibility(1,checked);}
void MainWindow::on_kunkka_toggled(bool checked)    {set_graph_visibility(2,checked);}
void MainWindow::on_Teuler_toggled(bool checked)    {TEPlot->ergraphs[0]->setVisible(checked); TEPlot->grid->replot();}
void MainWindow::on_Timp_euler_toggled(bool checked){TEPlot->ergraphs[1]->setVisible(checked); TEPlot->grid->replot();}
void MainWindow::on_TKunkka_toggled(bool checked)   {TEPlot->ergraphs[2]->setVisible(checked); TEPlot->grid->replot();}
void MainWindow::on_exact_toggled(bool checked)     {  MPlot->to_plot[0]->visible(checked)   ; MPlot->grid->replot();}
void MainWindow::on_Bug_toggled(bool checked)
{

    for (auto Plot:plots){

        if (checked)
            Plot->grid->setInteractions(Plot->grid->interactions() | QCP::iRangeDrag);
        else
            Plot->grid->setInteractions(Plot->grid->interactions() ^ QCP::iRangeDrag);

        Plot->grid->setInteraction(QCP::iRangeZoom,checked); //Scale
//        Plot->grid->setInteraction(QCP::iSelectPlottables, checked);//Selection
    }
}


//Text fields
void MainWindow::on_X0_textChanged(const QString &arg1){change_value(&X0_f,&X0,arg1);}
void MainWindow::on_Y0_textChanged(const QString &arg1){change_value(&Y0_f,&Y0,arg1);}
void MainWindow::on_X_textChanged(const QString &arg1) {change_value(&X_f, &X, arg1);}
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

    QString sas = "^(-?)(0|([0-9]?[0-9]?[0-9]?[0-9]?[0-9]))(\\.[0-9]?[0-9])?$";

//    ui->X->setValidator(new QRegExpValidator(QRegExp(sas)));
//    ui->X->setValidator(sas);
//    ui->X0->setValidator(sas);
//    ui->Y0->setValidator(sas);
//    ui->N->setValidator(new QIntValidator(1,99999));
//    ui->N0->setValidator(syas);
//    ui->Nmax->setValidator(syas);



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

    if (X0_f && Y0_f && N_f && X_f && X>X0 && gut(X0) && gut(X) && gut(Y0)){

        //Change color to black
        QString text = "<html><head/><body><p>	X<span style=\" vertical-align:sub;\">0</span></p></body></html>";
        ui->label_X0->setText("<font color=#ffffff>"+text+"</font>");
        ui->label_X->setText("<font color=#ffffff>X</font>");
        text = "<html><head/><body><p>Y<span style=\" vertical-align:sub;\">0</span></p></body></html>";
        ui->label_Y0->setText("<font color=#ffffff>"+text+"</font>");



        MPlot->Caculate_all(X0, Y0, X, N);
        EPlot->Caculate_all(X0, Y0, X, N);

//        MPlot->grid->savePng("SYAS");

        EPlot->Zoom(X0,X);
        EPlot->grid->yAxis->setRange(0,20);
        MPlot->Zoom(X0, X,Y0);

        for (auto box : graph_check_boxes ){
            box->setEnabled(true);
            box->setChecked(true);
        }

        if ( ui->radio_error->isChecked())
            ui->exact->setDisabled(true);

    }
    else{

        //Change color to red
        if (X0_f && X_f && ( X<=X0 || !gut(X0) || !gut(X)) ){
            QString text = "<html><head/><body><p>	X<span style=\" vertical-align:sub;\">0</span></p></body></html>";

//            if (!gut(X0))
//                ui->label_X0->setText("<font color=#ff0000>"+text+"</font>");
//            if (!gut(X))
//                ui->label_X->setText("<font color=#ff0000>X</font>");
            if ( (X<=X0) ){
                ui->label_X0->setText("<font color=#ff0000>"+text+"</font>");
                ui->label_X->setText("<font color=#ff0000>X</font>");
            }

        }
        else{ //Or not
            QString text = "<html><head/><body><p>	X<span style=\" vertical-align:sub;\">0</span></p></body></html>";
            ui->label_X0->setText("<font color=#ffffff>"+text+"</font>");
            ui->label_X->setText("<font color=#ffffff>X</font>");
        }
        QString text = "<html><head/><body><p>Y<span style=\" vertical-align:sub;\">0</span></p></body></html>";
        if (Y0_f && !gut(Y0))
            ui->label_Y0->setText("<font color=#ff0000>"+text+"</font>");
        else
            ui->label_Y0->setText("<font color=#ffffff>"+text+"</font>");


        ui->FIND->setDisabled(true);

        for (auto box : graph_check_boxes )
            box->setDisabled(true);
    }

}
void MainWindow::set_graph_visibility(int ind, bool c){

    MPlot->to_plot[ind + 1]->visible(c);
    EPlot->ergraphs[ind]->setVisible(c);

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


void MainWindow::xAxisChanged(const QCPRange & newRange)
{
    QCPAxis * axis = qobject_cast<QCPAxis *>(QObject::sender());
    QCustomPlot * plot = axis->parentPlot();

    QCPRange limitRange(plot->property("xmin").toDouble(), plot->property("xmax").toDouble());
    limitAxisRange(axis, newRange, limitRange);

    plot->replot();
}
void MainWindow::yAxisChanged(const QCPRange & newRange)
{
    QCPAxis * axis = qobject_cast<QCPAxis *>(QObject::sender());
    QCustomPlot * plot = axis->parentPlot();

    QCPRange limitRange(plot->property("ymin").toDouble(), plot->property("ymax").toDouble());
    limitAxisRange(axis, newRange, limitRange);

    plot->replot();
}
void MainWindow::limitAxisRange(QCPAxis * axis, const QCPRange & newRange, const QCPRange & limitRange)
{
    auto lowerBound = limitRange.lower;
    auto upperBound = limitRange.upper;

    // code assumes upperBound > lowerBound
    QCPRange fixedRange(newRange);
    if (fixedRange.lower < lowerBound)
    {
        fixedRange.lower = lowerBound;
        fixedRange.upper = lowerBound + newRange.size();
        if (fixedRange.upper > upperBound || qFuzzyCompare(newRange.size(), upperBound-lowerBound))
            fixedRange.upper = upperBound;
        axis->setRange(fixedRange); // adapt this line to use your plot/axis
    } else if (fixedRange.upper > upperBound)
    {
        fixedRange.upper = upperBound;
        fixedRange.lower = upperBound - newRange.size();
        if (fixedRange.lower < lowerBound || qFuzzyCompare(newRange.size(), upperBound-lowerBound))
            fixedRange.lower = lowerBound;
        axis->setRange(fixedRange); // adapt this line to use your plot/axis
    }
}

//void MainWindow::on_Save_pressed(){
//    MPlot->grid->savePng("Main.png");
//    EPlot->grid->savePng("Error.png");
//    TEPlot->grid->savePng("Total.png");
//}

//void MainWindow::on_SET_clicked()
//{
//    MPlot->grid->yAxis->setRange( ui->Z1->text().toDouble(), ui->Z2->text().toDouble()  );
//    EPlot->grid->yAxis->setRange( ui->Z1->text().toDouble(), ui->Z2->text().toDouble()  );
//    TEPlot->grid->yAxis->setRange( ui->Z1->text().toDouble(), ui->Z2->text().toDouble()  );

//    MPlot->grid->replot();
//    EPlot->grid->replot();
//    TEPlot->grid->replot();

//}



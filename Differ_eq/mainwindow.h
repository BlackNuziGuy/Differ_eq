#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Plotters/main_plotter.h"
#include "Plotters/error_plotter.h"
#include "Plotters/toterror_plotter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_X0_textChanged(const QString &arg1);
    void on_Y0_textChanged(const QString &arg1);
    void on_X_textChanged(const QString &arg1);
    void on_N_textChanged(const QString &arg1);

    void on_euler_toggled(bool checked);
    void on_exact_toggled(bool checked);

    void on_Bug_toggled(bool checked);
    void on_radio_error_toggled();

private:
    Ui::MainWindow *ui;
    Main_Plotter *MPlot;
    Error_Plotter *EPlot;
    TotError_Plotter *TEPlot;

    double X0,Y0,X;
    int N;
    bool X0_f = false,Y0_f = false,X_f = false,N_f = false;



    void Set_Appearance();
    void do_stuff();
    void set_graph_visibility(int ind, bool c);
    void change_value(bool*, double*, QString);
//    void Connect_Things();


};
#endif // MAINWINDOW_H

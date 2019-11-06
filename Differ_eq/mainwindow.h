#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <main_graph.h>

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

private:
    Ui::MainWindow *ui;
    Main_Graph *MGraph;
    double X0,Y0,X;
    int N;
    bool X0_f = false,Y0_f = false,X_f = false,N_f = false;



    void Set_Appearance();
    void do_stuff();
//    void Connect_Things();


};
#endif // MAINWINDOW_H

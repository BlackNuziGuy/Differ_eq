#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void do_stuff();


private slots:
    void on_exact_toggled(bool checked);

    void on_X0_textChanged(const QString &arg1);

    void on_Y0_textChanged(const QString &arg1);

    void on_X_textChanged(const QString &arg1);

    void on_N_textChanged(const QString &arg1);

//    void on_lineEdit_textChanged(const QString &arg1);

    void on_euler_toggled(bool checked);

    void on_checkBox_toggled(bool checked);

private:
    void Set_Theme();
    void Set_Appearance(Ui::MainWindow *ui);
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H

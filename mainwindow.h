#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include"employe.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void update_id();
private slots:

    bool controleNumTel(int test);

    bool controleVide(QString test);

    bool controleVideInt(int test);

    bool controleEmail(QString test);

    void on_pushButtonAjouter_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_LeTitreRT_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_Impdos_2_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;
    Employe emp;
    int id_emp=0;
};

#endif // MAINWINDOW_H

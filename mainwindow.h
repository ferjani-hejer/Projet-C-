#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"reportage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonAjouter_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButtonModifier_clicked();

    void on_idRT_textChanged(const QString &arg1);

    void on_categorieRT_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    Reportage R;
};

#endif // MAINWINDOW_H

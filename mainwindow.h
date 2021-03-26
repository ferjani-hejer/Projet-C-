#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"historique.h"

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
    bool controleVide(QString test);

    bool controleVideInt(int test);

    void on_pushButtonAjouter_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_LeTitreRT_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    Historique h;
};

#endif // MAINWINDOW_H

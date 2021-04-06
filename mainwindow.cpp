#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include<QLineEdit>

#include <QPrinter>
#include <QPrintDialog>
#include "dialogemploye.h"
#include "dialoghistorique.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonEmploye_clicked()
{
    Dialogemploye E;
    E.exec();
}
void MainWindow::on_pushButtonHistorique_clicked()
{
    Dialoghistorique H;
    H.exec();
}


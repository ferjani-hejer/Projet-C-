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
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    playermusic = new QMediaPlayer;
    player = new QMediaPlayer;
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonEmploye_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/Source/son.wav"));
    player->play();
    qDebug() << player->errorString();

    Dialogemploye E;
    E.exec();
}
void MainWindow::on_pushButtonHistorique_clicked()
{
    player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/Source/son.wav"));
    player->play();
    qDebug() << player->errorString();

    Dialoghistorique H;
    H.exec();
}


void MainWindow::on_start_2_clicked()
{
   playermusic->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Desktop/Source/music.mp3"));
   playermusic->play();
   qDebug() << playermusic->errorString();
}

void MainWindow::on_pause_2_clicked()
{

    playermusic->pause();

}

void MainWindow::on_horizontalSlider_2_sliderMoved(int position)
{
    playermusic->setVolume(position);
}

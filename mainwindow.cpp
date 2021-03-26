#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPixmap>
#include"article.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include <QDateTime>
#include<QDate>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(A.afficherArticle());

}


MainWindow::~MainWindow()
{
    delete ui;
}



/*void MainWindow::on_pushButton_SupprimerArticle_clicked()
{

    int idA =ui->leId_6->text().toInt();
        bool test = A.supprimerArticle(idA);
        if(test)
        {
            //refresh affichage
            ui->tableView->setModel(A.afficherArticle());

            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

        }
        else
            QMessageBox::critical(nullptr,QObject::tr("not ok"),
                                  QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}*/



void MainWindow::on_pushButtonAjouter_clicked()
{
    //Récuprération des informations saisies dans les 3 champs
       int idA=ui->LeId->text().toInt(); //convertir une chaine de caractére en un entier
       QString titre=ui->LeTitre->text();
       QString description=ui->LeDescription->text();
       QString auteur=ui->LeAuteur->text();
       QDateTime dateA=ui->dateEdit->dateTime();

       //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
       Article A(idA,titre,description,auteur,dateA);
       //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
       bool test =A.ajouterArticle();
       if(test)//si requête executée ==>QMessageBox::information
       {

          //refresh affichage
          ui->tableView->setModel(A.afficherArticle());
           QMessageBox::information(nullptr,QObject::tr("ok"),
                   QObject::tr("Ajout  effectué \n Click Cancel to exit."), QMessageBox::Cancel);
       }
       else //si requête non exécutée ==>QMessageBox::critical
           QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                                 QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);




}

void MainWindow::on_pushButtonSupprimer_clicked()
{
    int idA =ui->LeIdMS->text().toInt();
        bool test = A.supprimerArticle(idA);
        if(test)
        {
            //refresh affichage
            ui->tableView->setModel(A.afficherArticle());

            QMessageBox::information(nullptr,QObject::tr("Supprimer un article"),
                                     QObject::tr("Article supprimé \n ""Click Cancel to exit."),QMessageBox::Cancel);

        }
        else{
            QMessageBox::critical(nullptr,QObject::tr("Supprimer un article"),
                                  QObject::tr("Erreur !.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
}

void MainWindow::on_pushButtonModifier_clicked()
{
         int idA =ui->LeIdMS->text().toInt();
        QString titre = ui->LeTitre->text();
        QString description = ui->LeDescription->text();
        QString auteur = ui->LeAuteur->text();
        QDateTime dateA = ui->dateEdit->dateTime();
        Article A(idA,titre,description,auteur,dateA);
        bool test= A.modifierArticle(idA);
        if(test)
        {

            ui->tableView->setModel(A.afficherArticle());//refresh
      QMessageBox::information(nullptr, QObject::tr("Modifier un article"),
                        QObject::tr("article modifié.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            }
}



void MainWindow::on_LeIdRT_textChanged(const QString &arg1)
{
     ui->tableView->setModel(A.rechercherIDA(arg1));
}

void MainWindow::on_LeTitreRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(A.rechercherTitre(arg1));
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(A.AfficherTrieIdA());
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->tableView->setModel(A.AfficherTrieTitre());
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>
#include<QDate>
#include<QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(R.afficherReportage());
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_leBtAjouter_clicked()
{
    //Récuprération des informations saisies dans les 3 champs
    int idA=ui->id->text().toInt(); //convertir une chaine de caractére en un entier
    QString titre=ui->leNom->text();
    QString video=ui->lePrenom->text();
    QString realisateur=ui->lePrenom_4->text();
    QDateTime dateR=ui->dateEdit->dateTime();
    QString categorie=ui->lePrenom_3->text();
    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Reportage R(idA,titre,video,realisateur,dateR,categorie);
    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =R.ajouterReportage();
    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tabview->setModel(R.afficherReportage());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);





}*/

/*void MainWindow::on_leSupp_clicked()
{
    int id =ui->leIdSupp->text().toInt();
    bool test = R.supprimerReportage(id);
    if(test)
    {
        //refresh affichage
         ui->tabview->setModel(R.afficherReportage());

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
    int idA=ui->Id->text().toInt(); //convertir une chaine de caractére en un entier
    QString titre=ui->titre->text();
    QString realisateur=ui->realisateur->text();
    QDateTime dateR=ui->dateEdit->dateTime();
    QString categorie=ui->categorie->currentText();
    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Reportage R(idA,titre,realisateur,dateR,categorie);
    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =R.ajouterReportage();
    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(R.afficherReportage());
        QMessageBox::information(nullptr,QObject::tr("ajouter un reportage"),
                QObject::tr("reportage ajouté \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
       { QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Erreur !. \n ""Click Cancel to exit."),QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButtonSupprimer_clicked()
{
    int id =ui->idMS->text().toInt();
    bool test = R.supprimerReportage(id);
    if(test)
    {
        //refresh affichage
         ui->tableView->setModel(R.afficherReportage());

        QMessageBox::information(nullptr,QObject::tr("Supprimer un reportage"),
                                 QObject::tr("reportage supprimé \n ""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr,QObject::tr("Supprimer un reportage"),
                              QObject::tr("Erreur !.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButtonModifier_clicked()
{

   int idA =ui->Id->text().toInt();
   QString titre = ui->titre->text();
   QString realisateur = ui->realisateur->text();
   QDateTime dateR = ui->dateEdit->dateTime();
   QString categorie = ui->categorie->currentText();

   Reportage R(idA,titre,realisateur,dateR,categorie);

   bool test= R.modifierReportage(idA);
   if(test)
   {

       ui->tableView->setModel(R.afficherReportage());//refresh
 QMessageBox::information(nullptr, QObject::tr("Modifier un reportage"),
                   QObject::tr("reportage modifié.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       }
}

void MainWindow::on_idRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(R.rechercherIDA(arg1));
}

void MainWindow::on_categorieRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(R.rechercherCategorie(arg1));
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(R.AfficherTrieIdA());
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView->setModel(R.AfficherTrieCategorie());
}

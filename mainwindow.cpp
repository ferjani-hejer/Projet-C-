#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employe.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>


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

bool MainWindow::controleNumTel(int test)
{
    QString tel= QString::number(test);
    for(int i=0;i<tel.length();i++)
    {
        if (tel.length()==8)
        {
            return true;
        }
    }
    return false;
}

bool MainWindow::controleVide(QString test)
{
    if(test!="")
        return  true;
    return false;

}

bool MainWindow::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}

bool MainWindow::controleEmail(QString test)
{
    for(int i=0;i<test.length();i++)
    {
        if (test.at(i)=='@')
        {
            return true;
        }
    }
    return false;
}

void MainWindow::on_pushButtonAjouter_clicked()
{

    //Récuprération des informations saisies dans les 3 champs

    int id=ui->LeId->text().toInt(); //convertir une chaine de caractére en un entier
    QString nom=ui->LeTitre->text();
    QString prenom=ui->LeDescription->text();
    QString email=ui->Lemail->text();
    int num_tel=ui->lineEdit->text().toInt(); //convertir une chaine de caractére en un entier
    int salaire=ui->lineEdit_2->text().toInt(); //convertir une chaine de caractére en un entier
    QString role=ui->comboBox->currentText();

    bool test2;
    test2=(controleEmail(email)&&controleVide(nom)&&controleVide(prenom)&&controleVide(email)&&controleVideInt(num_tel)&&controleVideInt(salaire)&&controleVideInt(id) );

    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Employe E(id,nom,prenom,email,num_tel,salaire,role);
    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =E.ajouterEmployes();

  if(test2)
  {

    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(emp.afficherEmployes());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }

    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
  }

  else

  {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un employé "),
                                 QObject::tr("Employé non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


  }


}

void MainWindow::on_pushButtonModifier_clicked()
{
    //Récuprération des informations saisies dans les 3 champs

    int id=ui->LeIdMS->text().toInt(); //convertir une chaine de caractére en un entier
    QString nom=ui->LeTitre->text();
    QString prenom=ui->LeDescription->text();
    QString email=ui->Lemail->text();
    int num_tel=ui->lineEdit->text().toInt(); //convertir une chaine de caractére en un entier
    int salaire=ui->lineEdit_2->text().toInt(); //convertir une chaine de caractére en un entier
    QString role=ui->comboBox->currentText();

    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Employe Em(id,nom,prenom,email,num_tel,salaire,role);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =Em.modifierEmployes();

    bool test2;
    test2=(controleEmail(email)&&controleVide(nom)&&controleVide(prenom)&&controleVide(email)&&controleVideInt(num_tel)&&controleVideInt(salaire)&&controleVideInt(id) );

   if(test2){
    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(emp.afficherEmployes());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
   }

    else

    {

        QMessageBox::information(nullptr, QObject::tr("Modifier un employé "),
                                   QObject::tr("Employé non modifié, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


    }

}

void MainWindow::on_pushButtonSupprimer_clicked()
{
    int idA =ui->LeIdMS->text().toInt();
            bool test = emp.supprimerEmployes(idA);
            if(test)
            {
                //refresh affichage
                ui->tableView->setModel(emp.afficherEmployes());

                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),

     QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
     ui->tableView->setModel(emp.AfficherTrieCIN());
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->tableView->setModel(emp.AfficherTrieNom());
}

void MainWindow::on_LeIdRT_textChanged(const QString &arg1)
{
     ui->tableView->setModel(emp.rechercherCIN(arg1));
}

void MainWindow::on_LeTitreRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(emp.rechercherNom(arg1));
}

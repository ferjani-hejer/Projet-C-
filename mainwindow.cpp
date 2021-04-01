#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "historique.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(h.afficherHistorique());
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::on_pushButtonAjouter_clicked()
{
    //Récuprération des informations saisies dans les 3 champs

    int id=ui->LeId->text().toInt();
    int nbr_heures_trv=ui->lineEdit_3->text().toInt();

    QString Presence=ui->comboBox->currentText();
    QString tache=ui->lineEdit_2->text();
    QString cause=ui->lineEdit_6->text();

    QDateTime conge_debut=ui->dateEdit->dateTime();
    QDateTime conge_fin=ui->dateEdit_2->dateTime();


    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Historique H(id,Presence,tache,cause,conge_debut,conge_fin,nbr_heures_trv);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =H.ajouterHistorique();

    bool test2;
    test2=(controleVide(tache)&&controleVide(cause)&&controleVideInt(id)&&controleVideInt(nbr_heures_trv) );

  if(test2){
    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(h.afficherHistorique());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Ajout effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Ajout non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);
  }

  else

  {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un employe "),
                                 QObject::tr("Historique non ajouté, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


  }
}

void MainWindow::on_pushButtonModifier_clicked()
{
    //Récuprération des informations saisies dans les 3 champs


    int nbr_heures_trv=ui->lineEdit_3->text().toInt();

    QString Presence=ui->comboBox->currentText();
    QString tache=ui->lineEdit_2->text();
    QString cause=ui->lineEdit_6->text();

    QDateTime conge_debut=ui->dateEdit->dateTime();
    QDateTime conge_fin=ui->dateEdit_2->dateTime();


    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Historique H(id_h,Presence,tache,cause,conge_debut,conge_fin,nbr_heures_trv);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =H.modifierHistorique();

    bool test2;
    test2=(controleVide(tache)&&controleVide(cause)&&controleVideInt(id_h)&&controleVideInt(nbr_heures_trv) );

  if(test2){

    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(h.afficherHistorique());
        QMessageBox::information(nullptr,QObject::tr("ok"),
                QObject::tr("Modification effectué \n Click Cancel to exit."), QMessageBox::Cancel);
    }
    else //si requête non exécutée ==>QMessageBox::critical
        QMessageBox::critical(nullptr,QObject::tr("Not Ok"),
                              QObject::tr("Modification non effectué. \n ""Click Cancel to exit."),QMessageBox::Cancel);}

  else

  {

      QMessageBox::information(nullptr, QObject::tr("Ajouter un historique "),
                                 QObject::tr("Historique non modifié, vérifier les champs.\n""Click Cancel to exit."), QMessageBox::Cancel);


  }
}

void MainWindow::on_pushButtonSupprimer_clicked()
{

            bool test =h.supprimerHistorique(id_h);
            if(test)
            {
                //refresh affichage
                ui->tableView->setModel(h.afficherHistorique());

                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),

     QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
    ui->tableView->setModel(h.AfficherTrieID_H());
}

void MainWindow::on_pushButton_2_clicked()
{
     ui->tableView->setModel(h.AfficherTrieHeure());
}

void MainWindow::on_LeIdRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(h.rechercherID_H(arg1));
}

void MainWindow::on_LeTitreRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(h.rechercherPresences(arg1));
}


void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
                  QSqlQuery qry;
                  qry.prepare("select * from Historiques where"
                              " idh='"+val+"' or presences='"+val+"' or tache_realise='"+val+"' or debut_conge='"+val+"' or fin_conge ='"+val+"' or nbr_heures_trv ='"+val+"' or cause ='"+val+"'" );
                  if(qry.exec())
                    {while (qry.next())
                   {
                     ui->LeId->setText(qry.value(0).toString());
                     ui->comboBox->setCurrentText(qry.value(1).toString());
                     ui->lineEdit_2->setText(qry.value(2).toString());
                     ui->dateEdit->setDateTime(qry.value(3).toDateTime());
                     ui->dateEdit_2->setDateTime(qry.value(4).toDateTime());
                     ui->lineEdit_3->setText(qry.value(5).toString());
                     ui->lineEdit_6->setText(qry.value(6).toString());

                   }

                  }

}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
 id_h=ui->tableView->model()->data(index).toInt();
}

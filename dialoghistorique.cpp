#include "dialoghistorique.h"
#include "ui_dialoghistorique.h"
#include "historique.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include<QDebug>


Dialoghistorique::Dialoghistorique(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialoghistorique)
{
    ui->setupUi(this);
    ui->tableView->setModel(h.afficherHistorique());
    update_id();
}

Dialoghistorique::~Dialoghistorique()
{
    delete ui;
}
bool Dialoghistorique::controleVide(QString test)
{
    if(test!="")
        return  true;
    return false;

}

bool Dialoghistorique::controleVideInt(int test)
{
    if(test!=0)
        return  true;
    return false;

}

void Dialoghistorique::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT cinemp FROM employes");
       querry->exec();
       m->setQuery(*querry);
       ui->IDE->setModel(m);

}


void Dialoghistorique::on_pushButtonAjouter_clicked()
{
    //Récuprération des informations saisies dans les 3 champs

    int id=ui->LeId->text().toInt();
    int ide=ui->IDE->currentText().toInt();

    QString Presence=ui->comboBox->currentText();
    QString tache=ui->lineEdit_2->text();
    QString cause=ui->lineEdit_6->text();

    QDateTime conge_debut=ui->dateEdit->dateTime();
    QDateTime conge_fin=ui->dateEdit_2->dateTime();


    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Historique H(id,Presence,tache,cause,conge_debut,conge_fin,ide);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =H.ajouterHistorique();

    bool test2;
    test2=(controleVide(tache)&&controleVide(cause)&&controleVideInt(id)&&controleVideInt(ide));

    if(test2){
    if(test)//si requête executée ==>QMessageBox::information
    {

       //refresh affichage
        ui->tableView->setModel(h.afficherHistorique());
        update_id();
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

void Dialoghistorique::on_pushButtonModifier_clicked()
{
    //Récuprération des informations saisies dans les 3 champs

    int ide=ui->IDE->currentText().toInt();
    QString Presence=ui->comboBox->currentText();
    QString tache=ui->lineEdit_2->text();
    QString cause=ui->lineEdit_6->text();

    QDateTime conge_debut=ui->dateEdit->dateTime();
    QDateTime conge_fin=ui->dateEdit_2->dateTime();


    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Historique H(id_h,Presence,tache,cause,conge_debut,conge_fin,ide);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =H.modifierHistorique();

    bool test2;
    test2=(controleVide(tache)&&controleVide(cause)&&controleVideInt(id_h));

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


void Dialoghistorique::on_pushButtonSupprimer_clicked()
{

            bool test =h.supprimerHistorique(id_h);
            if(test)
            {
                //refresh affichage
                ui->tableView->setModel(h.afficherHistorique());
                update_id();
                QMessageBox::information(nullptr,QObject::tr("ok"),
                                         QObject::tr("suppression effectué \n ""Click Cancel to exit."),QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr,QObject::tr("not ok"),

     QObject::tr("suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);

}

void Dialoghistorique::on_pushButton_clicked()
{
    ui->tableView->setModel(h.AfficherTrieID_H());
}

void Dialoghistorique::on_pushButton_2_clicked()
{
     ui->tableView->setModel(h.AfficherTriePresence());
}

void Dialoghistorique::on_LeIdRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(h.rechercherID_H(arg1));
}

void Dialoghistorique::on_LeTitreRT_textChanged(const QString &arg1)
{
    ui->tableView->setModel(h.rechercherPresences(arg1));
}


void Dialoghistorique::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
                  QSqlQuery qry;
                  qry.prepare("select * from Historiques where"
                              " idh='"+val+"' or presences='"+val+"' or tache_realise='"+val+"' or cause ='"+val+"'" );
                  if(qry.exec())
                    {while (qry.next())
                   {
                     ui->LeId->setText(qry.value(0).toString());
                     ui->comboBox->setCurrentText(qry.value(1).toString());
                     ui->lineEdit_2->setText(qry.value(2).toString());
                     ui->dateEdit->setDateTime(qry.value(3).toDateTime());
                     ui->dateEdit_2->setDateTime(qry.value(4).toDateTime());
                     ui->lineEdit_6->setText(qry.value(6).toString());

                   }

                  }

}

void Dialoghistorique::on_tableView_clicked(const QModelIndex &index)
{

 id_h=ui->tableView->model()->data(index).toInt();

}

void Dialoghistorique::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tableView->setModel(h.rechercherID_E(arg1));
}

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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(emp.afficherEmployes());
    update_id();
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

void MainWindow::update_id()
{

       QSqlQueryModel *m=new QSqlQueryModel();
       QSqlQuery *querry=new QSqlQuery();
       querry->prepare("SELECT cinemp FROM employes");
       querry->exec();
       m->setQuery(*querry);

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

    QString nom=ui->LeTitre->text();
    QString prenom=ui->LeDescription->text();
    QString email=ui->Lemail->text();
    int num_tel=ui->lineEdit->text().toInt(); //convertir une chaine de caractére en un entier
    int salaire=ui->lineEdit_2->text().toInt(); //convertir une chaine de caractére en un entier
    QString role=ui->comboBox->currentText();

    //instancier un objet de la classe Etudiant en utilisant les informations saisies dans l interfaces
    Employe Em(id_emp,nom,prenom,email,num_tel,salaire,role);

    //insérer l'objet etudiant instancié dans la table etudiant et recuperer la valeur de retour de query.exec();
    bool test =Em.modifierEmployes();

    bool test2;
    test2=(controleEmail(email)&&controleVide(nom)&&controleVide(prenom)&&controleVide(email)&&controleVideInt(num_tel)&&controleVideInt(salaire)&&controleVideInt(id_emp) );

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
            bool test = emp.supprimerEmployes(id_emp);
            if(test)
            {
                //refresh affichage
                ui->tableView->setModel(emp.afficherEmployes());
                update_id();
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

void MainWindow::on_tableView_activated(const QModelIndex &index)
{
    QString val=ui->tableView->model()->data(index).toString();
          QSqlQuery qry;
          qry.prepare("select * from Employes where"
                      " cinemp='"+val+"' or nom='"+val+"' or prenom='"+val+"' or email='"+val+"' or num_tel ='"+val+"' or salaire='"+val+"' or role ='"+val+"' ");
          if(qry.exec())
            {while (qry.next())
           { ui->LeId->setText(qry.value(0).toString());
             ui->LeTitre->setText(qry.value(1).toString());
             ui->LeDescription->setText(qry.value(2).toString());
             ui->Lemail->setText(qry.value(3).toString());
             ui->lineEdit_3->setText(qry.value(4).toString());
             ui->lineEdit_2->setText(qry.value(5).toString());
             ui->comboBox->setCurrentText(qry.value(6).toString());

            }
        }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    id_emp=ui->tableView->model()->data(index).toInt();
}

void MainWindow::on_Impdos_2_clicked()
{
    Employe c;

             QString text=c.apercu_pdf();
             ui->imp->setText(text);

             QPrinter printer ;
             printer.setPrinterName("imprim");
             QPrintDialog dialog (&printer,this);
             if(dialog.exec()==QDialog::Rejected) return ;
             ui->imp->print(&printer);

}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
 ui->tableView->setModel(emp.rechercherS(arg1));
}

void MainWindow::on_pushButton_3_clicked()
{
 ui->tableView->setModel(emp.AfficherTrieS());
}

#include "employe.h"

#include<QSqlQuery>
#include<QDebug>

Employe::Employe()
{
        id=0;
        nom="";
        prenom="";
        email="";
        role="";
        salaire=0;
        num_tel=0;

}

Employe::Employe(int id ,QString nom,QString prenom,QString email,int num_tel,int salaire,QString role)
 {
     this->id=id;
     this->nom=nom;
     this->prenom=prenom;
     this->email=email;
     this->num_tel=num_tel;
     this->salaire=salaire;
     this->role=role;


 }


int Employe::getId()
 {
     return id;
 }

int Employe::getSalaire()
 {
     return salaire;
 }

int Employe::getNumTel()
 {
     return num_tel;
 }


QString Employe:: getNom(){

   return nom;
 }

QString Employe::getPrenom()
 {
       return prenom;
 }

QString Employe::getEmail()
 {
       return email;
 }

QString Employe::getRole()
 {
       return role;
 }


void Employe ::setId(int id)
{
    this->id=id;
}

void Employe ::setSalaire(int salaire)
{
    this->salaire=salaire;
}

void Employe ::setNumTel(int num_tel)
{
    this->num_tel=num_tel;
}

void Employe::setNom(QString nom)
{
    this->nom=nom;
}

void Employe::setPrenom(QString prenom){
    this->prenom=prenom;
}

void Employe::setRole(QString role){
    this->role=role;
}

void Employe::setEmail(QString email){
    this->email=email;
}


bool Employe::ajouterEmployes()
{
    QSqlQuery query;
    QString res1 = QString::number(id);
    QString res2 = QString::number(salaire);
    QString res3 = QString::number(num_tel);

    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into Employes(cinemp,nom,prenom,email,num_tel,salaire,role)""values(:id,:nom,:prenom,:email,:num_tel,:salaire,:role)");

    //Création des variables liées
    query.bindValue(":id",res1);
    query.bindValue(":salaire",res2);
    query.bindValue(":num_tel",res3);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email",email);
    query.bindValue(":role",role);

    return query.exec();//exec() envoie la requête pour l'exécution
}


QSqlQueryModel * Employe::afficherEmployes()
{

QSqlQueryModel * model=new QSqlQueryModel();
model->setQuery("select * from Employes");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("num_tel"));
model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
model->setHeaderData(6,Qt::Horizontal,QObject::tr("role"));
return model;

}


bool Employe::supprimerEmployes(int idA)
{
           QSqlQuery query;
           QString res=QString::number(idA);
           query.prepare("Delete from Employes where cinemp=:idA");
           query.bindValue(":idA",res);
           return query.exec();
}


bool Employe::modifierEmployes()
{
    QSqlQuery query ;
    QString res1 = QString::number(id);
    QString res2 = QString::number(salaire);
    QString res3 = QString::number(num_tel);
    query.prepare("UPDATE employes set cinemp = :id, nom = :nom,prenom = :prenom,email=:email,num_tel=:num_tel,salaire=:salaire,role=:role WHERE cinemp=:id");
    query.bindValue(":id",res1);
    query.bindValue(":salaire",res2);
    query.bindValue(":num_tel",res3);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":email",email);
    query.bindValue(":role",role);
    return query.exec();
}


QSqlQueryModel * Employe::AfficherTrieCIN()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employes ORDER BY cinemp");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("num_tel"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("role"));
    return model;
}

QSqlQueryModel * Employe::AfficherTrieNom()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM employes ORDER BY nom");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("num_tel"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("role"));
    return model;
}


QSqlQueryModel * Employe::rechercherCIN(QString cin)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from employes where cinemp like ?");
    q.addBindValue("%"+ cin +"%");
    q.exec();
    model->setQuery(q);
    return (model);
}

QSqlQueryModel * Employe::rechercherNom(QString nom)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from employes where nom like ?");
    q.addBindValue("%"+ nom +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

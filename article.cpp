#include "article.h"
#include<QSqlQuery>



Article::Article()
{
idA=0;
titre="";
description="";
auteur="";
}
 Article::Article(int idA,QString titre,QString description ,QString auteur,QDateTime dateA)
 {
     this->idA=idA;
     this->titre=titre;
     this->description=description;
     this->dateA=dateA;
     this->auteur=auteur;

 }

 int Article::getId()
     {
      return idA;
  }
 QString Article:: getTitre(){

    return titre;
  }
  QString Article::getDescription()
  {
        return description;
  }
  QDateTime Article:: getDateArticle(){

     return dateA;
   }
   QString Article::getAuteur()
   {
         return auteur;
   }


   void Article ::setId(int idA)
   {
       this->idA=idA;
   }
   void Article::setTitre(QString titre)
   {
       this->titre=titre;
   }
   void Article::setDescription(QString description){
       this->description=description;
   }
   void Article::setDateArticle(QDateTime dateA)
   {
       this->dateA=dateA;
   }
   void Article::setAuteur(QString auteur){
       this->auteur=auteur;
   }
   bool Article::ajouterArticle()
   {
       QSqlQuery query;
       QString res = QString::number(idA);
        //prepare() prend la requête en paramétre pour la préparer a l'exécution
       query.prepare("insert into Article(idA,titre,description,auteur,dateA)""values(:idA, :titre , :description, :auteur, :dateA)");

       //Création des variables liées
       query.bindValue(":idA",res);
       query.bindValue(":titre",titre);
       query.bindValue(":description",description);
       query.bindValue(":auteur",auteur);
       query.bindValue(":dateA",dateA);

       return query.exec();//exec() envoie la requête pour l'exécution
   }

    QSqlQueryModel * Article::afficherIDArticle()
    {
         QSqlQueryModel * model=new QSqlQueryModel();
         model->setQuery("select idA from Article");
         return model;
    }

   QSqlQueryModel * Article::afficherArticle()
   {
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("select * from Article");
   model->setHeaderData(0,Qt::Horizontal,QObject::tr("idA"));
   model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
   model->setHeaderData(2,Qt::Horizontal,QObject::tr("description"));
   model->setHeaderData(3,Qt::Horizontal,QObject::tr("auteur"));
   model->setHeaderData(4,Qt::Horizontal,QObject::tr("dateA"));
   return model;
   }

   bool Article::supprimerArticle(int idA)
   {
       QSqlQuery query;
       QString res=QString::number(idA);
       query.prepare("Delete from Article where idA=:idA");
       query.bindValue(":idA",res);
       return query.exec();
   }
    bool Article::modifierArticle(int idA)
    {
        QSqlQuery query;
        query.prepare("UPDATE Article SET idA=:idA, titre=:titre, description=:description , auteur=:auteur , dateA=:dateA WHERE idA=:idA");
        query.bindValue(":idA", idA);
        query.bindValue(":titre", titre);
        query.bindValue(":description", description);
        query.bindValue(":auteur", auteur);
        query.bindValue(":dateA", dateA);
        return    query.exec();
    }

    QSqlQueryModel * Article::rechercherIDA(QString idA)
    {
        QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery q;
        q.prepare("select * from Article where idA like ?");
        q.addBindValue("%"+ idA +"%");
        q.exec();
        model->setQuery(q);
        return (model);
    }

    QSqlQueryModel * Article::rechercherTitre(QString titre)
    {
        QSqlQueryModel *model= new QSqlQueryModel();
        QSqlQuery q;
        q.prepare("select * from Article where titre like ?");
        q.addBindValue("%"+ titre +"%");
        q.exec();
        model->setQuery(q);
        return (model);

    }

    QSqlQueryModel * Article::AfficherTrieIdA()
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM Article ORDER BY idA");

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("idA"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("description"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("auteur"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("dateA"));
        return model;
    }
    QSqlQueryModel * Article::AfficherTrieTitre()
    {
        QSqlQueryModel * model = new QSqlQueryModel();
        model->setQuery("SELECT * FROM Article ORDER BY titre");

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("idA"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("description"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("auteur"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("dateA"));
        return model;
    }

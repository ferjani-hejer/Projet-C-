#include "reportage.h"

Reportage::Reportage()
{
    idA=0;
     titre="";
     realisateur="";
     categorie="";

}

Reportage::Reportage(int idA,QString titre,QString realisateur,QDateTime dateR,QString categorie)
{
     this->idA=idA;
     this->titre=titre;
     this->realisateur=realisateur;
     this->dateR=dateR;
     this->categorie=categorie;
}
int Reportage:: getId(){
     return idA;
}
QString Reportage::getTitre(){
    return titre;
}

QString Reportage:: getRealisateur()
{
    return realisateur;

}
QDateTime Reportage:: getDateR(){
    return dateR;
}
QString Reportage::getCategorie(){
    return categorie;

}
void Reportage ::setId(int idA)
   {
       this->idA=idA;
   }
   void Reportage::setTitre(QString titre)
   {
       this->titre=titre;
   }

   void Reportage::setRealisateur(QString realisateur)
   {
       this->realisateur=realisateur;
   }
   void Reportage::setDateR(QDateTime dateR){
       this->dateR=dateR;
   }
   void Reportage::setCategorie(QString categorie){
       this->categorie=categorie;
   }


   bool Reportage::ajouterReportage()
     {
         QSqlQuery query;
         QString res = QString::number(idA);
          //prepare() prend la requête en paramétre pour la préparer a l'exécution
         query.prepare("insert into Reportage(idA,titre,realisateur,dateR,categorie)""values(:idA, :titre , :realisateur, :dateR, :categorie)");

         //Création des variables liées
         query.bindValue(":idA",res);
         query.bindValue(":titre",titre);
         query.bindValue(":realisateur",realisateur);
         query.bindValue(":dateR",dateR);
         query.bindValue(":categorie",categorie);
         return query.exec();//exec() envoie la requête pour l'exécution
     }
   QSqlQueryModel * Reportage::afficherReportage()
     {
     QSqlQueryModel * model=new QSqlQueryModel();
     model->setQuery("select * from Reportage");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("idA"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("realisateur"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("dateR"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));
     return model;
     }
   bool Reportage::supprimerReportage(int idA)
     {
         QSqlQuery query;
         QString res=QString::number(idA);
         query.prepare("Delete from Reportage where idA=:idA");
         query.bindValue(":idA",res);
         return query.exec();
     }
   bool Reportage::modifierReportage(int idA)
   {
       QSqlQuery query;
       query.prepare("UPDATE Reportage SET idA=:idA, titre=:titre, realisateur=:realisateur , dateR=:dateR , categorie=:categorie WHERE idA=:idA");
       query.bindValue(":idA", idA);
       query.bindValue(":titre", titre);
       query.bindValue(":realisateur",realisateur);
       query.bindValue(":dateR", dateR);
       query.bindValue(":categorie", categorie);
       return    query.exec();
   }
 QSqlQueryModel * Reportage::rechercherIDA(QString idA)
 {
     QSqlQueryModel *model= new QSqlQueryModel();
     QSqlQuery q;
     q.prepare("select * from Reportage where idA like ?");
     q.addBindValue("%"+ idA +"%");
     q.exec();
     model->setQuery(q);
     return (model);
 }
 QSqlQueryModel * Reportage::rechercherCategorie(QString titre)
 {
     QSqlQueryModel *model= new QSqlQueryModel();
     QSqlQuery q;
     q.prepare("select * from Reportage where titre like ?");
     q.addBindValue("%"+ titre +"%");
     q.exec();
     model->setQuery(q);
     return (model);
 }
 QSqlQueryModel * Reportage::AfficherTrieIdA()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM Reportage ORDER BY idA");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("idA"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("realisateur"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("dateR"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));
     return model;
 }
 QSqlQueryModel * Reportage::AfficherTrieCategorie()
 {
     QSqlQueryModel * model = new QSqlQueryModel();
     model->setQuery("SELECT * FROM Reportage ORDER BY titre");
     model->setHeaderData(0,Qt::Horizontal,QObject::tr("idA"));
     model->setHeaderData(1,Qt::Horizontal,QObject::tr("titre"));
     model->setHeaderData(2,Qt::Horizontal,QObject::tr("realisateur"));
     model->setHeaderData(3,Qt::Horizontal,QObject::tr("dateR"));
     model->setHeaderData(4,Qt::Horizontal,QObject::tr("categorie"));
     return model;
 }

#ifndef REPORTAGE_H
#define REPORTAGE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>
#include<QDateTime>



class Reportage
{
public:
    Reportage();
    Reportage(int,QString,QString,QDateTime,QString);
    //getters
          int getId();
          QString getTitre();
          QString getRealisateur();
          QDateTime getDateR();
          QString getCategorie();
          //Setters
          void setId(int);
          void setTitre(QString);
          void setRealisateur(QString);
          void setDateR(QDateTime);
          void setCategorie(QString);

          bool ajouterReportage();
          QSqlQueryModel * afficherReportage();
          bool supprimerReportage(int);

          bool modifierReportage(int);

          QSqlQueryModel * afficherIDReportage();

          QSqlQueryModel * AfficherTrieIdA();
          QSqlQueryModel * AfficherTrieCategorie();

          QSqlQueryModel * rechercherIDA(QString);
          QSqlQueryModel * rechercherCategorie(QString);


private:

          int idA;
          QString titre,realisateur,categorie;
          QDateTime dateR;
};

#endif // REPORTAGE_H

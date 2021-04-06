#ifndef HISTORIQUE_H
#define HISTORIQUE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class Historique
{
public:
    Historique();
    Historique(int,QString,QString,QString,QDateTime,QDateTime,int);

    //getters
    int getId_H();
    int getId_E();
    QString getPresence();
    QString getTache();
    QString getCause();
    QDateTime getConge_debut();
    QDateTime getConge_fin();

    //Setters
    void setId_H(int);
    void setId_E(int);
    void setPresence(QString);
    void setTache(QString);
    void setCause(QString);
    void setConge_debut(QDateTime);
    void setConge_fin(QDateTime);


    bool ajouterHistorique();
    QSqlQueryModel * afficherHistorique();
    bool supprimerHistorique(int);
    bool modifierHistorique();


    QSqlQueryModel * AfficherTrieID_H();
    QSqlQueryModel * AfficherTrieID_E();
    QSqlQueryModel * AfficherTriePresence();

    QSqlQueryModel * rechercherID_H(QString);
    QSqlQueryModel * rechercherID_E(QString);
    QSqlQueryModel * rechercherPresences(QString);

private:
    int IDH,IDE;
    QString Presence,tache,cause ;
    QDateTime conge_debut,conge_fin;

};

#endif // HISTORIQUE_H

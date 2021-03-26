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
    QString getPresence();
    QString getTache();
    QString getCause();
    QDateTime getConge_debut();
    QDateTime getConge_fin();
    int getNbr_heure_travail();

    //Setters
    void setId_H(int);
    void setPresence(QString);
    void setTache(QString);
    void setCause(QString);
    void setConge_debut(QDateTime);
    void setConge_fin(QDateTime);
    void setNbr_Heure_travail(int);


    bool ajouterHistorique();
    QSqlQueryModel * afficherHistorique();
    bool supprimerHistorique(int);
    bool modifierHistorique();


    QSqlQueryModel * AfficherTrieID_H();
    QSqlQueryModel * AfficherTrieHeure();

    QSqlQueryModel * rechercherID_H(QString);
    QSqlQueryModel * rechercherPresences(QString);

private:
    int IDH,Nbr_heure_travail;
    QString Presence,tache,cause ;
    QDateTime conge_debut,conge_fin;

};

#endif // HISTORIQUE_H

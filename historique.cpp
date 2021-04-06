#include "historique.h"

Historique::Historique()
{
    IDH=0;
    Presence="XX";
    tache="XX" ;
    cause="XX";

}

Historique::Historique(int idA ,QString pr,QString tache ,QString cause,QDateTime c_debut,QDateTime c_fin,int idE)
{
    this->IDH=idA;
    this->Presence=pr;
    this->tache=tache;
    this->conge_debut=c_debut;
    this->conge_fin=c_fin;
    this->cause=cause;
    this->IDE=idE;
}

int Historique::getId_H()
{
    return IDH;
}

int Historique::getId_E()
{
    return IDE;
}

QString Historique::getCause()
{
    return cause;
}

QString Historique::getPresence()
{
    return Presence;
}

QString Historique::getTache()
{
    return tache;
}


QDateTime Historique::getConge_debut()
{
   return conge_debut;
}

QDateTime Historique::getConge_fin()
{
  return conge_fin;
}


void Historique::setConge_debut(QDateTime dateA)
{
    this->conge_debut=dateA;
}

void Historique::setConge_fin(QDateTime dateA)
{
    this->conge_fin=dateA;
}

void Historique::setId_H(int id)
{
    this->IDH=id;
}

void Historique::setId_E(int id)
{
    this->IDH=id;
}

void Historique::setPresence(QString Pr)
{
    this->Presence = Pr;
}

void Historique::setTache(QString tache)
{
    this->tache=tache;
}

void Historique::setCause(QString cause)
{
    this->cause=cause;
}

bool Historique::ajouterHistorique()
{

    QSqlQuery query;
    QString res = QString::number(IDH);
    QString res3 = QString::number(IDE);
    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into Historiques(idh,presences,tache_realise,debut_conge,fin_conge,cause,cinemp)""values(:IDH,:Presence,:tache,:debut_conge,:fin_conge,:cause,:IDE)");

    //Création des variables liées
    query.bindValue(":IDH",res);
    query.bindValue(":Presence",Presence);
    query.bindValue(":tache",tache);
    query.bindValue(":cause",cause);
    query.bindValue(":debut_conge",conge_debut);
    query.bindValue(":fin_conge",conge_fin);
    query.bindValue(":IDE",res3);

    return query.exec();//exec() envoie la requête pour l'exécution

}

QSqlQueryModel * Historique::afficherHistorique()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Historiques");
    return model;
}


bool Historique:: supprimerHistorique(int idA)
{
    QSqlQuery query;
    QString res=QString::number(idA);
    query.prepare("Delete from Historiques where IDH=:idA");
    query.bindValue(":idA",res);
    return query.exec();

}

bool Historique::modifierHistorique()
{
    QSqlQuery query ;
    QString res = QString::number(IDH);
    query.prepare("UPDATE Historiques set idh = :IDH,  presences= :presence,tache_realise = :tache,debut_conge=:debut_conge,fin_conge=:fin_conge,cause=:cause WHERE idh=:IDH");

    //Création des variables liées
    query.bindValue(":IDH",res);
    query.bindValue(":presence",Presence);
    query.bindValue(":tache",tache);
    query.bindValue(":debut_conge",conge_debut);
    query.bindValue(":fin_conge",conge_fin);
    query.bindValue(":cause",cause);

    return query.exec();//exec() envoie la requête pour l'exécution
}

QSqlQueryModel * Historique :: AfficherTrieID_H()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Historiques ORDER BY idh");
    return model;
}


QSqlQueryModel * Historique :: AfficherTrieID_E()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Historiques ORDER BY cinemp");
    return model;

}

QSqlQueryModel * Historique:: AfficherTriePresence()
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM Historiques ORDER BY presences");
    return model;
}


QSqlQueryModel *Historique:: rechercherID_H(QString id)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from Historiques where idh like ?");
    q.addBindValue("%"+ id +"%");
    q.exec();
    model->setQuery(q);
    return (model);


}

QSqlQueryModel *Historique:: rechercherID_E(QString id)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from Historiques where cinemp like ?");
    q.addBindValue("%"+ id +"%");
    q.exec();
    model->setQuery(q);
    return (model);


}


QSqlQueryModel *Historique:: rechercherPresences(QString tch)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery q;
    q.prepare("select * from Historiques where presences like ?");
    q.addBindValue("%"+ tch +"%");
    q.exec();
    model->setQuery(q);
    return (model);

}

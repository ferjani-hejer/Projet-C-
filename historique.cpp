#include "historique.h"

Historique::Historique()
{
    IDH=0;
    Nbr_heure_travail=0;
    Presence="";
    tache="" ;
    cause="";

}

Historique::Historique(int idA ,QString pr,QString tache ,QString cause,QDateTime c_debut,QDateTime c_fin,int nbr_heure)
{
    this->IDH=idA;
    this->Presence=pr;
    this->tache=tache;
    this->conge_debut=c_debut;
    this->conge_fin=c_fin;
    this->Nbr_heure_travail=nbr_heure;
    this->cause=cause;
}

int Historique::getId_H()
{
    return IDH;
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

int Historique::getNbr_heure_travail()
{
    return Nbr_heure_travail;
}


void Historique::setConge_debut(QDateTime dateA)
{
    this->conge_debut=dateA;
}

void Historique::setConge_fin(QDateTime dateA)
{
    this->conge_fin=dateA;
}

void Historique::setNbr_Heure_travail(int dateA)
{
    this->Nbr_heure_travail=dateA;
}

void Historique::setId_H(int id)
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
    QString res2 = QString::number(Nbr_heure_travail);
    //prepare() prend la requête en paramétre pour la préparer a l'exécution
    query.prepare("insert into Historiques(idh,presences,tache_realise,debut_conge,fin_conge,nbr_heures_trv,cause)""values(:IDH,:Presence,:tache,:debut_conge,:fin_conge,:Nbr_heure_travail,:cause)");

    //Création des variables liées
    query.bindValue(":IDH",res);
    query.bindValue(":Presence",Presence);
    query.bindValue(":tache",tache);
    query.bindValue(":cause",cause);
    query.bindValue(":debut_conge",conge_debut);
    query.bindValue(":fin_conge",conge_fin);
    query.bindValue(":Nbr_heure_travail",res2);

    return query.exec();//exec() envoie la requête pour l'exécution

}

QSqlQueryModel * Historique::afficherHistorique()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from Historiques");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDH"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Presence"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("tache"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("debut_conge"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("fin_conge"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nbr_heure_travail"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("cause"));
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
    query.prepare("UPDATE Historiques set idh = :IDH,  presences= :presence,tache_realise = :tache,debut_conge=:debut_conge,fin_conge=:fin_conge,nbr_heures_trv=:Nbr_heures_travail,cause=:cause WHERE idh=:IDH");

    //Création des variables liées
    query.bindValue(":IDH",res);
    query.bindValue(":presence",Presence);
    query.bindValue(":tache",tache);
    query.bindValue(":debut_conge",conge_debut);
    query.bindValue(":fin_conge",conge_fin);
    query.bindValue(":Nbr_heures_travail",Nbr_heure_travail);
    query.bindValue(":cause",cause);
    return query.exec();//exec() envoie la requête pour l'exécution
}

QSqlQueryModel * Historique :: AfficherTrieID_H()
{
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Historiques ORDER BY idh");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDH"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Presence"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("tache"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("debut_congé"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("fin_congé"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nbr_heure_travail"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Cause"));
    return model;

}

QSqlQueryModel * Historique:: AfficherTrieHeure()
{

    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM Historiques ORDER BY nbr_heures_trv");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDH"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Presence"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("tache"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("debut_congé"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("fin_congé"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("Nbr_heure_travail"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("Cause"));
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

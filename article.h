#ifndef ARTICLE_H
#define ARTICLE_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QDate>

class Article
{
public:
    Article();
    Article(int,QString,QString,QString,QDateTime);
        //getters
        int getId();
        QString getTitre();
        QString getAuteur();
        QString getDescription();
        QDateTime getDateArticle();
        //Setters
        void setId(int);
        void setTitre(QString);
        void setAuteur(QString);
        void setDescription(QString);
        void setDateArticle(QDateTime);

        bool ajouterArticle();
        QSqlQueryModel * afficherArticle();
        bool supprimerArticle(int);
        bool modifierArticle(int);

        QSqlQueryModel * afficherIDArticle();

        QSqlQueryModel * AfficherTrieIdA();
        QSqlQueryModel * AfficherTrieTitre();

        QSqlQueryModel * rechercherIDA(QString);
        QSqlQueryModel * rechercherTitre(QString);




private:
    int idA;
    QString titre,description,image,auteur;
    QDateTime dateA;


};

#endif // ARTICLE_H

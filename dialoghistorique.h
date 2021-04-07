#ifndef DIALOGHISTORIQUE_H
#define DIALOGHISTORIQUE_H
#include <QDialog>
#include "historique.h"
#include <QMediaPlayer>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include<QSound>

namespace Ui {
class Dialoghistorique;
}

class Dialoghistorique : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoghistorique(QWidget *parent = nullptr);
    ~Dialoghistorique();

    void update_id();

private slots:
    bool controleVide(QString test);

    bool controleVideInt(int test);

    void on_pushButtonAjouter_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_LeTitreRT_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Dialoghistorique *ui;
    Historique h;
    int id_h=0;
    QMediaPlayer*	player;
};

#endif // DIALOGHISTORIQUE_H

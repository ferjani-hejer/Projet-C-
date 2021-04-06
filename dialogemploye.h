#ifndef DIALOGEMPLOYE_H
#define DIALOGEMPLOYE_H
#include "employe.h"
#include <QDialog>

namespace Ui {
class Dialogemploye;
}

class Dialogemploye : public QDialog
{
    Q_OBJECT

public:
    explicit Dialogemploye(QWidget *parent = nullptr);
    ~Dialogemploye();
    void update_id();

private slots:


    bool controleNumTel(int test);

    bool controleVide(QString test);

    bool controleVideInt(int test);

    bool controleEmail(QString test);

    void on_pushButtonAjouter_clicked();

    void on_pushButtonModifier_clicked();

    void on_pushButtonSupprimer_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_LeIdRT_textChanged(const QString &arg1);

    void on_LeTitreRT_textChanged(const QString &arg1);

    void on_tableView_activated(const QModelIndex &index);

    void on_tableView_clicked(const QModelIndex &index);

    void on_Impdos_2_clicked();

    void on_lineEdit_3_textChanged(const QString &arg1);

    void on_pushButton_3_clicked();

private:
    Ui::Dialogemploye *ui;
    Employe emp;
    int id_emp=0;
};

#endif // DIALOGEMPLOYE_H

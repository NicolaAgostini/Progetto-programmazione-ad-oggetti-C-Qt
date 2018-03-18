#ifndef FINESTRALISTAUTENTI_H
#define FINESTRALISTAUTENTI_H

#include"admin.h"
#include"moderatore.h"
#include"premium.h"
#include"utentestd.h"
#include"utente.h"
#include"listautenti.h"
#include <QVBoxLayout>
#include <QListWidget>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QFormLayout>
#include <QInputDialog>
#include <QComboBox>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include<QRadioButton>

class finestralistautenti:public QVBoxLayout{
    Q_OBJECT
private:

    bool utenterifiutato;

    QDialog* scrivi;
    QRadioButton* radio1;
 QRadioButton* radio2;
 QRadioButton* radio3;
QRadioButton* radio4;

   QVBoxLayout* vert;

   QPushButton*  okvai;
   QPushButton* annulla;

    QLineEdit* insenome;
    QLineEdit* insepass;

    listautenti & lista;
    QLabel* etichetta;
    QListWidget* listawidget;
    QLabel* etichettaricerca;
    QLineEdit* cerca;

    void refresh();
    void filtralista();

public:
    finestralistautenti(listautenti& lista, QWidget * p =0 );

public slots:
    void annullainserimento();
    void ricaricalista();
    void scartalista();
    void aggiungiute();
    void banna();
    void cambiapassword();

signals:
    void attivo();//riattivo i pulsanti
};


#endif // FINESTRALISTAUTENTI_H

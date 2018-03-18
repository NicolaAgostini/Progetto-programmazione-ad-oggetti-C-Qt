#ifndef FINESTRACANI_H
#define FINESTRACANI_H

#include"cani.h"
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QFormLayout>
#include <QMessageBox>
#include <QLineEdit>


class finestracani:public QWidget{//classe virtuale pura

    Q_OBJECT
public://tutto pubblico perchè poi riutilizzo per le sottoclassi
    cani* m;//unico campo dati
    virtual ~finestracani()=0;
    finestracani(cani*,QWidget* =0);
    QFormLayout *l;
    QPushButton* conferma;
    QPushButton* annulla;
    QLineEdit* anno;
    QLineEdit* peso;
    QLineEdit* nome;
    QLineEdit* proprietario;
    QLineEdit* razza;
    QLineEdit* colore;
    QLineEdit* codicepedigree;
    virtual bool controllasenzaerr();
    void costruttore();//costruisce il widget
   virtual void modificacampi()const;//per estenderlo anche per i sottotipi che aumentano i campi dati ovviamente
    virtual bool controlla()const;//controlla se i campi sono inseriti
    virtual void construisciline();//costruisce la lineedit
    virtual void costruiscibutton();//costruisce i qpushbuttons
public slots:
        void aggiorna();//se premi il button conferma aggiorna le info
        void tornaindietro();//se premi il button annulla tornaindietro
signals:
        void tuttook();//segnale ok
        void annullaok();//segnale torna indietro del pulsante







};

#endif

#ifndef PRINCIPALE_H
#define PRINCIPALE_H

#include <QLabel>
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QListWidget>
#include <QScrollArea>



#include <QRadioButton>
#include"listacani.h"
#include"cani.h"
#include"gestoreadmin.h"
#include"aggiungeremodificare.h"

#include"finestramostrasoggetto.h"

class principale:public QWidget{
    Q_OBJECT
private:
    QDialog* scrivi;
    QRadioButton* radio1;
QRadioButton* radio2;
QRadioButton* radio3;
QRadioButton* radio4;
QRadioButton* radio5;
    QVBoxLayout * vert;

    QPushButton* okvai;
    QGridLayout* griglia;
    listacani lelemento;
    listautenti& lutente;
    utente* user;
    QPushButton* baggiungi;
    QPushButton* bmodifica;
    QPushButton* berase;
    QPushButton* badmin;
    QPushButton* bordnome;
    QPushButton* borddimensione;
    QPushButton* Orddurata;
    QPushButton* bottieniinfo;
    gestoreadmin* gestore;
    QListWidget* lista;
    QLabel* aggiornamento;
    QScrollArea* finestraaggiornamento;
    QLineEdit* trova;


    QLabel* labeltrova;
   QLabel* media;

    void aggiorna();

        void finestraricerca();
        void mostrainformazioni();
        void tornaallinizio();

        void media_anni();



signals:

         void cambiamessaggio(QString);

private slots:
         void informazioni();

         void ricaricaberase();
         void ricaricabmodifica();
         void eraseelement();
         void modificare();
             void aggiungere();
             void aggiornaricerca();
             void ordinasulnome();
             void ordinasullanno();
            void ordinasulpeso();
             void mostrainfo();
             void ricaricabottieniinfo();


public:
             principale(listautenti&,utente*,QWidget* =0);



};

#endif // PRINCIPALE_H

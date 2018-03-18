#ifndef AGGIUNGEREMODIFICARE_H
#define AGGIUNGEREMODIFICARE_H
#include"finestracani.h"
#include"cani.h"
#include<QFormLayout>
#include<QMessageBox>

#include"finestrapoliziotto.h"
#include"finestrabestiame.h"
#include"finestraguida.h"
#include"finestrasport.h"
#include"finestracaccia.h"

#include"poliziotto.h"
#include"bestiame.h"
#include"guida.h"
#include"sport.h"
#include"caccia.h"

class aggiungeremodificare:public QDialog{//è la classe che mi permette di modificare o costruire un oggetto
    Q_OBJECT
private:
    cani* a;
    QFormLayout* l;
finestracani* fm;
    bool& e;
public:
    aggiungeremodificare(cani*,bool&,QWidget* =0);//solo il costruttore che si occupa di tutto lui

    finestracani* ritornapuntatore(cani*);//mi ritorna un puntatore con TD l'oggetto con cui chiamo ed è essenziale per capire se è un oggetto valido e per costruire le finestre dai soggetti

public slots:
    void prova();


};


#endif // AGGIUNGEREMODIFICARE_H

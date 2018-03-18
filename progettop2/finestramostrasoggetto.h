#ifndef FINESTRAMOSTRASOGGETTO_H
#define FINESTRAMOSTRASOGGETTO_H

#include<QWidget>
#include<QGridLayout>
#include"cani.h"
#include<QLabel>
#include<QDialog>
#include"mostracani.h"

#include"mostrapoliziotto.h"
#include"mostrabestiame.h"
#include"mostraguida.h"
#include"mostrasport.h"
#include"mostracaccia.h"


class finestramostrasoggetto:public QDialog{

private:
    cani* mostra;
    QGridLayout* disposizione;
public:
    finestramostrasoggetto(cani*,QWidget* =0);
    mostracani* ritornapuntatore(cani*);
};

#endif // finestramostrasoggetto_H

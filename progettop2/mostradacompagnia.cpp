#include"mostradacompagnia.h"


mostradacompagnia::mostradacompagnia(cani* k,QWidget* p):mostracani(k,p){}

void mostradacompagnia::construisciline(){

    mostracani::construisciline();
   dacompagnia *b=static_cast<dacompagnia*>(mu);
    mic=new QLabel();
    nex=new QLabel();
    mic->setText("Microcip: " +QString::number(b->getmicrocip()));
    nex->setText("ID expo: "+QString::number(b->getnexpo()));

    l->addWidget(mic);
    l->addWidget(nex);
}

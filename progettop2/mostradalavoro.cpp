#include"mostradalavoro.h"


mostradalavoro::mostradalavoro(cani* k,QWidget* p):mostracani(k,p){}

void mostradalavoro::construisciline(){

    mostracani::construisciline();
    dalavoro *b=static_cast<dalavoro*>(mu);
    cod=new QLabel();
    cod->setText("Codice identificativo:" +QString::number(b->getcodident()));
    l->addWidget(cod);
}

#include"mostraguida.h"

mostraguida::mostraguida(cani* k,QWidget* p):mostradalavoro(k,p){}

void mostraguida::construisciline(){

    mostradalavoro::construisciline();
    guida *b=dynamic_cast<guida*>(mu);
    nomeip=new QLabel();
    nomeip->setText("Persona a cui è assegnato: "+QString::fromStdString(b->getnomeipovedente()));
    l->addWidget(nomeip);
}

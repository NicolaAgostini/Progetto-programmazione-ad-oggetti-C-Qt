#include"mostrasport.h"

mostrasport::mostrasport(cani* k,QWidget* p):mostradacompagnia(k,p){}

void mostrasport::construisciline(){

    mostradacompagnia::construisciline();
   sport *b=dynamic_cast<sport*>(mu);
   tip=new QLabel();
   squ=new QLabel();
   tip->setText("Sport: " +QString::fromStdString(b->gettiposport()));
   squ->setText("Club a cui è iscritto: "+QString::fromStdString(b->getsquadra()));

   l->addWidget(tip);
   l->addWidget(squ);
}

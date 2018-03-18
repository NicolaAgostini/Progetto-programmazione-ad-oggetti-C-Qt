#include"mostrabestiame.h"



mostrabestiame::mostrabestiame(cani* w,QWidget* p):mostradalavoro(w,p){}

 void mostrabestiame::construisciline(){
     mostradalavoro::construisciline();
     bestiame *b=dynamic_cast<bestiame*>(mu);
     gre=new QLabel();
     gre->setText("Gregge: "+QString::fromStdString(b->getcodgregge()));
     l->addWidget(gre);
 }

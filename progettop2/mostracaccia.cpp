#include"mostracaccia.h"


mostracaccia::mostracaccia(cani* k,QWidget* p):mostradacompagnia(k,p){}

void mostracaccia::construisciline(){

    mostradacompagnia::construisciline();
   caccia *b=dynamic_cast<caccia*>(mu);
   passa=new QLabel();

   passa->setText("Codice permesso di caccia: " +QString::fromStdString(b->getpassaportocaccia()));


   l->addWidget(passa);

}

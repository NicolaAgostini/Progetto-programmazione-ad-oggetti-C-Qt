#include"mostrapoliziotto.h"


mostrapoliziotto::mostrapoliziotto(cani* k,QWidget* p):mostradalavoro(k,p){}

void mostrapoliziotto::construisciline(){

    mostradalavoro::construisciline();
    poliziotto *b=dynamic_cast<poliziotto*>(mu);
    nu=new QLabel();
    nu->setText("Nucleo Operativo: "+QString::fromStdString(b->getnucleooperativo()));
    l->addWidget(nu);
}

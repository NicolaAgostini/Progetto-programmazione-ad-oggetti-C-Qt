#ifndef MOSTRABESTIAME_H
#define MOSTRABESTIAME_H

#include"bestiame.h"
#include"mostradalavoro.h"

class mostrabestiame:public mostradalavoro{
private:
    QLabel* gre;
public:
    mostrabestiame(cani* ,QWidget* =0);
     void construisciline();
};

#endif

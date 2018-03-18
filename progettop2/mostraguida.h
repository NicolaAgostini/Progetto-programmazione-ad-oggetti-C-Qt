#ifndef MOSTRAGUIDA_H
#define MOSTRAGUIDA_H

#include"guida.h"
#include"mostradalavoro.h"

class mostraguida:public mostradalavoro{
private:
    QLabel* nomeip;
public:
    mostraguida(cani* ,QWidget* =0);
     void construisciline();
};

#endif

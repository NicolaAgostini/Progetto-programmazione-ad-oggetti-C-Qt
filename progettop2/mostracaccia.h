#ifndef MOSTRACACCIA_H
#define MOSTRACACCIA_H

#include"caccia.h"
#include"mostradacompagnia.h"

class mostracaccia:public mostradacompagnia{
private:
    QLabel* passa;

public:
    mostracaccia(cani* ,QWidget* =0);
     void construisciline();
};

#endif

#ifndef MOSTRASPORT_H
#define MOSTRASPORT_H

#include"sport.h"
#include"mostradacompagnia.h"

class mostrasport:public mostradacompagnia{
private:
    QLabel* tip;
    QLabel* squ;
public:
    mostrasport(cani* ,QWidget* =0);
     void construisciline();
};

#endif

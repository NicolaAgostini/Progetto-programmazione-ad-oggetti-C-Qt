#ifndef MOSTRADACOMPAGNIA_H
#define MOSTRADACOMPAGNIA_H

#include"mostracani.h"
#include"dacompagnia.h"


class mostradacompagnia:public mostracani{
private:
    QLabel* mic;
    QLabel* nex;
public:
    mostradacompagnia(cani* ,QWidget* =0);
    virtual void construisciline();
};

#endif

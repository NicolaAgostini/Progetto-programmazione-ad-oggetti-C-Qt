#ifndef MOSTRADALAVORO_H
#define MOSTRADALAVORO_H

#include"mostracani.h"
#include"dalavoro.h"


class mostradalavoro:public mostracani{
private:
    QLabel* cod;
public:
    mostradalavoro(cani* ,QWidget* =0);
    virtual void construisciline();
};

#endif

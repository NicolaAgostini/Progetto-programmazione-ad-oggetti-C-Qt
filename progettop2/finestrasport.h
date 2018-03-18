#ifndef FINESTRASPORT_H
#define FINESTRASPORT_H
#include<QLineEdit>
#include"sport.h"
#include"finestradacompagnia.h"

class finestrasport:public finestradacompagnia{
private:
    QLineEdit* tiposport;
    QLineEdit* squadra;
public:
    finestrasport(cani*,QWidget * =0);
    virtual void modificacampi()const;
    virtual void construisciline();
    virtual bool controlla()const;
    virtual bool controllasenzaerr();
};

#endif

#ifndef FINESTRADACOMPAGNIA_H
#define FINESTRADACOMPAGNIA_H
#include<QLineEdit>
#include"finestracani.h"
#include "dacompagnia.h"
#include<QString>

class finestradacompagnia:public finestracani{

private:
    QLineEdit* microcip;
    QLineEdit* nexpo;
public:
    finestradacompagnia(cani*,QWidget * =0);
    virtual ~finestradacompagnia() =0;
virtual void construisciline();
    virtual void modificacampi()const;
    virtual bool controlla()const;
    virtual bool controllasenzaerr();

};

#endif

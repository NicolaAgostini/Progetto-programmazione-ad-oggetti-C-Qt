#ifndef FINESTRACACCIA_H
#define FINESTRACACCIA_H
#include<QLineEdit>
#include"caccia.h"
#include"finestradacompagnia.h"

class finestracaccia:public finestradacompagnia{
private:
    QLineEdit* passaportocaccia;
public:
    finestracaccia(cani*,QWidget * =0);
    virtual void modificacampi()const;
    virtual void construisciline();
    virtual bool controlla()const;
    virtual bool controllasenzaerr();
};

#endif

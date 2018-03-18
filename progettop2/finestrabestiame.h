#ifndef FINESTRABESTIAME_H
#define FINESTRABESTIAME_H
#include<QLineEdit>
#include"finestradalavoro.h"
#include"bestiame.h"

class finestrabestiame:public finestradalavoro{
private:
    QLineEdit* codgregge;
public:
    finestrabestiame(cani*,QWidget * =0);
    virtual void modificacampi()const;
    virtual void construisciline();
    virtual bool controlla()const;
    virtual bool controllasenzaerr();
};

#endif

#ifndef FINESTRAGUIDA_H
#define FINESTRAGUIDA_H
#include<QLineEdit>
#include"guida.h"
#include"finestradalavoro.h"

class finestraguida:public finestradalavoro{
private:
    QLineEdit* nomeipovedente;
public:
    finestraguida(cani*,QWidget * =0);
    virtual void modificacampi()const;
    virtual void construisciline();
    virtual bool controlla()const;
    virtual bool controllasenzaerr();
};

#endif

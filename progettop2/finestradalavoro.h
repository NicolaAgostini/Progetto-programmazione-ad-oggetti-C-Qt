#ifndef FINESTRADALAVORO_H
#define FINESTRADALAVORO_H

#include"dalavoro.h"
#include"finestracani.h"
#include<string>

#include<QLineEdit>

class finestradalavoro:public finestracani{

private:
     QLineEdit* codident;
public:
    finestradalavoro(cani*,QWidget* =0);


    virtual ~finestradalavoro() =0;
    virtual void modificacampi() const;//ereditato e ridefinito per forza
    virtual void construisciline();//ereditato e ridefinito poichè aumentano i campi ovviamente
    virtual bool controlla()const;
    virtual bool controllasenzaerr();


};

#endif

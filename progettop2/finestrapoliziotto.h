#ifndef FINESTRAPOLIZIOTTO_H
#define FINESTRAPOLIZIOTTO_H
#include<QLineEdit>
#include "poliziotto.h"
#include"finestradalavoro.h"

class finestrapoliziotto:public finestradalavoro{
private:
    QLineEdit* nucleooperativo;
public:
    finestrapoliziotto(cani*,QWidget * =0);
    virtual void modificacampi()const;
    virtual void construisciline();
    virtual bool controlla()const;
    virtual bool controllasenzaerr();

};

#endif

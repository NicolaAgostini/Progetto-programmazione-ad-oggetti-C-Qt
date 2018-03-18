#ifndef GESTOREADMIN_H
#define GESTOREADMIN_H

#include<QMainWindow>
#include<QString>
#include"finestraadmin.h"
#include"listautenti.h"
#include"utente.h"

class gestoreadmin:public QMainWindow{
private:
    listautenti& lis;
    utente* ute;
    finestraadmin* finestra;
public:
    gestoreadmin(listautenti&,utente*,QWidget* =0);
};

#endif // GESTOREADMIN_H

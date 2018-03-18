#ifndef FINESTRAADMIN_H
#define FINESTRAADMIN_H

#include<QGridLayout>
#include<QWidget>
#include"listautenti.h"
#include"pannelloadmin.h"
#include"finestralistautenti.h"
#include"utente.h"

class finestraadmin:public QWidget{
    Q_OBJECT

private:

    listautenti& list;
    utente* ute;
    QGridLayout* disposizione;
    pannelloadmin* butto;
    finestralistautenti* finestrautenti;
public:
    finestraadmin(listautenti&,utente* ,QWidget* =0);
signals:
    void shutall();
};



#endif // FINESTRAADMIN_H

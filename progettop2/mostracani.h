#ifndef MOSTRACANI_H
#define MOSTRACANI_H

#include<QLabel>
#include<QGridLayout>
#include<QWidget>
#include"cani.h"

class mostracani:public QWidget{


public:
    mostracani(cani*,QWidget * =0);
    cani* mu;
    QGridLayout* l;
    QLabel* an;
   QLabel*  pe;
   QLabel*   no;
   QLabel*  pr;
    QLabel*  ra;
    QLabel*  co;
    QLabel*  cod;
   virtual void construisciline();
};

#endif

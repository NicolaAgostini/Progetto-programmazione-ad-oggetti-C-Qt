#ifndef MOSTRAPOLIZIOTTO_H
#define MOSTRAPOLIZIOTTO_H

#include"poliziotto.h"
#include"mostradalavoro.h"

class mostrapoliziotto:public mostradalavoro{
private:
    QLabel* nu;
public:
    mostrapoliziotto(cani* ,QWidget* =0);
     void construisciline();
};

#endif

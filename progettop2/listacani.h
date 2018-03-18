#ifndef LISTACANI_H
#define LISTACANI_H
#include<string>
#include<vector>
#include"sport.h"
#include"dacompagnia.h"
#include"poliziotto.h"
#include"caccia.h"
#include"bestiame.h"
#include"guida.h"
#include"dalavoro.h"
#include"cani.h"
#include<QFile>
#include<QXmlStreamReader>
#include <algorithm>
#include<QIODevice>
#include<QString>
#include<QMessageBox>



class listacani{


public:
    std::vector<cani*> vettore;
    listacani();
    bool aggiungi(cani*);
    std::vector<cani*> cercanome(std::string)const;

    cani* cercaindice(int)const;
    bool cancellaindice(int);
    double calcolaanno()const;
    void ordina_sullanno();
    void ordina_sulpeso();
    void ordina_sulnome();
    bool inputdaxml();

    void outputinxml();


};

#endif

#ifndef DACOMPAGNIA_H
#define DACOMPAGNIA_H
#include <string>
#include "cani.h"
#include<QXmlStreamReader>

class dacompagnia:public cani{
private:
    int microcip;
    int nexpo;
public:
    dacompagnia(int ,double ,std::string ,std::string ,std::string , std::string ,std::string ,int ,int );
    int getmicrocip()const;
    int getnexpo()const;
    void modificamicrocip(int);
    void modificanexpo(int);
    static void inputxml(QXmlStreamReader&, int&,int&);
    virtual void mieixml(QXmlStreamWriter&) const;
};

#endif

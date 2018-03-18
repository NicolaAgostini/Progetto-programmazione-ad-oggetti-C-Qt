#ifndef POLIZIOTTO_H
#define POLIZIOTTO_H
#include"cani.h"
#include "dalavoro.h"
#include<vector>
#include<string>
#include<QXmlStreamReader>

class poliziotto:public dalavoro{
private:
    std::string nucleooperativo;
public:
    poliziotto(int,double,std::string,std::string,std::string, std::string,std::string,double,std::string);
    poliziotto* clone() const;
    std::string getnucleooperativo()const;
    void modificanucleooperativo(std::string);
    static void inputxml(QXmlStreamReader&,std::string &);
    static cani* importaxml(QXmlStreamReader&);
    virtual std::string tag()const;
    virtual void mieixml(QXmlStreamWriter&) const;
};

#endif

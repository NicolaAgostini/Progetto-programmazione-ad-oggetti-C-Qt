#ifndef BESTIAME_H
#define BESTIAME_H
#include <string>
#include"cani.h"
#include "dalavoro.h"
#include<QXmlStreamReader>

class bestiame:public dalavoro{
private:
    std::string codgregge;
public:
    bestiame(int,double,std::string,std::string,std::string, std::string,std::string,double,std::string);
    std::string getcodgregge() const;
    void modificacodgregge(std::string);
    bestiame* clone() const;
    static void inputxml(QXmlStreamReader&,std::string&);
    static cani* importaxml(QXmlStreamReader &);
     virtual std::string tag()const;
    virtual void mieixml(QXmlStreamWriter&) const;
};

#endif


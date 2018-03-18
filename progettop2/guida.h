#ifndef GUIDA_H
#define GUIDA_H
#include<string>
#include"dalavoro.h"
#include"cani.h"
#include<QXmlStreamReader>

class guida:public dalavoro{
private:
    std::string nomeipovedente;
public:
    guida(int,double,std::string,std::string,std::string, std::string,std::string,double,std::string);
    std::string getnomeipovedente()const;
    void modificanomeipovedente(std::string);
    guida* clone() const;
    static void inputxml(QXmlStreamReader&,std::string &);
    static cani* importaxml(QXmlStreamReader&);
     virtual std::string tag()const;
   virtual void mieixml(QXmlStreamWriter&) const;
};

#endif

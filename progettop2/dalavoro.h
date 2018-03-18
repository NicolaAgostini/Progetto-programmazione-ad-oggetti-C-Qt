#ifndef DALAVORO_H
#define DALAVORO_H
#include"cani.h"
#include<string>
#include<QXmlStreamReader>
#include<algorithm>

class dalavoro:public cani{
private:
    double codident;
public:
    dalavoro(int,double,std::string,std::string,std::string, std::string,std::string,double);
    double getcodident()const;
    void modificacodident(double);
    static void inputxml(QXmlStreamReader&,double&);
    //non ha senso ridefinire tag tanto non istanzierò mai un oggetto di questo tipo poichè è astratto

    virtual void mieixml(QXmlStreamWriter&) const;
};

#endif

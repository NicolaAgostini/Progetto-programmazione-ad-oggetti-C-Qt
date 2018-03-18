#ifndef CACCIA_H
#define CACCIA_H
#include<cani.h>
#include<string>
#include<dacompagnia.h>

class caccia:public dacompagnia{
private:
    std::string passaportocaccia;
public:
    caccia(int ,double ,std::string ,std::string ,std::string , std::string ,std::string ,int ,int,std::string );
    std::string getpassaportocaccia()const;
    void modificapassaportocaccia( std::string);
    caccia* clone() const;
    static void inputxml(QXmlStreamReader&,std::string&);
    static cani* importaxml(QXmlStreamReader&);
     virtual std::string tag()const;
    virtual void mieixml(QXmlStreamWriter& ) const;
};

#endif

#ifndef SPORT_H
#define SPORT_H
#include<string>
#include"dacompagnia.h"
#include"cani.h"
#include<vector>
#include<QXmlStreamReader>

class sport:public dacompagnia{
private:
    std::string tiposport;
    std::string squadra;
public:
    sport(int ,double ,std::string ,std::string ,std::string , std::string ,std::string ,int ,int ,std::string,std::string);
    std::string gettiposport() const;
   std::string getsquadra() const;
    void modificatiposport(std::string);
    void modificasquadra(std::string);
     sport* clone() const;
     static void inputxml(QXmlStreamReader&,std::string&,std::string&);
     static cani* importaxml(QXmlStreamReader&);
      virtual std::string tag()const;
     virtual void mieixml(QXmlStreamWriter& ) const;
};

#endif

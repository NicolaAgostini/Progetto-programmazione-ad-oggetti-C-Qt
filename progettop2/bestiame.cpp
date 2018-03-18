#include <string>
#include"cani.h"
#include "dalavoro.h"
#include"bestiame.h"

bestiame::bestiame(int a,double b,std::string c,std::string d,std::string e, std::string f,std::string g,double h,std::string i):dalavoro(a,b,c,d,e,f,g,h),codgregge(i){}
    std::string bestiame::getcodgregge() const{
        return codgregge;
    }
    void bestiame::modificacodgregge(std::string a){
            codgregge=a;
    }

    bestiame* bestiame::clone() const{
        return new bestiame(*this);
    }
     void bestiame::inputxml(QXmlStreamReader& input,std::string& a){
         a=xmlinserisci(input,"Codgregge");
     }

     cani* bestiame::importaxml(QXmlStreamReader& input){
         int a;
         double b;
         std::string c;
         std::string d;
         std::string e;
         std::string f;
         std::string g;
         cani::inputxml(input,a,b,c,d,e,f,g);
         double h;
         dalavoro::inputxml(input,h);
         std::string i;
         bestiame::inputxml(input,i);
         return new bestiame(a,b,c,d,e,f,g,h,i);
     }
 std::string bestiame::tag()const{
         return "Bestiame";
     }
void bestiame::mieixml(QXmlStreamWriter& output) const{
     dalavoro::mieixml(output);
     output.writeTextElement("Codgregge",QString::fromStdString(getcodgregge()));
 }

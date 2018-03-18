#include"cani.h"
#include "dacompagnia.h"
#include"caccia.h"
#include <string>

caccia::caccia(int a ,double b ,std::string c,std::string d,std::string e, std::string f,std::string g,int h,int i,std::string l):dacompagnia(a,b,c,d,e,f,g,h,i),passaportocaccia(l){}
std::string caccia::getpassaportocaccia()const{
    return passaportocaccia;
}
void caccia::modificapassaportocaccia(std::string m){
    passaportocaccia=m;
}

caccia* caccia::clone() const{
    return new caccia(*this);
}
void caccia::inputxml(QXmlStreamReader&input,std::string&pass){
    pass=cani::xmlinserisci(input,"Passaportocaccia");
}

 cani* caccia::importaxml(QXmlStreamReader& input){
     int a;
     double b;
     std::string c;
     std::string d;
     std::string e;
     std::string f;
     std::string g;
     cani::inputxml(input,a,b,c,d,e,f,g);

     int h;
     int i;
     dacompagnia::inputxml(input,h,i);
     std::string l;
     caccia::inputxml(input,l);
     return new caccia(a,b,c,d,e,f,g,h,i,l);
 }
std::string caccia::tag()const{
    return "Caccia";
}
void caccia::mieixml(QXmlStreamWriter& output) const{
    dacompagnia::mieixml(output);
    output.writeTextElement("Passaportocaccia",QString::fromStdString(getpassaportocaccia()));
}

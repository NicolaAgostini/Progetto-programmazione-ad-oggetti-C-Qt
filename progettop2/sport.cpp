#include "sport.h"


sport::sport(int s,double d,std::string n,std::string c,std::string de, std::string f,std::string t,int fr,int qu,std::string ab,std::string ve):dacompagnia(s,d,n,c,de,f,t,fr,qu), tiposport(ab), squadra(ve){}
std::string sport::gettiposport() const{
    return tiposport;
}
std::string sport::getsquadra() const{
    return squadra;
}
void sport::modificatiposport(std::string re){
    tiposport=re;
}

void sport::modificasquadra(std::string ve){
    squadra=ve;
}

sport* sport::clone() const{
    return new sport(*this);
}
 void sport::inputxml(QXmlStreamReader&input,std::string&re,std::string&a){
    re=cani::xmlinserisci(input,"Tiposport");
    a=cani::xmlinserisci(input,"Squadra");
}

 cani* sport::importaxml(QXmlStreamReader&input){
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
     std::string l, m;
     sport::inputxml(input,l,m);
     return new sport(a,b,c,d,e,f,g,h,i,l,m);
}
std::string sport::tag()const{
     return "Sport";
 }
void sport::mieixml(QXmlStreamWriter& output) const{
    dacompagnia::mieixml(output);
    output.writeTextElement("Tiposport",QString::fromStdString(gettiposport()));
    output.writeTextElement("Squadra",QString::fromStdString(getsquadra()));
}

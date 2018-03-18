#include <string>
#include "dacompagnia.h"
#include "cani.h"

dacompagnia::dacompagnia(int s,double d,std::string n,std::string c,std::string de, std::string f,std::string t,int fr,int qu):cani(s,d,n,c,de,f,t),microcip(fr),nexpo(qu){}
int dacompagnia::getmicrocip()const{
    return microcip;
}
int dacompagnia::getnexpo()const{
    return nexpo;
}
void dacompagnia::modificamicrocip(int f){
    microcip=f;
}

void dacompagnia::modificanexpo(int q){
    nexpo=q;
}
void dacompagnia::inputxml(QXmlStreamReader&input, int& micro,int& nexp){
    micro=std::stoi(cani::xmlinserisci(input,"Microcip"));
    nexp=std::stoi(cani::xmlinserisci(input,"Nexpo"));
}
void dacompagnia::mieixml(QXmlStreamWriter& output) const{
    cani::mieixml(output);
    output.writeTextElement("Microcip", QString::number(getmicrocip()));
       output.writeTextElement("Nexpo", QString::number(getnexpo()));
}

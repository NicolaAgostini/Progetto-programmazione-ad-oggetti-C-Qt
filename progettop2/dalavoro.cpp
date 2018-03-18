#include"cani.h"
#include<string>
#include"dalavoro.h"


dalavoro::dalavoro(int a,double b,std::string c,std::string d,std::string e, std::string f,std::string g,double h):cani(a,b,c,d,e,f,g),codident(h){}
double dalavoro::getcodident()const{
    return codident;
}
void dalavoro::modificacodident(double f){
    codident=f;
}
void dalavoro::inputxml(QXmlStreamReader& input,double& codi){
    std::string si;
    codi=std::stod(xmlinserisci(input,"Codident"));
}
void dalavoro::mieixml(QXmlStreamWriter& output) const{
    cani::mieixml(output);
    output.writeTextElement("Codident", QString::number(getcodident()));

}

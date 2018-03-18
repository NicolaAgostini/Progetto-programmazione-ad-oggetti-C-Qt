#include<string>
#include"dalavoro.h"
#include"guida.h"

guida::guida(int a,double b,std::string c,std::string d,std::string e, std::string f,std::string g,double h,std::string i):dalavoro(a,b,c,d,e,f,g,h),nomeipovedente(i){}
std::string guida::getnomeipovedente()const{
    return nomeipovedente;
}
void guida::modificanomeipovedente(std::string a){
    nomeipovedente=a;
}
guida* guida::clone()const{
    return new guida(*this);
}
void guida::inputxml(QXmlStreamReader& input,std::string & autor){
    autor=xmlinserisci(input,"Nomeipovedente");
}

cani* guida::importaxml(QXmlStreamReader& input){
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
    guida::inputxml(input,i);
    return new guida(a,b,c,d,e,f,g,h,i);
}
std::string guida::tag()const{
    return "Guida";
}

 void guida::mieixml(QXmlStreamWriter& output) const{
    dalavoro::mieixml(output);
    output.writeTextElement("Nomeipovedente", QString::fromStdString(getnomeipovedente()));

 }

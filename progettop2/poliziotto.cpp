
#include"poliziotto.h"


poliziotto::poliziotto(int a,double b,std::string c,std::string d,std::string e, std::string f,std::string g,double h,std::string i):dalavoro(a,b,c,d,e,f,g,h),nucleooperativo(i){}
poliziotto* poliziotto::clone() const{
    return new poliziotto(*this);
}
std::string poliziotto::getnucleooperativo()const{
    return nucleooperativo;
}
void poliziotto::modificanucleooperativo(std::string a){
    nucleooperativo=a;
}

 void poliziotto::inputxml(QXmlStreamReader& input,std::string& nucleoo){
    nucleoo=cani::xmlinserisci(input,"Nucleooperativo");
}

 cani* poliziotto::importaxml(QXmlStreamReader& input){
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
    poliziotto::inputxml(input,i);
    return new poliziotto(a,b,c,d,e,f,g,h,i);
}
 std::string poliziotto::tag()const{
     return "Poliziotto";
}
void poliziotto::mieixml(QXmlStreamWriter& output) const{
    dalavoro::mieixml(output);
    output.writeTextElement("Nucleooperativo", QString::fromStdString(getnucleooperativo()));

}

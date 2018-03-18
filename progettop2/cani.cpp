#include "cani.h"
#include <string>

cani::cani(int s,double d,std::string n,std::string c,std::string de, std::string f,std::string t):anno(s),peso(d),nome(n),proprietario(c),razza(de),colore(f),codicepedigree(t){}
std::string cani::getnome()const{
    return nome;
}
int cani::getanno() const{
    return anno;
}
double cani::getpeso() const{
    return peso;
}
std::string cani::getproprietario() const{
    return proprietario;
}
std::string cani::getrazza() const{
    return razza;
}
std::string cani::getcolore()const{
    return colore;
}
std::string cani::getcodicepedigree()const{
    return codicepedigree;
}

void cani::modificaanno(int s){
    anno=s;
}
void cani::modificanome(std::string a){
    nome=a;
}

void cani::modificapeso(double d){
    peso=d;
}

void cani::modificaproprietario(std::string c){
    proprietario=c;
}

void cani::modificarazza(std::string d){
    razza=d;
}

void cani::modificacolore(std::string f){
    colore=f;
}

void cani::modificacodicepedigree(std::string t){
    codicepedigree=t;
}
 void cani::inputxml(QXmlStreamReader &input,int & ann,double & pes,std::string& nom,std::string& prop,std::string& razz,std::string& col,std::string& cod){
    std::string si;
    ann=std::stoi(xmlinserisci(input,"Anni"));
    pes=std::stod(xmlinserisci(input,"Peso"));
    nom=xmlinserisci(input,"Nome");
    prop=xmlinserisci(input,"Proprietario");
    razz=xmlinserisci(input,"Razza");
    col=xmlinserisci(input,"Colore");
    cod=xmlinserisci(input,"Codicepedigree");



}
std::string cani::xmlinserisci(QXmlStreamReader& input,std::string nometag){
    input.readNextStartElement();
    if(input.name()!=QString::fromStdString(nometag))
    {
        //errore
        return 0;

    }
    else{
        return (input.readElementText()).toStdString();
    }
}

 std::string cani::tag()const
{
    return "cani";
}
 void cani::riempixml(QXmlStreamWriter& output) const{//questa sarà la funzione ereditata da tutte le classi e a seconda di che tipo è richiamreà la virtuale mieixml() che inserisce i dati propri
     output.writeStartElement(QString::fromStdString(tag()));//scrive il tipo dell'oggetto con cui è stata invocata, come tag xml
         mieixml(output);
         output.writeEndElement();
 }
 void cani::mieixml(QXmlStreamWriter& output) const{
    output.writeTextElement("Anni",QString::number(cani::getanno()));
     output.writeTextElement("Peso",QString::number(cani::getpeso()));

     output.writeTextElement("Nome",QString::fromStdString(getnome()));
     output.writeTextElement("Proprietario",QString::fromStdString(getproprietario()));
     output.writeTextElement("Razza",QString::fromStdString(getrazza()));
     output.writeTextElement("Colore",QString::fromStdString(getcolore()));
     output.writeTextElement("Codicepedigree",QString::fromStdString(getcodicepedigree()));

 }

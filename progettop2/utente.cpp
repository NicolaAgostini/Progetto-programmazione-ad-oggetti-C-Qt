#include "utente.h"
#include <string>
#include<qstring.h>

utente::utente(std::string n, std::string p): nome(n),pass(p){}

std::string utente::getnome() const {
    return nome;
}
std::string utente::getpass() const {
    return pass;
}
void utente::cambiapass(std::string np){
    pass=np;
}
bool utente::operator==(const utente& a)const{
    if((nome==a.nome)&&(pass==a.pass)) return true;
    return false;
}
bool utente::operator!=(const utente& a)const{
    if((nome!=a.nome)||(pass!=a.pass))return true;
    return false;
}
void utente::outputinxml(QXmlStreamWriter& output)const{
    output.writeStartElement(QString::fromStdString(tipo()));
    output.writeTextElement("Nome",QString::fromStdString(getnome()));
    output.writeTextElement("Pass",QString::fromStdString(getpass()));
    output.writeEndElement();
}

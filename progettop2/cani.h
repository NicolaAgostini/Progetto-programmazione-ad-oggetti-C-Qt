#ifndef CANI_H
#define CANI_H
#include <string>
#include<QXmlStreamReader>
#include<QString>
#include<QXmlStreamWriter>

class cani{
private:
    int anno;
    double peso;
    std::string nome;
    std::string proprietario;
    std::string razza;
    std::string colore;
    std::string codicepedigree;
public:
    cani(int,double,std::string,std::string,std::string, std::string,std::string);
    std::string getnome()const;
    int getanno() const;
    double getpeso() const;
    std::string getproprietario() const;
    std::string getrazza() const;
    std::string getcolore()const;
    std::string getcodicepedigree()const;
    virtual cani* clone() const =0;
    void modificanome(std::string);
    void modificaanno(int);
    void modificapeso(double);
    void modificaproprietario(std::string);
    void modificarazza(std::string);
    void modificacolore(std::string);
    void modificacodicepedigree(std::string);
    virtual ~cani(){}
    virtual std::string tag()const;//serve per capire dinamicamente che soggetto è (per lo stream) cosi non ho bisogno del dynamic cast utilizzato male

   static std::string  xmlinserisci(QXmlStreamReader&,std::string );

   static void  inputxml(QXmlStreamReader &,int &,double &,std::string&,std::string&,std::string&,std::string&,std::string&);

   void riempixml(QXmlStreamWriter&) const;
   virtual void mieixml(QXmlStreamWriter&) const;
};

#endif

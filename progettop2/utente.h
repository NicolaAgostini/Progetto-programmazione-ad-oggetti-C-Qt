#ifndef UTENTE_H
#define UTENTE_H
#include<string>
#include<QXmlStreamWriter>

class utente{
private:
    std::string nome;
    std::string pass;
public:
    utente(std::string,std::string);
    std::string getpass() const;
    std::string getnome() const;
    void cambiapass(std::string);
    virtual bool pubblicapiu() const=0;
    virtual bool modifica() const=0;
    virtual bool elimina() const=0;
    virtual bool vedi() const=0;
    virtual utente* clone() const =0;
   virtual ~utente() {} //è virtuale ma non è puro serve per assicurarsi che il distruttore sia virtuale nella gerarchia
    bool operator==(const utente&)const;
    bool operator!=(const utente&)const;
  virtual std::string tipo()const =0;//ritorna il tipo
    void outputinxml(QXmlStreamWriter&)const;//questa è un funzione polimorfa nel senso che all'interno chiama

};

#endif // UTENTE_H

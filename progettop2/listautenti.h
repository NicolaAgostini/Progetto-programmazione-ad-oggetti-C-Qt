#ifndef LISTAUTENTI_H
#define LISTAUTENTI_H
#include<list>
#include<string>
#include"utente.h"
#include"amministratore.h"
#include"admin.h"
#include"moderatore.h"
#include"premium.h"
#include"utentestd.h"
#include<QXmlStreamReader>
#include<QFile>
#include<QIODevice>
#include<QString>



class listautenti{


public:
     std::list<utente*> lista;
    listautenti();
    bool aggiungi(utente*);
    utente* trova(std::string)const;
    bool trovato(const utente*)const;
    static bool controllapw(const utente*,std::string);
    void modificapw(utente*,std::string);
    bool inputdaxml();
    void pulisci();
    void outputinxml();//scrive in output gli utenti nuovi(usata nel caso di errore nel leggere l'xml)
};

#endif // LISTAUTENTI_H

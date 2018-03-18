#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include "utente.h"
#include "amministratore.h"
class admin:public amministratore{
public:
    admin(std::string,std::string);


    virtual bool pubblicapiu() const;//può inserire i soggetti
    virtual bool modifica() const;//puo modificare anche gli altri soggetti
    virtual bool elimina() const;//puo eliminare utenti
    virtual bool vedi() const;//puo vedere gli utenti
    virtual admin* clone() const;
    virtual std::string tipo() const;

};
#endif // ADMIN_H

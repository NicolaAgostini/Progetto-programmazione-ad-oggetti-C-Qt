#ifndef MODERATORE_H
#define MODERATORE_H
#include "amministratore.h"
#include "utente.h"
#include<string>
class moderatore:public amministratore{
public:moderatore(std::string,std::string);


    virtual bool pubblicapiu() const;
    virtual bool modifica() const;
    virtual bool elimina() const;
    virtual bool vedi() const;
    virtual moderatore* clone() const;
    virtual std::string tipo() const;
};

#endif // MODERATORE_H

#ifndef PREMIUM_H
#define PREMIUM_H
#include "utente.h"
#include <string>
#include<QXmlStreamWriter>
class premium:public utente{
public:
    premium(std::string,std::string);
        virtual bool pubblicapiu() const;
        virtual bool modifica() const;
        virtual bool elimina() const;
        virtual bool vedi() const;
        virtual premium* clone() const;
    virtual std::string tipo() const;
};

#endif // PREMIUM_H

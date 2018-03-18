#ifndef UTENTESTD_H
#define UTENTESTD_H
#include<string>
#include"utente.h"
#include<QXmlStreamWriter>
class utentestd:public utente{
public:
    utentestd(std::string,std::string);
        virtual bool pubblicapiu() const;
        virtual bool modifica() const;
        virtual bool elimina() const;
        virtual bool vedi() const;
        virtual utentestd* clone() const;
    virtual std::string tipo() const;
};


#endif // UTENTESTD_H

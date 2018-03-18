#ifndef AMMINISTRATORE_H
#define AMMINISTRATORE_H

#include "utente.h"
#include <string>
class amministratore: public utente{
public: amministratore(std::string n,std::string p):utente(n,p){}


};

#endif // AMMINISTRATORE_H

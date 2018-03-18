#include <string>
#include "utente.h"
#include "moderatore.h"
#include"amministratore.h"

moderatore::moderatore(std::string n, std::string p): amministratore(n,p){}

bool moderatore::pubblicapiu() const{
    return 1;
}
bool moderatore::modifica() const{
    return 1;
}
bool moderatore::elimina() const{
    return 0;
}
bool moderatore::vedi() const{
    return 1;
}
moderatore* moderatore::clone() const{
    return new moderatore(*this);
}
std::string moderatore::tipo()const{
    return "Moderatore";
}

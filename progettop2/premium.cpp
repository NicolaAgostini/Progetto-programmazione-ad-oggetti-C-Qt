
#include "premium.h"


premium::premium(std::string n,std::string p):utente(n,p){}

bool premium::pubblicapiu() const{
    return 1;
}
bool premium::modifica() const{
    return 0;
}
bool premium::elimina() const{
    return 0;
}
bool premium::vedi() const{
    return 0;
}
premium* premium::clone() const{
    return new premium(*this);
}
std::string premium::tipo()const{
    return "Premium";
}

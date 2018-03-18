
#include "utentestd.h"

utentestd::utentestd(std::string n,std::string p):utente(n,p){}

bool utentestd::pubblicapiu() const{
    return 0;
}
bool utentestd::modifica() const{
    return 0;
}
bool utentestd::elimina() const{
    return 0;
}
bool utentestd::vedi() const{
    return 0;
}
utentestd* utentestd::clone() const{
    return new utentestd(*this);
}
std::string utentestd::tipo()const{
    return "Utentestd";
}

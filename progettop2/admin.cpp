#include "admin.h"
#include "utente.h"
#include<string>

admin::admin(std::string n, std::string p): amministratore(n,p){}

bool admin::pubblicapiu() const{
    return 1;
}
bool admin::modifica() const{
    return 1;
}
bool admin::elimina() const{
    return 1;
}
bool admin::vedi() const{
    return 1;
}
admin* admin::clone() const{
    return new admin(*this);
}
std::string admin::tipo()const{
    return "Admin";
}

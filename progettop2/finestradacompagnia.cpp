#include "finestradacompagnia.h"


finestradacompagnia::finestradacompagnia(cani* a,QWidget * p):finestracani(a,p){}
finestradacompagnia::~finestradacompagnia() {}

void finestradacompagnia::construisciline(){

    finestracani::construisciline();
    dacompagnia* v=static_cast<dacompagnia*>(m);
    microcip=new QLineEdit;
    nexpo=new QLineEdit;


     microcip->setText(QString::number(v->getmicrocip()));

    nexpo->setText(QString::number(v->getnexpo()));


         l->addRow(new QLabel("Microcip"),microcip);// l è formlayout ereditato da finestracani
         l->addRow(new QLabel("ID Expo"),nexpo);


}

void finestradacompagnia::modificacampi()const{
    finestracani::modificacampi();
    dacompagnia* v=static_cast<dacompagnia*>(m);
    v->modificamicrocip(microcip->text().toInt());
    v->modificanexpo(nexpo->text().toInt());

}
bool finestradacompagnia::controlla()const{
    if(finestracani::controlla()){
    if(nexpo->text()==""||microcip->text()=="")
    {
        QMessageBox errore;
        errore.setWindowTitle("ERRORE");
        errore.setText("I campi vanno inseriti tutti");
        errore.exec();
        return false;

    }
    return true;//se tutti i campi sono inseriti
    }
    return false;
}

bool finestradacompagnia::controllasenzaerr(){
    if(finestracani::controllasenzaerr()){
    if(nexpo->text()==""||microcip->text()=="")
    {

        return false;

    }
    return true;//se tutti i campi sono inseriti
    }
    return false;
}

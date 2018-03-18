#include "finestradalavoro.h"

finestradalavoro::finestradalavoro(cani* a,QWidget* p):finestracani(a,p){}


finestradalavoro::~finestradalavoro() {}
void finestradalavoro::modificacampi() const{

    finestracani::modificacampi();
    dalavoro* b=static_cast<dalavoro*>(m);




    b->modificacodident(codident->text().toDouble());

    }
void finestradalavoro::construisciline(){

    finestracani::construisciline();
    dalavoro*b=static_cast<dalavoro*>(m);
    codident=new QLineEdit();
    codident->setMaxLength(5);

       codident->setText(QString::number(b->getcodident()));
        l->addRow(new QLabel("Codice Identificativo"),codident);
}
bool finestradalavoro::controlla()const{

    if(finestracani::controlla()){



    if(codident->text()=="")
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

bool finestradalavoro::controllasenzaerr(){
    if(finestracani::controllasenzaerr()){
    if(codident->text()=="")
    {

        return false;

    }
    return true;//se tutti i campi sono inseriti
    }
    return false;
}

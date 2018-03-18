#include "finestrapoliziotto.h"


finestrapoliziotto::finestrapoliziotto(cani* a,QWidget * p):finestradalavoro(a,p){}
void finestrapoliziotto::modificacampi()const{

    finestradalavoro::modificacampi();
    poliziotto* p=dynamic_cast<poliziotto*>(m);
    p->modificanucleooperativo(nucleooperativo->text().toStdString());
}
void finestrapoliziotto::construisciline(){

    finestradalavoro::construisciline();
    poliziotto* p=dynamic_cast<poliziotto*>(m);
    nucleooperativo=new QLineEdit();
    nucleooperativo->setText(QString::fromStdString(p->getnucleooperativo()));
    l->addRow(new QLabel("Nucleo operativo"),nucleooperativo);
}


bool finestrapoliziotto::controlla()const{
    if(finestradalavoro::controlla()){


    if(nucleooperativo->text()=="")
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

bool finestrapoliziotto::controllasenzaerr(){
    if(finestradalavoro::controllasenzaerr()){
    if(nucleooperativo->text()=="")
    {

        return false;

    }
    return true;//se tutti i campi sono inseriti
    }
    return false;
}

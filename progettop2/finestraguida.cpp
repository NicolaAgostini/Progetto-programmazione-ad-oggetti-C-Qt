#include"finestraguida.h"

finestraguida::finestraguida(cani* a,QWidget * p):finestradalavoro(a,p){}
void finestraguida::modificacampi()const{
    finestradalavoro::modificacampi();
    guida* r=dynamic_cast<guida*>(m);
    r->modificanomeipovedente(nomeipovedente->text().toStdString());
}
void finestraguida::construisciline(){
    finestradalavoro::construisciline();
     guida* r=dynamic_cast<guida*>(m);
    nomeipovedente=new QLineEdit();
     nomeipovedente->setText(QString::fromStdString(r->getnomeipovedente()));
     l->addRow(new QLabel("Nome della persona a cui è associato"),nomeipovedente);
}


bool finestraguida::controlla()const{
    if(finestradalavoro::controlla()){
    if(nomeipovedente->text()=="")
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
bool finestraguida::controllasenzaerr(){
    if(finestradalavoro::controllasenzaerr()){
    if(nomeipovedente->text()=="")
    {

        return false;

    }
    return true;//se tutti i campi sono inseriti
    }
    return false;
}

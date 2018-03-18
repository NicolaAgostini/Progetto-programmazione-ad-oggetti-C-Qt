#include"finestrabestiame.h"

finestrabestiame::finestrabestiame(cani* a,QWidget * p):finestradalavoro(a,p){}
void finestrabestiame::modificacampi()const{
    finestradalavoro::modificacampi();
    bestiame* c=dynamic_cast<bestiame*>(m);
   c->modificacodgregge(codgregge->text().toStdString());
}
void finestrabestiame::construisciline(){
    finestradalavoro::construisciline();
    bestiame* c=dynamic_cast<bestiame*>(m);// dinamico
   codgregge=new QLineEdit();
    codgregge->setText(QString::fromStdString(c->getcodgregge()));
    l->addRow(new QLabel("Codice Gregge"),codgregge);
}
bool finestrabestiame::controlla()const{
    if(finestradalavoro::controlla()){
    if(codgregge->text()=="")
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

bool finestrabestiame::controllasenzaerr(){
    if(finestradalavoro::controllasenzaerr()){
    if(codgregge->text()=="")
    {

        return false;

    }
    return true;//se tutti i campi sono inseriti
    }
    return false;
}

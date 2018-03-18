#include"finestracaccia.h"

finestracaccia::finestracaccia(cani* a,QWidget * p):finestradacompagnia(a,p){}
void finestracaccia::modificacampi()const{
    finestradacompagnia::modificacampi();
    caccia* ly=dynamic_cast<caccia*>(m);
    ly->modificapassaportocaccia(passaportocaccia->text().toStdString());

}
void finestracaccia::construisciline(){
    finestradacompagnia::construisciline();
    caccia* ly=dynamic_cast<caccia*>(m);//devo fare il dynamic cast perchè altrimenti non sarebbe disponibile getpassaportocaccia()
   passaportocaccia=new QLineEdit();
   passaportocaccia->setText(QString::fromStdString(ly->getpassaportocaccia()));
    l->addRow(new QLabel("Numero Permesso Caccia"),passaportocaccia);
}

bool finestracaccia::controlla()const{
    if(finestradacompagnia::controlla()){
    if(passaportocaccia->text()=="")
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

bool finestracaccia::controllasenzaerr(){
    if(finestradacompagnia::controllasenzaerr()){
    if(passaportocaccia->text()=="")
    {

        return false;

    }
    return true;//se tutti i campi sono inseriti
    }
    return false;
}

#include"finestrasport.h"


finestrasport::finestrasport(cani* a,QWidget * p):finestradacompagnia(a,p){}
void finestrasport::modificacampi()const{
    finestradacompagnia::modificacampi();
    sport*v=dynamic_cast<sport*>(m);
    v->modificatiposport(tiposport->text().toStdString());
    v->modificasquadra(squadra->text().toStdString());
}
void finestrasport::construisciline(){

     finestradacompagnia::construisciline();
    sport*v=dynamic_cast<sport*>(m);
    tiposport=new QLineEdit();
    squadra=new QLineEdit();
    tiposport->setText(QString::fromStdString(v->gettiposport()));
    squadra->setText(QString::fromStdString(v->getsquadra()));
    l->addRow(new QLabel("Sport"),tiposport);
    l->addRow(new QLabel("Appartenente al club"),squadra);
}

bool finestrasport::controlla()const{
    if(finestradacompagnia::controlla()){
    if(tiposport->text()==""||squadra->text()=="")
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

bool finestrasport::controllasenzaerr(){
    if(finestradacompagnia::controllasenzaerr()){
    if(tiposport->text()==""||squadra->text()=="")
    {

        return false;

    }
    return true;//se tutti i campi sono inseriti
    }
    return false;
}

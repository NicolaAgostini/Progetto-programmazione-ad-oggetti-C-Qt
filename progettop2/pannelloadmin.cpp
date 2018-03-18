#include"pannelloadmin.h"





pannelloadmin::pannelloadmin(utente * u,QWidget* p):QVBoxLayout(p),ute(u){
    add=new QPushButton();
    erase=new QPushButton();
    changepass=new QPushButton();
    goout=new QPushButton();
    add->setText("Aggiungi utente");
    erase->setText("Elimina utente");
    changepass->setText("Cambia password");
    goout->setText("Esci");
    addWidget(goout);
    addWidget(add);
    addWidget(changepass);
    addWidget(erase);
    if(!u->elimina()){//è un moderatore cioè
        add->setVisible(false);
        erase->setVisible(false);
        changepass->setVisible(false);
    }
    connect(goout,SIGNAL(clicked()),this,SIGNAL(close()));
    connect(add,SIGNAL(clicked()),this,SIGNAL(aggiungiute()));
    connect(changepass,SIGNAL(clicked()),this,SIGNAL(cambiapassword()));
    connect(erase,SIGNAL(clicked()),this,SIGNAL(banna()));
    connect(erase,SIGNAL(clicked()),this,SLOT(disattiva()));

}
void pannelloadmin::disattiva(){
    erase->setEnabled(false);
    changepass->setEnabled(false);
}
void pannelloadmin::attivo(){
    erase->setEnabled(true);
    changepass->setEnabled(true);
}



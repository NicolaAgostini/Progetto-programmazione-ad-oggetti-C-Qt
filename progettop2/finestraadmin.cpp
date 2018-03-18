#include"finestraadmin.h"

finestraadmin::finestraadmin(listautenti& l,utente* u, QWidget* p):QWidget(p),list(l),ute(u){
    disposizione=new QGridLayout();
    butto=new pannelloadmin(ute);
    finestrautenti=new finestralistautenti(list);
    disposizione->addItem(butto,0,1);

    disposizione->addItem(finestrautenti,0,0);

    setLayout(disposizione);
    connect(finestrautenti,SIGNAL(attivo()),butto,SLOT(attivo()));//attivo i pulsanti quando creo l oggetto praticamente
    connect(butto,SIGNAL(aggiungiute()),finestrautenti,SLOT(aggiungiute()));//praticamente queste connect servono a collegare le funzioni di banna crea e chiudi ecc. tra funzioni delle altre classi
    connect(butto,SIGNAL(banna()),finestrautenti,SLOT(banna()));
    connect(butto,SIGNAL(close()),this,SIGNAL(shutall()));
    connect(butto,SIGNAL(cambiapassword()),finestrautenti,SLOT(cambiapassword()));


}



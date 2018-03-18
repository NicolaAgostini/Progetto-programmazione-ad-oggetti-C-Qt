#include"aggiungeremodificare.h"


aggiungeremodificare::aggiungeremodificare(cani* m,bool& r,QWidget* p):QDialog(p),a(m),e(r){
    if(a->getrazza()==""){
        setWindowTitle("Crea il soggetto");
    }
    else{
        setWindowTitle("Modifica il soggetto");
    }
    l=new QFormLayout(this);


     fm=ritornapuntatore(a);
    if(fm)
    {

        fm->costruttore();

        l->addWidget(fm);

             connect(fm, SIGNAL(tuttook()), this, SLOT(prova()));
        connect(fm, SIGNAL(tuttook()), this, SLOT(accept()));
connect(fm, SIGNAL(annullaok()), this, SLOT(prova()));


        connect(fm, SIGNAL(annullaok()), this, SLOT(reject()));


    }
    else{
        l->addRow(new QLabel("Errore"));
        QMessageBox p;
        p.setText("Errore!");
        p.exec();
    }
}
finestracani* aggiungeremodificare::ritornapuntatore(cani * m){
    if(m->tag()=="Poliziotto")
        return new finestrapoliziotto(m);
    if(m->tag()=="Bestiame")
        return new finestrabestiame(m);
    if(m->tag()=="Guida")
        return new finestraguida(m);
    if(m->tag()=="Sport")
        return new finestrasport(m);
    if(m->tag()=="Caccia")
        return new finestracaccia(m);


     return 0;
}
void aggiungeremodificare::prova(){
    if(!fm->controllasenzaerr())
    {
        e=false;
    }
}


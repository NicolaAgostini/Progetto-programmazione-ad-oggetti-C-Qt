#include"finestramostrasoggetto.h"
#include<QMessageBox>



finestramostrasoggetto::finestramostrasoggetto(cani *m,QWidget* p):QDialog(p),mostra(m){
    setWindowTitle("Mostra info del Soggetto");
    disposizione=new QGridLayout(this);
    mostracani* mm=ritornapuntatore(mostra);
    if(mm){
        mm->construisciline();
        disposizione->addWidget(mm);
    }
    else{
        QMessageBox errore;
        errore.setText("Errore nell'operazione!");
        errore.exec();
    }




}
mostracani* finestramostrasoggetto::ritornapuntatore(cani* o){//serve per castare dinamicamente la cani in modo da chiamare gli overriding virtuali giusti di construisciline
    if(o->tag()=="Poliziotto")
    {
        return new mostrapoliziotto(o);
    }
    if(o->tag()=="Bestiame")
    {
        return new mostrabestiame(o);
    }
    if(o->tag()=="Guida")
    {
        return new mostraguida(o);
    }
    if(o->tag()=="Sport")
    {
        return new mostrasport(o);
    }
    if(o->tag()=="Caccia")
    {
        return new mostracaccia(o);
    }
    return 0;

}

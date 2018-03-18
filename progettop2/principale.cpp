#include"principale.h"
#include<QDebug>



 principale::principale(listautenti& l,utente* u,QWidget* p):QWidget(p),lutente(l),user(u){
     lelemento.inputdaxml();//carico i soggetti da xml
     griglia=new QGridLayout();
     setLayout(griglia);
     if(user->vedi())//è o moderatore o admin
     {
         badmin=new QPushButton("Gestisci");
         badmin->setFixedSize(150,40);
         gestore=new gestoreadmin(lutente,user);
         connect(badmin,SIGNAL(clicked()),gestore,SLOT(show()));//qui ho collegato il pulsante gestisci per gli admin dopo aver verificato che l'utente sia amministratore e mostro la windows con collegato il widget finestraadmin
         griglia->addWidget(badmin,2,0);

     }


     lista=new QListWidget();
     griglia->addWidget(lista,0,1,7,1);
     finestraaggiornamento=new QScrollArea();
    aggiornamento=new QLabel();
    finestraaggiornamento->setWidget(aggiornamento);
    aggiornamento->setText("Seleziona un soggetto");
    aggiornamento->setFixedWidth(200);
    aggiornamento->setFixedHeight(30);
    aggiornamento->setWordWrap(true);
    finestraaggiornamento->setFixedWidth(210);
    finestraaggiornamento->setFixedHeight(40);
    griglia->addWidget(finestraaggiornamento,0,0);
    baggiungi=new QPushButton("Inserisci un soggetto");
    griglia->addWidget(baggiungi,2,2);


        bmodifica=new QPushButton("Modifica");
    griglia->addWidget(bmodifica,3,2);
    bmodifica->setDisabled(true);
    berase=new QPushButton("Elimina");
    griglia->addWidget(berase,4,2);
    berase->setDisabled(true);
    bordnome=new QPushButton("Ordina per nome");
    griglia->addWidget(bordnome,5,2);
    borddimensione=new QPushButton("Ordina per età");
    griglia->addWidget(borddimensione,6,2);
    Orddurata=new QPushButton("Ordina per Peso");
    griglia->addWidget(Orddurata,7,2);
    if(user->tipo()=="Utentestd")//cioè è utente free
      {  baggiungi->setVisible(false);//allora non puo aggiungere un dalavoro           QUI ! ! ! ! ! !  !   ! !!!! ! ! !!!!!!! ! !  ! ! !  !   ! !     !! !
            bmodifica->setVisible(false);
            berase->setVisible(false);

    }

    bottieniinfo=new QPushButton("Mostra dettagli");//per ottenere info estese sul dalavoro e non solo anteprima

    griglia->addWidget(bottieniinfo,8,2);
    bottieniinfo->setDisabled(true);

    media=new QLabel();
     double tot=lelemento.calcolaanno();
     media->setText("Età media dei soggetti: "+QString::number(tot));
     griglia->addWidget(media,3,0);

     connect(lista,SIGNAL(itemSelectionChanged()),this,SLOT(ricaricabottieniinfo()));
    connect(bottieniinfo,SIGNAL(clicked()),this,SLOT(mostrainfo()));
    connect(lista,SIGNAL(itemSelectionChanged()),this,SLOT(informazioni()));
    connect(lista,SIGNAL(itemSelectionChanged()),this,SLOT(ricaricabmodifica()));
    connect(lista,SIGNAL(itemSelectionChanged()),this,SLOT(ricaricaberase()));
    connect(bmodifica,SIGNAL(clicked()),this,SLOT(modificare()));
    connect(baggiungi,SIGNAL(clicked()),this,SLOT(aggiungere()));
    connect(berase,SIGNAL(clicked()),this,SLOT(eraseelement()));
    connect(bordnome,SIGNAL(clicked()),this,SLOT(ordinasulnome()));
    connect(borddimensione,SIGNAL(clicked()),this,SLOT(ordinasullanno()));
    connect(Orddurata,SIGNAL(clicked()),this,SLOT(ordinasulpeso()));

    finestraricerca();
    aggiorna();

 }
 void principale::aggiorna(){//stampa la lista (agiornata) nell'apposito spazio
     lista->clear();
     for(int i=0;i<(static_cast<int>(lelemento.vettore.size()));i++)
     {
         QListWidgetItem* elemento=new QListWidgetItem();
         elemento->setText(QString::fromStdString(lelemento.vettore[i]->getnome()));
         lista->addItem(elemento);

     }
     informazioni();

 }
 void principale::finestraricerca(){
     labeltrova=new QLabel("Trova");
     labeltrova->setMaximumHeight(20);
     labeltrova->setMinimumHeight(15);
griglia->addWidget(labeltrova,0,2);
trova=new QLineEdit();
    griglia->addWidget(trova,1,2);
    connect(trova,SIGNAL(textEdited(const QString &)),this,SLOT(aggiornaricerca()));

 }

void principale::mostrainformazioni(){//mostra le info nella finestra di sinistra
    int i=lista->currentRow();
   cani* o= lelemento.vettore[i];
   std::string a=o->getnome();
   QString p=QString::fromStdString(o->tag());

   aggiornamento->setText("Nome: "+ QString::fromStdString(a) +"\n"+"Tipo :"+p);//solo anteprima del nome
   aggiornamento->adjustSize();



}

void principale::media_anni(){//praticamente aggiorna la media degli anni se modifico o elimino un soggetto


    double tot=lelemento.calcolaanno();
    media->setText("Età media dei soggetti: "+QString::number(tot));

}

void principale::informazioni(){
    if(lista->currentRow()>=0)//se è selezionato qualcosa, di esistente
        mostrainformazioni();
}
void principale::ricaricaberase(){
    int i=lista->currentRow();
   cani* o= lelemento.vettore[i];
    //cioè se il chiamante è quello che ha creato il dalavoro o se è un moderatore o meglio admin allora puo eliminare poichè gli faccio comparire il pulsante elimina
   if((lista->currentItem()->isSelected())&&(((user->modifica())||(o->getproprietario()==user->getnome()))))
   berase->setDisabled(false);
    else{
        berase->setDisabled(true);
    }

}
void principale::ricaricabmodifica(){



    int i=lista->currentRow();
   cani* o= lelemento.vettore[i];
    if((lista->currentItem()->isSelected())&&(((user->modifica())||(o->getproprietario()==user->getnome()))))//stessa roba di sopra
        bmodifica->setDisabled(false);
    else
        bmodifica->setDisabled(true);


}
void principale::eraseelement(){
    lelemento.cancellaindice(lista->currentRow());
    lista->takeItem(lista->currentIndex().row());
    lelemento.outputinxml();
    tornaallinizio();
    emit cambiamessaggio("Eliminato!");

    media_anni();
}
void principale::modificare(){

    int i=lista->currentRow();
   cani* o= lelemento.vettore[i];
   bool ty=true;
    aggiungeremodificare* a=new aggiungeremodificare(o,ty);
    int ok=a->exec();
    if(ok==QDialog::Accepted)
    {
        lelemento.outputinxml();
        lista->item(lista->currentRow())->setText(QString::fromStdString(o->getnome()));
        emit cambiamessaggio("Editato!!");
        mostrainformazioni();
    }
    else{
        emit cambiamessaggio("Non posso modificare!");
        lista->setCurrentRow(i);//ritorno alla situazione di partenza
    }

    media_anni();
}
void principale::aggiungere(){
    int a=lista->currentRow();

    scrivi=new QDialog();
     radio1=new QRadioButton("Poliziotto",this);
 radio2=new QRadioButton("Bestiame",this);
 radio3=new QRadioButton("Guida",this);
radio4=new QRadioButton("Sport",this);
 radio5=new QRadioButton("Caccia",this);
    vert=new QVBoxLayout();
    vert->addWidget(radio1);
    vert->addWidget(radio2);
    vert->addWidget(radio3);
    vert->addWidget(radio4);
    vert->addWidget(radio5);
    scrivi->setLayout(vert);
     okvai=new QPushButton();
    okvai->setText("Conferma");
    vert->addWidget(okvai);
    connect(okvai,SIGNAL(clicked(bool)),scrivi,SLOT(close()));

    scrivi->exec();

    cani* m=0;
    if(radio1->isChecked()){
        m=new poliziotto(0,0,"","","","","",0,"");
     m->modificaproprietario(user->getnome());
    }
    if(radio2->isChecked()){
        m=new bestiame(0,0,"","","","","",0,"");
    m->modificaproprietario(user->getnome());
    }
    if(radio3->isChecked()){
        m=new guida(0,0,"","","","","",0,"");
    m->modificaproprietario(user->getnome());
    }
    if(radio4->isChecked()){
        m=new sport(0,0,"","","","","",0,0,"","");
    m->modificaproprietario(user->getnome());
    }
    if(radio5->isChecked()){
        m=new caccia(0,0,"","","","","",0,0,"");
    m->modificaproprietario(user->getnome());
    }



    if(m!=0)
    {
        bool ty=true;
        aggiungeremodificare* f=new aggiungeremodificare(m,ty);
        int risultato=f->exec();
        f->prova();



        if(!ty)
        {

            delete m;
            return;
        }
        if(risultato==QDialog::Rejected)
        {
           delete m;
            return;
        }

        lelemento.aggiungi(m);
        delete m;// ELIMINA IL SOGGETTO DOPO AVER AGGIUNTO UNA COPIA POLIMORFA COL METODO CLONE()

        lelemento.outputinxml();
        lista->addItem(new QListWidgetItem(QString::fromStdString(m->getnome())));
        lista->setCurrentRow((lista->count()-1));//vado a dove ho aggiunto
        emit cambiamessaggio("Soggetto aggiunto!!!");
    }
    else{
        QMessageBox msgErr;
                    msgErr.setWindowTitle("Error");
                    msgErr.setText("Il Soggetto non è stato inserito,tipo non inserito o operazione annullata");

                    msgErr.exec();
                    lista->setCurrentRow(a);
                    emit cambiamessaggio("Soggetto non creato!");
    }
media_anni();









}


void principale::aggiornaricerca(){
    int a =0;
    for(int i=0;i<(static_cast<int>(lelemento.vettore.size()));i++)
    {

        if((QString::fromStdString(lelemento.vettore[i]->getnome())).indexOf(trova->text(),0)!=-1)//cioè c'è un match
        {


            lista->setRowHidden(a,false);
        }
        else {
            lista->setRowHidden(a,true);//nascondo quelle che non c'entrano
        }
        a++;
    }
}
void principale::tornaallinizio(){
    lista->clearSelection();
    berase->setDisabled(true);
    bmodifica->setDisabled(true);
    aggiornamento->setText("Seleziona un soggetto");
    aggiornamento->adjustSize();
}


void principale::ordinasulnome(){

        lelemento.ordina_sulnome();

        emit cambiamessaggio("Ordine sul Nome");
    lelemento.outputinxml();
    aggiorna();
    tornaallinizio();

}
void principale::ordinasullanno(){
   lelemento.ordina_sullanno();
    emit cambiamessaggio("Ordine sull'età");
lelemento.outputinxml();
aggiorna();
tornaallinizio();
}
void principale::ordinasulpeso(){
    lelemento.ordina_sulpeso();
    emit cambiamessaggio("Ordine sul peso");
lelemento.outputinxml();
aggiorna();
tornaallinizio();
}

void principale::mostrainfo(){
    int i=lista->currentRow();
   cani* o= lelemento.vettore[i];
    finestramostrasoggetto* a=new finestramostrasoggetto(o);
    a->setMinimumWidth(400);
    int ok=a->exec();
    if(ok==QDialog::Accepted)
    {

        lista->item(lista->currentRow())->setText(QString::fromStdString(o->getnome()));
        emit cambiamessaggio("Informazioni Viste!!");
        mostrainformazioni();
    }
    else{
        emit cambiamessaggio("Per le informazioni, premi mostra informazioni");
        lista->setCurrentRow(i);//ritorno alla situazione di partenza
    }
}
void principale::ricaricabottieniinfo(){

    if(lista->currentItem()->isSelected())
        bottieniinfo->setDisabled(false);
    else
        bottieniinfo->setDisabled(true);
}









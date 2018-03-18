#include"finestralistautenti.h"




finestralistautenti::finestralistautenti(listautenti& lista, QWidget* p):QVBoxLayout(p),lista(lista){
    etichetta=new QLabel("Lista Utenti");
    listawidget=new QListWidget();
    listawidget->setFixedWidth(100);
    addWidget(etichetta);
    addWidget(listawidget);
    etichettaricerca=new QLabel("Cerca");
    cerca=new QLineEdit();
    addWidget(etichettaricerca);
    addWidget(cerca);
    connect(cerca,SIGNAL(textEdited(const QString&)),this,SLOT(scartalista()));//cioè quando scrivo qualcosa viene cercato l elemento scartando quelli che non c'entrano
    ricaricalista();//ovviamente aggiorno la lista COME PRIMA COSA
    connect(listawidget,SIGNAL(itemSelectionChanged()),this,SIGNAL(attivo()));//quando seleziono riattivo i bottoni elimina e cambia pass poichè cambio utente e non c'è piu rischio di guai
}

void finestralistautenti::refresh(){
    listawidget->clear();
    for(std::list<utente*>::const_iterator ci=lista.lista.begin();ci!=lista.lista.end();++ci)
    {
        QListWidgetItem* valore=new QListWidgetItem;
        valore->setText(QString::fromStdString((*ci)->getnome()));
        listawidget->addItem(valore);
    }
    if(cerca->text()!="")
    {
        filtralista();
    }
}

void finestralistautenti::filtralista(){
    int nnascondi=0;
    for(std::list<utente*>::const_iterator ci=lista.lista.begin();ci!=lista.lista.end();++ci){

        if(QString::fromStdString((*ci)->getnome()).indexOf(cerca->text())!=-1)//cioè è stato trovato
        {
            listawidget->setRowHidden(nnascondi,false);
        }
        else{
            listawidget->setRowHidden(nnascondi,true);//se stai cercando allora nascondi quelle che non cerci
        }
         nnascondi++;
    }
}



void finestralistautenti::ricaricalista(){
    refresh();
}

void finestralistautenti::scartalista(){
    filtralista();
}

void finestralistautenti::aggiungiute(){

    scrivi=new QDialog();
    radio1=new QRadioButton("Admin");
 radio2=new QRadioButton("Moderatore");
  radio3=new QRadioButton("Utente Premium");
 radio4=new QRadioButton("Utente Standard");

    vert=new QVBoxLayout();
    vert->addWidget(radio1);
    vert->addWidget(radio2);
    vert->addWidget(radio3);
    vert->addWidget(radio4);

    scrivi->setLayout(vert);
    annulla=new QPushButton();
    annulla->setText("Annulla");
     okvai=new QPushButton();
    okvai->setText("Conferma");
    vert->addWidget(okvai);
    vert->addWidget(annulla);

     insenome=new QLineEdit();
    insepass=new QLineEdit();
    vert->addWidget(insenome);
    vert->addWidget(insepass);

    utenterifiutato=false;

    connect(okvai,SIGNAL(clicked(bool)),scrivi,SLOT(close()));
    connect(annulla,SIGNAL(clicked(bool)),this,SLOT(annullainserimento()));
    connect(annulla,SIGNAL(clicked(bool)),scrivi,SLOT(close()));

    scrivi->exec();
    QString id=insenome->text();
    QString passco=insepass->text();



    if(id==""||passco=="")
    {
        QMessageBox errore;
        errore.setText("Erorre nell'aggiungere l'utente, operazione annullata!");
        errore.exec();
        return;
    }
    if(lista.trova(id.toStdString()))//vuol dire che c'è gia un utente con quel id
    {
        QMessageBox errore;
        errore.setText("Erorre nell'aggiungere l'utente,utente gia esistente");
        errore.exec();
        return;
    }
    if(utenterifiutato){
        return;
    }
    utente* nuovo=0;
    if(radio1->isChecked()){
        nuovo=new admin(id.toStdString(),passco.toStdString());
    }
    if(radio2->isChecked()){
        nuovo=new moderatore(id.toStdString(),passco.toStdString());
    }
    if(radio3->isChecked()){
        nuovo=new premium(id.toStdString(),passco.toStdString());
    }
    if(radio4->isChecked()){
        nuovo=new utentestd(id.toStdString(),passco.toStdString());
    }
    if(nuovo!=0){//cioè è stato creato bene
             lista.aggiungi(nuovo);
             lista.outputinxml();
             listawidget->addItem(new QListWidgetItem(QString::fromStdString(nuovo->getnome())));
             listawidget->setCurrentRow(listawidget->count()-1);//poichè ho aggiunto un elemento
    }
    else{
        QMessageBox errore;
        errore.setText("Erorre nell'aggiungere l'utente, nessun tipo selezionato!");
        errore.exec();
        return;
    }


}


void finestralistautenti::banna(){
    QWidget* eli=new QWidget();
    eli->setWindowTitle("Eliminazione Utente");
    lista.lista.remove(lista.trova(listawidget->currentItem()->text().toStdString()));
    listawidget->takeItem(listawidget->currentIndex().row());
    lista.outputinxml();
}

void finestralistautenti::cambiapassword(){
    bool ok=false;
    QWidget* widge=new QWidget();
    widge->setWindowTitle("Cambia Password");
    QInputDialog* testo=new QInputDialog();
    QString nuovapass=testo->getText(widge,"Cambia","Nuova password",QLineEdit::Normal,"", &ok);//ciao
    if(ok){
        lista.modificapw(lista.trova(listawidget->currentItem()->text().toStdString()),nuovapass.toStdString());
        lista.outputinxml();//ovviamente aggiorno sempre l'xml come sopra
    }

}
void finestralistautenti::annullainserimento(){
    utenterifiutato=true;
}


#include "autenticazione.h"

autenticazione::autenticazione(listautenti& lista_ute,utente** ute,bool& y,QWidget* parent):QDialog(parent),listaU(lista_ute),user(ute),ok(y){
    setWindowTitle(tr("Loop Quantum Records"));

    creafinestra();
    QVBoxLayout* principale = new QVBoxLayout;//ora rendo visibile e eseguo la finestra di login
    //dopo aver settato i parametri con la funzione creafinestra()
        principale->addLayout(finestra);
        setLayout(principale);
}
void autenticazione::provaautenticazione(){

    if(listautenti::controllapw(listaU.trova(inserisciutente->text().toStdString()),inseriscipass->text().toStdString()))//controlla pass
    {
        QMessageBox* succes=new QMessageBox();
        succes->setText("Loggato con successo!!");
        succes->exec(); //prova per vedere se funziona
        *user=listaU.trova(inserisciutente->text().toStdString());
        this->close();
    }
    else{
        QMessageBox* errore=new QMessageBox();
        if(!listaU.trova(inserisciutente->text().toStdString()))//utente non esiste
        {
            errore->setText("Utente Inesistente");
        }
        else{//pass sbagliata
            errore->setText("Password Errata");
            inseriscipass->clear();
            inseriscipass->setFocus();

        }
        errore->exec();
    }
}

void autenticazione::pulisci(){//pulisce login e pass in caso siano sbagliati
    inserisciutente->clear();
    inseriscipass->clear();
    inserisciutente->setFocus();
}

void autenticazione::creafinestra(){
    finestra=new QGridLayout();
    testoutente=new QLabel();
    testoutente->setText("ID:");
    testopass=new QLabel();
    testopass->setText("Pass:");
    inserisciutente=new QLineEdit();
    inseriscipass=new QLineEdit();
    inseriscipass->setEchoMode(QLineEdit::Password);//praticamente quando scrivo vedo gli asterischi *****
    finestra->addWidget(testoutente, 1, 0);
        finestra->addWidget(inserisciutente, 1, 1);
        finestra->addWidget(testopass, 2, 0);
        finestra->addWidget(inseriscipass, 2, 1);
        autenticati=new QPushButton();
        autenticati->setText("Login");
    finestra->addWidget(autenticati, 3, 0, 1, 2);
    chiudi=new QPushButton();
    chiudi->setText("Esci dal programma");
    finestra->addWidget(chiudi,4,1);

    connect(autenticati,SIGNAL(clicked(bool)),this,SLOT(provaautenticazione()));
    connect(chiudi,SIGNAL(clicked(bool)),this,SLOT(cambiaok()));
    setFixedSize(400,250);
}
void autenticazione::cambiaok(){
        ok=false;
        close();
}

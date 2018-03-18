#include "finestracani.h"



finestracani::~finestracani() {}//lo ridefinisco
finestracani::finestracani(cani* a,QWidget* p):QWidget(p),m(a) {}



void finestracani::costruttore(){

    construisciline();

    costruiscibutton();
}

void finestracani::modificacampi()const{

    m->modificaanno(anno->text().toInt());

    m->modificapeso(peso->text().toDouble());// OK double !! !  ! ! ! !  ! !

    m->modificanome(nome->text().toStdString());
    m->modificaproprietario(proprietario->text().toStdString());
    m->modificarazza(razza->text().toStdString());
    m->modificacolore(colore->text().toStdString());
    m->modificacodicepedigree(codicepedigree->text().toStdString());

}

bool finestracani::controlla()const{
    if(anno->text()==""||peso->text()==""||nome->text()==""||proprietario->text()==""||razza->text()==""||colore->text()==""||codicepedigree->text()=="")
    {
        QMessageBox errore;
        errore.setWindowTitle("ERRORE");
        errore.setText("I campi vanno inseriti tutti");
        errore.exec();
        return false;

    }
    return true;//se tutti i campi sono inseriti
}

void finestracani::construisciline(){

    l = new QFormLayout(this);
        anno= new QLineEdit();
       peso = new QLineEdit();
        nome = new QLineEdit();
       proprietario = new QLineEdit();
        razza = new QLineEdit();
        colore=new QLineEdit();
        codicepedigree=new QLineEdit();
        codicepedigree->setMaxLength(7);//massimo 7 caratteri
        anno->setMaxLength(3);
        peso->setMaxLength(3);



        anno->setText(QString::number(m->getanno()));
        peso->setText(QString::number(m->getpeso()));
        nome->setText(QString::fromStdString(m->getnome()));
        proprietario->setText(QString::fromStdString(m->getproprietario()));
        razza->setText(QString::fromStdString(m->getrazza()));
        colore->setText(QString::fromStdString(m->getcolore()));
       codicepedigree->setText(QString::fromStdString(m->getcodicepedigree()));

        l->addRow(new QLabel("Anni"),anno);
        l->addRow(new QLabel("Peso"),peso);
        l->addRow(new QLabel("Nome"),nome);
        l->addRow(new QLabel("Proprietario"),proprietario);
        l->addRow(new QLabel("Razza"),razza);
        l->addRow(new QLabel("Colore"),colore);
        l->addRow(new QLabel("Codice del Pedigree"),codicepedigree);

}

void finestracani::costruiscibutton(){
    conferma=new QPushButton();
    annulla=new QPushButton();
    conferma->setText("Conferma");
    annulla->setText("Annulla");
    conferma->setFixedWidth(150);
    conferma->setFixedHeight(50);
   annulla->setFixedWidth(150);
    annulla->setFixedHeight(50);
    annulla->setFocus();
    l->addRow(annulla,conferma);

    connect(annulla,SIGNAL(clicked()),this,SLOT(tornaindietro()));
    connect(conferma,SIGNAL(clicked()),this,SLOT(aggiorna()));


}


 void finestracani::aggiorna(){
        if(controlla())
        {

            modificacampi();

            emit tuttook();

        }

    }

    void finestracani::tornaindietro(){
        emit annullaok();
    }

bool finestracani::controllasenzaerr(){
    if(anno->text()==""||peso->text()==""||nome->text()==""||proprietario->text()==""||razza->text()==""||colore->text()==""||codicepedigree->text()=="")
    {

        return false;

    }
    return true;//se tutti i campi sono inseriti
}





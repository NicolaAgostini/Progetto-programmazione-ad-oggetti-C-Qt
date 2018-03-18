#include "mostracani.h"


mostracani::mostracani(cani* q,QWidget * p): QWidget(p),mu(q){}

void mostracani::construisciline(){

    l=new QGridLayout(this);
    an = new QLabel();
    pe = new QLabel();
      no = new QLabel();
    pr = new QLabel();
      ra = new QLabel();
      co=new QLabel();
      cod=new QLabel();

    an->setText("Anni: " + QString::number(mu->getanno()));
    pe->setText("Peso: "+QString::number(mu->getpeso()));
    no->setText("Nome: "+QString::fromStdString(mu->getnome()));
    pr->setText("Proprietario: "+QString::fromStdString(mu->getproprietario()));
    ra->setText("Razza: "+QString::fromStdString(mu->getrazza()));
    co->setText("Colore: "+QString::fromStdString(mu->getcolore()));
    cod->setText("Codice Pedigree: "+QString::fromStdString(mu->getcodicepedigree()));

    l->addWidget(an);
    l->addWidget(pe);
    l->addWidget(no);
    l->addWidget(pr);
    l->addWidget(ra);
    l->addWidget(co);
    l->addWidget(cod);

}

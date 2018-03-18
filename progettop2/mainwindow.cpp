#include "mainwindow.h"

MainWindow::MainWindow(utente* u,listautenti& l,bool& i,QWidget * p):QMainWindow(p),lutente(l),user(u),ok(i){
    setWindowTitle("Loop Quantum Records");
    aggiornalutente();
    inseriscibarra();
}

void MainWindow::aggiornalutente(){
    barra=new barraalta();
    barra->cambiamessaggio(QString::fromStdString(user->getnome()));
    setStatusBar(barra);
    Principale=new principale(lutente,user);
setCentralWidget(Principale);//QUI ! ! !  ! !!! !!!! !  ! ! !  !
    connect(Principale,SIGNAL(cambiamessaggio(QString)),barra,SLOT(cambiamessaggio(QString)));//cosi collego i cambiamenti della barra alla mainwindow

}

void MainWindow::inseriscibarra(){

    melemento=new QMenu("Help");





    adeloggati = new QAction(tr("&Logout"), this);
        adeloggati->setShortcuts(QKeySequence::New);
        adeloggati->setStatusTip(tr("Esegui il logout"));
        ainformazioni=new QAction("About",this);
        aesci=new QAction("Esci",this);
aesci->setShortcuts(QKeySequence::Close);

            melemento->addAction(adeloggati);
            melemento->addAction(ainformazioni);
            melemento->addAction(aesci);
menuBar()->addMenu(melemento);



    connect(adeloggati,SIGNAL(triggered(bool)),this,SLOT(loggati()));
    connect(adeloggati,SIGNAL(triggered()),this,SLOT(close()));
    connect(aesci,SIGNAL(triggered()),this,SLOT(close()));
    connect(ainformazioni,SIGNAL(triggered()),this,SLOT(informati()));

}



void MainWindow::loggati(){
    ok=false;
}

void MainWindow::informati(){
    QMessageBox in;
    in.setText("Applicazione  versione 1.0");
    in.exec();
}




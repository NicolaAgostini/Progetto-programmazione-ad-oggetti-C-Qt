#ifndef AUTENTICAZIONE_H
#define AUTENTICAZIONE_H
#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QPicture>
#include <QMessageBox>
#include"listautenti.h"
#include"utente.h"

class autenticazione:public QDialog{
    Q_OBJECT
private:
    const listautenti & listaU;
    QLineEdit* inserisciutente;
    QLineEdit* inseriscipass;
    QLabel* testoutente;
    QLabel* testopass;

    QPushButton* autenticati;
    QPushButton* chiudi;
    QGridLayout* finestra;
    utente** user;
    bool& ok;
public:
    autenticazione(listautenti&,utente**,bool&,QWidget* parent=0);
    void pulisci();
    void creafinestra();
public slots:
    void provaautenticazione();
    void cambiaok();
};

#endif // AUTENTICAZIONE_H

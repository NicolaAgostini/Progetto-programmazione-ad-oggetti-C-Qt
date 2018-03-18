#ifndef PANNELLOADMIN_H
#define PANNELLOADMIN_H

#include<QVBoxLayout>
#include<QPushButton>
#include<QWidget>
#include"utente.h"


class pannelloadmin:public QVBoxLayout{
    Q_OBJECT
private:
    utente* ute;
    QPushButton* add;
    QPushButton* erase;
    QPushButton* changepass;
    QPushButton* goout;
public:
    pannelloadmin(utente* ,QWidget* =0);
public slots:
    void disattiva();//serve per disattivare il pulsante elimina e cambia password quando elimino l utente per evitare di rieliminare lo stesso utente o cambiare la pass ad un utente che ormai ho eliminato
    void attivo();//ripristino i pulsanti elimina e cambia pass quando seleziono un nuovo utente
signals:
    void close();//chiude la creazione
    void aggiungiute();//aggiunge un utente
    void cambiapassword();//cambia la pass
    void banna();//elimina un utente
};

#endif // PANNELLOADMIN_H

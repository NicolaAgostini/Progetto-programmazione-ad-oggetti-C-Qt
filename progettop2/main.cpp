#include "mainwindow.h"
#include <QApplication>
#include "listautenti.h"
#include "utente.h"
#include "autenticazione.h"
#include"listacani.h"
#include"mainwindow.h"
#include<QMessageBox>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    listautenti q;
    bool inputok=false;
    inputok=q.inputdaxml();
    if(!inputok)
    {
        q.pulisci();
                    admin u("admin","qrz398");
                  q.aggiungi(&u);
                 moderatore mod("moderatore","kng932");
                  q.aggiungi(&mod);

                        QMessageBox er;
                        er.setText("Errore nel caricamento file, due utenti creati id: admin password: qrz398");
                        er.setWindowTitle("Errore");
                        er.exec();

                        q.listautenti::outputinxml();

    }

    {
        utente* b=0;
        bool ok=true;
        autenticazione* c=new autenticazione(q,&b,ok);

            while(ok)
            {
                b=0;
                c->pulisci();
                c->exec();

                if(b!=0){
                        bool ok2=true;
                        MainWindow w(b,q,ok2);
                        w.setWindowModality(Qt::ApplicationModal);
                        w.show();
                        a.exec();
                        if(ok2)//cioè non è stato premuto il pulsante adeloggati quindi si esce normalmente
                        {
                            ok=false;
                        }
                }

            }

    }



    return 0;
}

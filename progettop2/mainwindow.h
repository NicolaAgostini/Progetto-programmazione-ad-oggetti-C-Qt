#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<barraalta.h>
#include <QStatusBar>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QString>
#include <QMessageBox>
#include <QString>
#include"listautenti.h"
#include"principale.h"
#include<string>



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(utente*,listautenti&,bool&,QWidget * =0);
    void aggiornalutente();
    void inseriscibarra();


private:
    barraalta* barra;
    principale* Principale;
    QMenuBar* menu;
    QMenu* melemento;
    QMenu* maggiorna;
    QAction* adeloggati;
    QAction* aesci;
    QAction* ainformazioni;
    listautenti& lutente;
    utente* user;
    bool &ok;
public slots:
    void loggati();
    void informati();




};

#endif // MAINWINDOW_H

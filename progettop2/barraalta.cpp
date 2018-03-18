#include"barraalta.h"

barraalta::barraalta(QWidget * parent ):QStatusBar(parent){
     messaggio= new QLabel("Menu centrale");
     addPermanentWidget(messaggio,1);
}

void barraalta::cambiamessaggio(QString a){
    messaggio->setText(a);
}

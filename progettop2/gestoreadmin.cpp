#include"gestoreadmin.h"



gestoreadmin::gestoreadmin(listautenti& l,utente* u,QWidget* p): QMainWindow(p),lis(l),ute(u){
    setWindowTitle("Admin");
    setWindowModality(Qt::ApplicationModal);//QUi !!! ! !  ! !
    finestra=new finestraadmin(lis,ute);
    setCentralWidget(finestra);
    connect(finestra,SIGNAL(shutall()),this,SLOT(close()));
    setMaximumSize(400,600);

}

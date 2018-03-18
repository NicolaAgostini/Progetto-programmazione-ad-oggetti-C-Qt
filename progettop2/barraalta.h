#ifndef BARRAALTA_H
#define BARRAALTA_H

#include<QString>
#include<QStatusBar>
#include<QLabel>

class barraalta:public QStatusBar{

    Q_OBJECT
private:

        QWidget* padre;
        QLabel* messaggio;
public:
        barraalta(QWidget* =0);
public slots:
    void cambiamessaggio(QString);


};

#endif // BARRAALTA_H

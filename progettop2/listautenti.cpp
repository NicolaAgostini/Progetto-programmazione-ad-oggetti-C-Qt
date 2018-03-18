
#include"listautenti.h"

#include<QMessageBox>
#include<QDebug>
#include<QDir>


listautenti::listautenti():lista(){}

bool listautenti::aggiungi(utente* u){
    if(u){
    if(!trova(u->getnome())){
    lista.push_back(u->clone());
        return true;
    }
    }
    return false;//negli altri casi
}

utente* listautenti::trova(std::string n)const{
    for(std::list<utente*>::const_iterator ci=lista.begin();ci!=lista.end();ci++)
    {
        if((*ci)->utente::getnome()==n)
        {
            return *ci;
        }
    }
    return 0;
}
bool listautenti::trovato(const utente* a)const{
    if(a!=0)
    {
        for(std::list<utente*>::const_iterator ci=lista.begin();ci!=lista.end();ci++){
            if(*(*ci)==(*a))
            {
                return true;
            }
        }
    }
    return false;
}
bool listautenti::controllapw(const utente* a,std::string p){
    if(a){
        return a->getpass()==p;
    }
    return false;
}

void listautenti::modificapw(utente* a,std::string p){
    if(a)
    {
        a->cambiapass(p);
    }
}
void listautenti::pulisci(){
    if(*(lista.begin())!=0)
    {
        for(std::list<utente*>::const_iterator ci=lista.begin();ci!=lista.end();++ci)
        {
            delete *ci;
        }
        lista.erase(lista.begin(),lista.end());
    }
}

bool listautenti::inputdaxml(){
    pulisci();
    bool ok=false;
     QFile file("utenti.txt");


    if(!file.exists()){

        QMessageBox re;
        re.setText("Il file non esiste");
        re.exec();

        file.close();
        return false;

    }
    if(!file.open(QFile::ReadWrite | QFile::Text)){
        QMessageBox re;
        re.setText("Il file non è stato creato. Errore!");
        re.exec();

        file.close();
        return false;


           // exit(0);
        }




        QXmlStreamReader stream(&file);
        if(stream.readNextStartElement()){
        if(stream.name()=="Root"){

            while(stream.readNextStartElement()){

            std::string classe=(stream.name().toString().toStdString());//prendi il tag e controllaa che classe appatiene
            std::string nome;
            std::string pass;
            stream.readNextStartElement();
            nome=stream.readElementText().toStdString();//inserisci il nome
            stream.readNextStartElement();
            pass=stream.readElementText().toStdString();//inserisci la pass
            utente* a=0;

            if(classe=="Admin")
                a=new admin(nome,pass);

             if(classe=="Moderatore")
            a=new moderatore(nome,pass);

             if(classe=="Premium")
            a=new premium(nome,pass);

             if(classe=="Utentestd")
                a=new utentestd(nome,pass);

                //default inserisci errore

              if(a){


                  ok=true;
                  aggiungi(a);
                  delete a;
              }
              stream.skipCurrentElement();//salto il resto e passo al prossimo tag
              if(!a)
              {

              }

        }
        }
    }
    file.close();
    return ok;
}

void listautenti::outputinxml(){


    QString utefile="utenti.txt";
    QFile file(utefile);

    if (!file.open(QIODevice::WriteOnly))
        {
          QMessageBox::warning(0, "Error!", "Error opening file");
        }
    QXmlStreamWriter output(&file);
    output.writeStartElement("Root");
    for(std::list<utente*>::const_iterator ci=lista.begin();ci!=lista.end();ci++){
    (*ci)->utente::outputinxml(output);
    }
    output.writeEndElement();
    file.close();
}

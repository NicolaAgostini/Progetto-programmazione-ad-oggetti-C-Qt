#include"listacani.h"



listacani::listacani():vettore(){}
bool listacani::aggiungi(cani* a){
    if(a){
        vettore.push_back(a->clone());

        return true;

    }
    return false;
}

std::vector<cani*> listacani::cercanome(std::string n)const{
    std::vector<cani*> v;
    for(int i=0;i<(static_cast<int>(vettore.size()));i++)
    {
        if(vettore[i]->getnome()==n)
        {
            v.push_back(vettore[i]);
        }
    }
    return v;
}

cani* listacani::cercaindice(int i)const{
    return vettore[i];
}
bool listacani::cancellaindice(int i){
    if(static_cast<int>(vettore.size())<i)    //controllo se indice valido
    {
        return false;
    }

    vettore.erase(vettore.begin()+i);
    return true;
}

double listacani::calcolaanno()const{
    double tot=0;
    int y=0;
    for(int i=0;i<(static_cast<int>(vettore.size()));i++)
    {
       tot=tot+vettore[i]->getanno();
       y++;
    }
    if(tot)
    return tot/y;//media anni
    else return 0;
}

void listacani::ordina_sullanno(){
   std::sort(vettore.begin(), vettore.end(), [](const cani* a, const cani* b) { return a->getanno() < b->getanno(); });
}

void listacani::ordina_sulpeso(){
    std::sort(vettore.begin(), vettore.end(),
            [](const cani* a, const cani* b) {
                return (a->getpeso() < b->getpeso());
            });
}

void listacani::ordina_sulnome(){
    std::sort(vettore.begin(), vettore.end(),
            [](const cani* a, const cani* b) {
                return (a->getnome() < b->getnome());
            });
}


bool listacani::inputdaxml(){
   vettore.erase(vettore.begin(),vettore.end());
    bool ok=false;

    QFile file("cani.txt");

    if(!file.open(QFile::ReadWrite | QFile::Text)){
 QMessageBox::warning(0, "Error!", "Il file non è stato creato! Errore!");


 file.close();
 return false;
            //exit(0);
        }


        QXmlStreamReader stream(&file);


        if(stream.readNextStartElement()){
            if(stream.name()=="Root"){
                while(stream.readNextStartElement()){
            std::string classe=(stream.name().toString().toStdString());//prendi il tag e controlla a che classe appatiene

            cani* a=0;

            if (classe == "Poliziotto")
                   a= poliziotto::importaxml(stream);
                if (classe == "Bestiame")
                    a=bestiame::importaxml(stream);
                if (classe == "Guida")
                    a=guida::importaxml(stream);
                if (classe == "Sport")
                    a=sport::importaxml(stream);
                if (classe == "Caccia")
                    a=caccia::importaxml(stream);




              if(a){

                  ok=true;
                  listacani::aggiungi(a);

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
void listacani::outputinxml(){
     QFile file("cani.txt");

    if (!file.open(QIODevice::WriteOnly))
        {
          QMessageBox::warning(0, "Error!", "Error opening file");
        }
    QXmlStreamWriter output(&file);
    output.writeStartElement("Root");

    for(int i=0;i<(static_cast<int>(vettore.size()));i++){
        vettore[i]->cani::riempixml(output);
    }
    output.writeEndElement();
    file.close();
}



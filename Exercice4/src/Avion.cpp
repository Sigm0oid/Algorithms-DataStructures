#include "Avion.h"
#include <bits/stdc++.h>
using namespace std;
Avion::~Avion()
{
    //dtor
}
Avion::Avion(string id,string type,string etat){
    id=id;
    type=type;
    etat=etat;

    }
void Avion::changeEtat(string newetat){
    etat=newetat;
    return ;
    }
string    Avion::getEtat(){
    return etat;
    }
string Avion::getNom(){
    return id;
    }
void Avion:: description(){
    cout<<"description"<<endl;
    cout<< " id :"<<id<<endl;
    cout<< " etat :"<<etat<<endl;
    cout<< " type :"<<type<<endl;
    };

#include<bits/stdc++.h>
#ifndef AVION_H
#define AVION_H

using namespace std;

class Avion
{
    public:
    Avion(string id,string type,string etat);
    virtual ~Avion();
    void changeEtat(string etat );
    string getEtat();
    string getNom();
    void description();
    protected:
    string  id,type,etat;
    private:
};

#endif // AVION_H

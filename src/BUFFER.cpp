/// Programme LogisSim :
/// -------------------------------------------------
///
/// INFO 7-9-10
///
/// Date création : 23/03/2022
///
/// Date de dernière modification : 28/03/2022
///
/// Auteurs : Antonin CLAUD, Raphaël DE MAGALHAES
///
/// Polytech Clermont
///
#include "BUFFER.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

BUFFER::BUFFER():Composant("","U","U","U","BUFFER")
{
    noeud_A = "";
    noeud_S = "";
}

BUFFER::BUFFER(std::string nom, std::string A, std::string B, std::string S, std::string type, std::string noeud_A, std::string noeud_S):Composant(nom,A,B,S,type)
{
    this -> noeud_A = noeud_A;
    this -> noeud_S = noeud_S;
}

BUFFER::~BUFFER()
{
    cout << this << endl;
    cout << "Pas d'attribut alloue dynamiquement : le destructeur n'a rien a faire." << endl;
}

void BUFFER::propagation()
{
    if (A != "U")
    {
        this -> S = A;
    }
    else if (B != "U")
    {
        this -> S = B;
    }

}

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
#include "NOT.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

NOT::NOT():Composant("","U","U","U","NOT")
{
    noeud_A = "";
    noeud_S = "";
}

NOT::NOT(std::string nom, std::string A, std::string B, std::string S, std::string type, std::string noeud_A, std::string noeud_S):Composant(nom,A,B,S,type)
{
    this -> noeud_A = noeud_A;
    this -> noeud_S = noeud_S;
}

NOT::~NOT()
{
    cout << this << endl;
    cout << "Pas d'attribut alloue dynamiquement : le destructeur n'a rien a faire." << endl;
}

void NOT::propagation()
{
    if (A != "U")
    {
        if (this -> A == "0")
        {
            this -> S = "1";
        }
        else
        {
            this -> S = "0";
        }
    }
    else if (B != "U")
    {
        if (this -> B == "0")
        {
            this -> S = "1";
        }
        else
        {
            this -> S = "0";
        }
    }
}

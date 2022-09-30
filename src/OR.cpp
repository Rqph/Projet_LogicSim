/// Programme LogisSim :
/// -------------------------------------------------
///
/// INFO 7-9-10
///
/// Date cr�ation : 23/03/2022
///
/// Date de derni�re modification : 28/03/2022
///
/// Auteurs : Antonin CLAUD, Rapha�l DE MAGALHAES
///
/// Polytech Clermont
///
#include "OR.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

OR::OR():Composant("","U","U","U","OR")
{
    noeud_A = "";
    noeud_B = "";
    noeud_S = "";
}

OR::OR(std::string nom, std::string A, std::string B, std::string S, std::string type, std::string noeud_A, std::string noeud_B, std::string noeud_S):Composant(nom,A,B,S,type)
{
    this -> noeud_A = noeud_A;
    this -> noeud_B = noeud_B;
    this -> noeud_S = noeud_S;
}

OR::~OR()
{
    cout << this << endl;
    cout << "Pas d'attribut alloue dynamiquement : le destructeur n'a rien a faire." << endl;
}

void OR::propagation()
{
    if (this -> A == "1")
    {
        this -> S = "1";
    }
    else if (this -> B == "1")
    {
        this -> S = "1";
    }
    else
    {
        this -> S = "0";
    }
}

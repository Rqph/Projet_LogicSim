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
#include "NOR.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

NOR::NOR():Composant("","U","U","U","NOR")
{
    noeud_A = "";
    noeud_B = "";
    noeud_S = "";
}

NOR::NOR(std::string nom, std::string A, std::string B, std::string S, std::string type, std::string noeud_A, std::string noeud_B, std::string noeud_S):Composant(nom,A,B,S,type)
{
    this -> noeud_A = noeud_A;
    this -> noeud_B = noeud_B;
    this -> noeud_S = noeud_S;
}

NOR::~NOR()
{
    cout << this << endl;
    cout << "Pas d'attribut alloue dynamiquement : le destructeur n'a rien a faire." << endl;
}

void NOR::propagation()
{
    if ((this -> A == "0") && (this -> B == "0"))
    {
        this -> S = "1";
    }
    else
    {
        this -> S = "0";
    }
}

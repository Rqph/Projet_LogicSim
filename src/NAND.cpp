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
#include "NAND.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

NAND::NAND():Composant("","U","U","U","NAND")
{
    noeud_A = "";
    noeud_B = "";
    noeud_S = "";
}

NAND::NAND(std::string nom, std::string A, std::string B, std::string S, std::string type, std::string noeud_A, std::string noeud_B, std::string noeud_S):Composant(nom,A,B,S,type)
{
    this -> noeud_A = noeud_A;
    this -> noeud_B = noeud_B;
    this -> noeud_S = noeud_S;
}

NAND::~NAND()
{
    cout << this << endl;
    cout << "Pas d'attribut alloue dynamiquement : le destructeur n'a rien a faire." << endl;
}

void NAND::propagation()
{
    if (this -> A == "0")
    {
        this -> S = "1";
    }
    else if (this -> B == "0")
    {
        this -> S = "1";
    }
    else
    {
        this -> S = "0";
    }
}

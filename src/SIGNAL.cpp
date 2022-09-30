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
#include "SIGNAL.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;

SIGNAL::SIGNAL()
{
    nom = "";
    noeud = "";
    type = "";
    val = "";
}

SIGNAL::SIGNAL(std::string nom, std::string noeud, std::string type, std::string val)
{
    this -> nom = nom;
    this -> noeud = noeud;
    this -> type = type;
    this -> val = val;
}

SIGNAL::~SIGNAL()
{
    cout << this << endl;
    cout << "Pas d'attribut alloue dynamiquement : le destructeur n'a rien a faire." << endl;
}

void SIGNAL::Afficher()
{
    cout << "Informations du signal" << endl;
    cout << "Nom : " << nom << endl << "Noeud : " << noeud << endl <<
    "type : " << type << endl << "Valeur : " << val << endl;
}

void SIGNAL::propagation(Composant &porte)
{
    if (this -> type == "INPUT")
    {
        if (this -> noeud == porte.noeud_A)
        {
            porte.A = this -> val;
        }
        else if (this -> noeud == porte.noeud_B)
        {
            porte.B = this -> val;
        }
    }
    else if (this -> type == "OUTPUT")
    {
        if (this -> noeud == porte.noeud_A)
        {
            this -> val == porte.A;
        }
        else if (this -> noeud == porte.noeud_B)
        {
            this -> val = porte.B;
        }
    }
}

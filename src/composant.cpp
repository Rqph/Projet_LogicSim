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
#include <iostream>
#include "composant.h"
#include <string>
#include <stdlib.h>
using namespace std;

Composant::Composant()
{
    this -> nom = "";
    this -> A = "U";
    this -> B = "U";
    this -> S = "U";
    this -> type = "";
    cout << "Constructeur par defaut" << endl;
}

Composant::Composant(std::string nom, std::string A, std::string B, std::string S, std::string type)
{
    this -> nom = nom;
    this -> A = A;
    this -> B = B;
    this -> S = S;
    this -> type = type;
    cout << "Constructeur de surcharge" << endl;
}

Composant::~Composant()
{
     cout << "Pas d'attribut alloue dynamiquement : le destructeur n'a rien a faire." << endl;
}

void Composant::AffecterEntree(std::string niveau_logique1, std::string niveau_logique2)
{
    this -> A = niveau_logique1;
    this -> B = niveau_logique2;
}

void Composant::AffecterNoeud(std::string noeud_A, std::string noeud_B, std::string noeud_S)
{
    this -> noeud_A = noeud_A;
    this -> noeud_B = noeud_B;
    this -> noeud_S = noeud_S;
}

void Composant::Afficher()
{
    cout << "Informations du composant" << endl;
    cout << "Nom : " << nom << endl << "Entree A : " << A << endl <<
    "Entree B : " << B << endl << "Sortie : " << S << endl;
    cout << "Type de porte : " << type << endl;
    cout << "Noeud entree A : " << noeud_A << endl << "Noeud entree B : " << noeud_B << endl <<
    "Noeud sortie S : " << noeud_S << endl << endl;
}

void Composant::propa_signaux(Composant &porte2)
{
    // Propagation entrée A
    if (this -> noeud_A == porte2.noeud_A)
    {
        porte2.A = this -> A;
    }
    else if (this -> noeud_A == porte2.noeud_B)
    {
        porte2.B = this -> A;
    }
    else if (this -> noeud_A == porte2.noeud_S)
    {
        porte2.S = this -> A;
    }

    // Propagation entrée B
    if (this -> noeud_B == (porte2.noeud_A))
    {
        porte2.A = this -> B;
    }
    else if (this -> noeud_B == porte2.noeud_B)
    {
        porte2.B = this -> B;
    }
    else if (this -> noeud_B == porte2.noeud_S)
    {
        porte2.S = this -> B;
    }

    // Propagation sortie S
    if (this -> noeud_S == (porte2.noeud_A))
    {
        porte2.A = this -> S;
    }
    else if (this -> noeud_S == porte2.noeud_B)
    {
        porte2.B = this -> S;
    }
    else if (this -> noeud_S == porte2.noeud_S)
    {
        porte2.S = this -> S;
    }
}

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

#ifndef COMPOSANT_H_INCLUDED
#define COMPOSANT_H_INCLUDED
#include <stdlib.h>
#include <string>

///
/// Classe Composant
///
/// Diagramme UML :
///
/// |------------------------------------------|
/// |               Composant                  |
/// |------------------------------------------|
/// | + nom : string                           |
/// | + A : string                             |
/// | + B : string                             |
/// | + S : string                             |
/// | + noeud_A : string                       |
/// | + noeud_B : string                       |
/// | + noeud_S : string                       |
/// | + type : string                          |
/// |                                          |
/// |------------------------------------------|
/// | + Composant()                            |
/// | + ~Composant()                           |
/// | + Composant(string,string,string,string, |
/// |        string,string,string,string)      |
/// | + propagation : void                     |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// |------------------------------------------|
///

class Composant
{
    public :
        std::string nom;
        std::string A,B,S;
        std::string noeud_A;
        std::string noeud_B;
        std::string noeud_S;
        std::string type;

        Composant(); // Constructeur par défaut
        Composant(std::string nom, std::string A, std::string B, std::string S, std::string type); // Constructeur de surcharge
        ~Composant(); // Destructeur
        void AffecterEntree(std::string niveau_logique1, std::string niveau_logique2);
        void AffecterNoeud(std::string noeud_A,std::string noeud_B,std::string noeud_S);
        void Afficher();
        void propa_signaux(Composant &porte2);
};



#endif // COMPOSANT_H_INCLUDED

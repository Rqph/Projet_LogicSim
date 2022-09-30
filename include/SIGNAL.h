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
#ifndef SIGNAL_H_INCLUDED
#define SIGNAL_H_INCLUDED
#include <string>
#include "composant.h"

///
/// Classe SIGNAL
///
/// Diagramme UML :
///
/// |------------------------------------------|
/// |               SIGNAL                     |
/// |------------------------------------------|
/// | + nom : string                           |
/// | + noeud : string                         |
/// | + type : string                          |
/// | + val : string                           |
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

class SIGNAL
{
    public :
        std::string nom;
        std::string noeud;
        std::string type;
        std::string val;
        SIGNAL(); // Constructeur par défaut
        SIGNAL(std::string, std::string , std::string, std::string); // Constructeur de surcharge
        ~SIGNAL(); // Destructeur
        void Afficher();
        void propagation(Composant &porte);

};


#endif // SIGNAL_H_INCLUDED

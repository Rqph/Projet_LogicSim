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
#ifndef OR_H_INCLUDED
#define OR_H_INCLUDED
#include "composant.h"
#include <string>

///
/// Classe OR
///
/// Diagramme UML :
///
///
///         |    Composant   |
///         |----------------|
///         |      ....      |
///         |----------------|
///         |      ....      |
///         |----------------|
///                 ^
///                / \
///               /___\
///                 |
///                 |
///                 | (Héritage)
///                 |
///                 |
/// |------------------------------------------|
/// |         OR : Composant                   |
/// |------------------------------------------|
/// |                                          |
/// |                                          |
/// |------------------------------------------|
/// | + OR()                                   |
/// | + ~OR()                                  |
/// | + OR(string,string,string,string,        |
/// |        string,string,string,string)      |
/// | + propagation : void                     |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// |------------------------------------------|
///

class OR : public Composant
{
    public :
        OR(); // Constructeur par défaut
        OR(std::string, std::string , std::string, std::string, std::string, std::string, std::string, std::string); // Constructeur de surcharge
        ~OR(); // Destructeur
        void propagation();

};


#endif // OR_H_INCLUDED

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
#ifndef NOR_H_INCLUDED
#define NOR_H_INCLUDED
#include "composant.h"
#include <string>

///
/// Classe NOR
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
/// |         NOR : Composant                  |
/// |------------------------------------------|
/// |                                          |
/// |                                          |
/// |------------------------------------------|
/// | + NOR()                                  |
/// | + ~NOR()                                 |
/// | + NOR(string,string,string,string,       |
/// |        string,string,string,string)      |
/// | + propagation : void                     |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// |------------------------------------------|
///

class NOR : public Composant
{
    public :
        NOR(); // Constructeur par défaut
        NOR(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string); // Constructeur de surcharge
        ~NOR(); // Destructeur
        void propagation();

};

#endif // NOR_H_INCLUDED

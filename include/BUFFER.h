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
#ifndef BUFFER_H_INCLUDED
#define BUFFER_H_INCLUDED
#include "composant.h"
#include <string>

///
/// Classe BUFFER
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
/// |         BUFFER : Composant               |
/// |------------------------------------------|
/// |                                          |
/// |                                          |
/// |------------------------------------------|
/// | + BUFFER()                               |
/// | + ~BUFFER()                              |
/// | + BUFFER(string,string,string,string,    |
/// |        string,string,string)             |
/// | + propagation : void                     |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// |------------------------------------------|
///

class BUFFER : public Composant
{
    public :
        BUFFER(); // Constructeur par défaut
        BUFFER(std::string, std::string , std::string, std::string, std::string, std::string, std::string); // Constructeur de surcharge
        ~BUFFER(); // Destructeur
        void propagation();

};


#endif // BUFFER_H_INCLUDED

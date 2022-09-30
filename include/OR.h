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
///                 | (H�ritage)
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
        OR(); // Constructeur par d�faut
        OR(std::string, std::string , std::string, std::string, std::string, std::string, std::string, std::string); // Constructeur de surcharge
        ~OR(); // Destructeur
        void propagation();

};


#endif // OR_H_INCLUDED

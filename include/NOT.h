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
#ifndef NOT_H_INCLUDED
#define NOT_H_INCLUDED
#include "composant.h"
#include <string>
///
/// Classe NOT
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
/// |         NOT : Composant                  |
/// |------------------------------------------|
/// |                                          |
/// |                                          |
/// |------------------------------------------|
/// | + NOT()                                  |
/// | + ~NOT()                                 |
/// | + NOT(string,string,string,string,       |
/// |        string,string,string)             |
/// | + propagation : void                     |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// |------------------------------------------|
///

class NOT : public Composant
{
    public :
        NOT(); // Constructeur par d�faut
        NOT(std::string, std::string , std::string, std::string, std::string, std::string, std::string); // Constructeur de surcharge
        ~NOT(); // Destructeur
        void propagation();

};



#endif // NOT_H_INCLUDED

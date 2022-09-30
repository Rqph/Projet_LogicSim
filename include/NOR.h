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
///                 | (H�ritage)
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
        NOR(); // Constructeur par d�faut
        NOR(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string); // Constructeur de surcharge
        ~NOR(); // Destructeur
        void propagation();

};

#endif // NOR_H_INCLUDED

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
#ifndef AND_H_INCLUDED
#define AND_H_INCLUDED
#include "composant.h"
#include <string>

///
/// Classe AND
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
/// |         AND : Composant                  |
/// |------------------------------------------|
/// |                                          |
/// |                                          |
/// |------------------------------------------|
/// | + AND()                                  |
/// | + ~AND()                                 |
/// | + AND(string,string,string,string,       |
/// |        string,string,string,string)      |
/// | + propagation : void                     |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// |------------------------------------------|
///

class AND : public Composant
{
    public :
        AND(); // Constructeur par d�faut
        AND(std::string, std::string , std::string, std::string, std::string, std::string, std::string, std::string); // Constructeur de surcharge
        ~AND(); // Destructeur
        void propagation();

};


#endif // AND_H_INCLUDED

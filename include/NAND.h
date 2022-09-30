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
#ifndef NAND_H_INCLUDED
#define NAND_H_INCLUDED
#include "composant.h"
#include <string>

///
/// Classe NAND
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
/// |         NAND : Composant                 |
/// |------------------------------------------|
/// |                                          |
/// |                                          |
/// |------------------------------------------|
/// | + NAND()                                 |
/// | + ~NAND()                                |
/// | + NAND(string,string,string,string,      |
/// |        string,string,string,string)      |
/// | + propagation : void                     |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// | +                                        |
/// |------------------------------------------|
///

class NAND : public Composant
{
    public :
        NAND(); // Constructeur par défaut
        NAND(std::string, std::string, std::string, std::string, std::string, std::string, std::string, std::string); // Constructeur de surcharge
        ~NAND(); // Destructeur
        void propagation();

};



#endif // NAND_H_INCLUDED

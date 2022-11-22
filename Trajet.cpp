/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 06/10/2022
    copyright            : (C) 2022 par GAROUI et BOCANDE
    e-mail               : mathys.garoui(at)insa-lyon.fr, yvan.bocande(at)insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Trajet> (fichier Trajet.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//------------------------------------------------------ Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Trajet.h"

//----------------------------------------------------------------- PUBLIC

//-------------------------------------------- Constructeurs - destructeur

Trajet::Trajet()
{
#ifdef MAP
    cout << "Appel au constructeur de <Trajet>" << endl;
#endif
}

Trajet::~Trajet()
{
#ifdef MAP
    cout << "Appel au destructeur de <Trajet>" << endl;
#endif
}

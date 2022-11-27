/*************************************************************************
                           Trajet  -  description
                             -------------------
    début                : 06/10/2022
    copyright            : (C) 2022 par GAROUI et BOCANDE
    e-mail               : mathys.garoui(at)insa-lyon.fr, yvan.bocande(at)insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Trajet> (fichier Trajet.h) ----------------
#if ! defined ( TRAJET_H )
#define TRAJET_H

//--------------------------------------------------- Interfaces utilisées
#include <fstream>
using namespace std;

//------------------------------------------------------------------ Types
enum TypeTrajet { SIMPLE, COMPOSE, BOTH };

//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
// Cette classe abstraite représente un trajet.
// Elle définit des méthodes virtuelles pures qui seront implémentées dans les classes filles.
//
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual const char* GetDepart() const = 0;
    // Mode d'emploi :
    // Renvoie le point de départ du trajet. Doit être redéfini dans les classes filles.

    virtual const char* GetArrivee() const = 0;
    // Mode d'emploi :
    // Renvoie le point d'arrivée du trajet. Doit être redéfini dans les classes filles.

    virtual void Afficher() const = 0;
    // Mode d'emploi :
    // Affiche le trajet. Doit être redéfini dans les classes filles.

    virtual TypeTrajet GetTypeTrajet() const = 0;
    // Mode d'emploi :
    // Retourne le type de trajet

    virtual void Sauvegarder(ofstream & os) const = 0;
    // Mode d'emploi :
    // Sauvegarde le le trajet dans le fichier os
    //
    // @param os le fichier dans lequel écrire la sauvegarde

//-------------------------------------------- Constructeurs - destructeur

    Trajet(const Trajet & unTrajet);
    // Mode d'emploi (constructeur de copie)

    Trajet();

    virtual ~Trajet( );
    // Mode d'emploi :
    // Destructeur de la classe Trajet.
};


#endif // TRAJET_H

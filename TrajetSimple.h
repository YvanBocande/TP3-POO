/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 06/10/2022
    copyright            : (C) 2022 par GAROUI et BOCANDE
    e-mail               : mathys.garoui(at)insa-lyon.fr, yvan.bocande(at)insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetSimple> (fichier TrajetSimple.h) ----------------

#if ! defined ( TRAJET_SIMPLE_H )
#define TRAJET_SIMPLE_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------------ Types
//Définition d'un nouveau type appelé `MoyenTransport` qui peut prendre les valeurs `BATEAU`, `AVION`, `TRAIN` ou `AUTO`.
enum MoyenTransport {BATEAU,AVION, TRAIN, AUTO};

//------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// Cette classe permet de représenter un trajet simple.
// Elle est définit par un départ, une arrivée et un moyen de transport.
//------------------------------------------------------------------------

class TrajetSimple : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    const char *GetArrivee() const;
    // Mode d'emploi :
    // retourne la ville d'arrivé du trajet'

    const char *GetDepart() const;
    // Mode d'emploi :
    // retourne la ville de départ du trajet

    void Afficher() const;
    // Mode d'emploi :'
    //*
    // Il imprime la ville de départ, la ville d'arrivée et le moyen de transport
    //
    
    void CompterTypeTrajet(int & nbTss, int & nbTcs) const;

    void Sauvegarder(ofstream & os) const;

//-------------------------------------------- Constructeurs - destructeur

    TrajetSimple(const TrajetSimple & unTrajetSimple);
    // Mode d'emploi (constructeur de copie)

    TrajetSimple(const char *leDepart, const char *lArrive, MoyenTransport leTransport);
    // Mode d'emploi :
    //*
    // Il crée un nouvel objet TrajetSimple, et initialise ses attributs avec les valeurs des paramètres
    //
    // @param leDepart la ville de départ
    // @param lArrive la destination
    // @param leTransport le type de transport utilisé pour le voyage
    //

    virtual ~TrajetSimple ( );
    // Mode d'emploi :
    //*
    // Il supprime la mémoire allouée pour les chaînes départ et arrivée
    //




//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    char * depart;
    char * arrivee;
    MoyenTransport transport;


};


#endif // TRAJET_SIMPLE_H

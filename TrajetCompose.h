/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 06/10/2022
    copyright            : (C) 2022 par GAROUI et BOCANDE
    e-mail               : mathys.garoui(at)insa-lyon.fr, yvan.bocande(at)insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ----------------

#if ! defined ( TRAJET_COMPOSE_H )
#define TRAJET_COMPOSE_H

//--------------------------------------------------- Interfaces utilisées
#include "Collection.h"
#include "TrajetSimple.h"


//------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// Cette classe permet de créer un trajet composé à partir d'une collection de trajets simples.
// Elle hérite de la classe Trajet.
// Elle redéfinit les méthodes virtuelles pures de la classe Trajet.

//------------------------------------------------------------------------

class TrajetCompose : public Trajet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques



    const char* GetDepart() const;
    // Mode d'emploi :
    //*
    // Il renvoie la ville de départ du premier trajet de la collection
    //
    // @return La ville de départ du premier trajet de la collection.
    //

    const char* GetArrivee() const;
    // Mode d'emploi :
    //*
    // Il renvoie la ville d'arrivée du dernier Trajet de la collection
    //
    // @return La ville d'arrivée du dernier Trajet de la collection.
    //

    void Afficher() const;
    // Mode d'emploi :
    //*
    // Il affiche la ville de départ, la ville d'arrivée et les villes intermédiaires
    // On parcourt la collection et on affiche les villes de départ et d'arrivée de chaque trajet
    //


    void AjouterTrajet(TrajetSimple &t);
    // Mode d'emploi :
    //*
    // Il ajoute un trajet à la collection
    //
    // @param t Le trajet à ajouter
    //

    Trajet * GetTrajet(const int indice) const;
    // Mode d'emploi :
    //*
    // Il renvoie le pointeur vers l'objet Trajet à l'index donné dans la collection
    //
    // @param indice l'index du Trajet à retourner
    //
    // @return Un pointeur vers un objet Trajet.
    //

//-------------------------------------------- Constructeurs - destructeur

    TrajetCompose(const TrajetCompose & unTrajetCompose);
    // Mode d'emploi (constructeur de copie)

    TrajetCompose ();
    // Mode d'emploi :
    // Il crée un objet TrajetCompose vide

    virtual ~TrajetCompose ( );
    // Mode d'emploi :
    // Il détruit l'objet TrajetCompose

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Attributs protégés
    Collection col;


};


#endif // TRAJET_COMPOSE_H

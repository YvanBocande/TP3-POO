/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 06/10/2022
    copyright            : (C) 2022 par GAROUI et BOCANDE
    e-mail               : mathys.garoui(at)insa-lyon.fr, yvan.bocande(at)insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Catalogue> (fichier Catalogue.h) ----------------
#if ! defined ( CATALOGUE_H )
#define CATALOGUE_H

//--------------------------------------------------- Interfaces utilisées
#include "Collection.h"
#include "TrajetSimple.h"


//------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// Cette classe permet de stocker des trajets simples et des trajets composés dans une collection.
// POur cela on utilise des méthodes d'ajout et de recherche. qui permermettent d'ajouter des trajets simples et composés.
// Elle permet de rechercher des trajets simples et des trajets composés dans la collection.
// Elle permet d'afficher les trajets simples et les trajets composés de la collection.
// Cette classe permet aussi la navigation dans l'application. En effet, le menu est lancé depuis cette classe.

//------------------------------------------------------------------------

class Catalogue
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    void AjouterTrajet (Trajet & t);
    // Mode d'emploi :
    // Il ajoute un nouveau voyage à la collection.
    // Pour cela on utilise la méthode ajouter
    //
    // @param t Trajet &


    void Afficher ( ) const;
    // Mode d'emploi :
    // Affiche tous les trajets présents dans la callection du catalogue

    void LancementMenu();
    // Mode d'emploi :
    ///*
    // C'est un menu qui permet à l'utilisateur de créer un parcours simple ou complexe, de rechercher un parcours, ou
    // d'afficher le catalogue
    // Le menu utilise les méthode de la classe catalogue
    //
    // @return La valeur de retour est le nombre d'éléments du tableau.
    //





//-------------------------------------------- Constructeurs - destructeur

    Catalogue(const Catalogue & leCatalogue);
    // Mode d'emploi (constructeur de copie)

    Catalogue ();
    // Mode d'emploi :
    // INitialise le catalogue


    virtual ~Catalogue( );
    // Mode d'emploi :
    // Destructeur de la classe Catalogue


//------------------------------------------------------------------ PRIVE

protected:
//------------------------------------------------------- Méthodes protégées

    void creerTrajetCompose();
    // Mode d'emploi :
    ///
    // Il crée un objet TrajetCompose en demandant à l'utilisateur le parcours qu'il souhaite pour le trajet.
    // L'utilisateur peut rnetré autant d'étapes qu'il le souhaite.
    // Ensuite le trajet composé est ajouté au cataogue grâce à la méthode COllection   aujoutertrajet
    //

    void creerTrajetSimple();
    // Mode d'emploi :
    ///
    //Il demande à l'utilisateur es informations par rapport à un trajet simple.
    //IL crée ensuite un trajet simple et l'ajouter au catalogue grâce à la méthode ajouteTrajet
    //

    void rechercheParcours();
    // Mode d'emploi :
    //*
    // Il prend une ville de départ et une ville d'arrivée, et trouve tous les chemins possibles entre eux.
    // IL utilise nottament la méthode completerParcours de la classe catalogue

    void afficherCatalogue() const;
    // Mode d'emploi :
    // Affiche tous les trajets présents dans la callection du catalogue

    void selectionMoyenTransport(MoyenTransport &mt);
    // Mode d'emploi :
    //*
    // Il demande à l'utilisateur de choisir un mode de transport via le terminal et renvoie la valeur enum correspondante.
    //
    // @param mt une référence à une variable MoyenTransport.
    //

    void sauvegarder() const;

    void sauvegarderSansCritere(ofstream & os) const;

    void sauvegarderParType(ofstream & os) const;

    void sauvegarderParDepartArrivee(ofstream & os) const;

    void sauvegarderParSelection(ofstream & os) const;
    
    const bool lireCatalogue(char* nomFichier);

//----------------------------------------------------- Attributs protégés
    Collection col;


};

#endif // CATALOGUE_H

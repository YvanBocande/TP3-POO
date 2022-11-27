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
#include "TrajetCompose.h"


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

    void chargerParType(char* nomFichier);
    // Mode d'emploi :
    // demande à l'utilisateur de choisir un type de trajet à charger et lance lireCatalogue avec le bon type de trajet
    //
    // @param nomFichier le nom du fichier à charger
    //

    void chargerParDepartArrivee(char* nomFichier);
    // Mode d'emploi :
    //demande à l'utilisateur de choisir une ville de départ et une ville d'arrivée et lance lireCatalogue avec les bonnes villes
    //
    // @param nomFichier le nom du fichier à charger
    //

    void chargerParSelection(char* nomFichier);
    // Mode d'emploi :
    // demande à l'utilisateur de choisir l'interval de trajets à charger et lance lireCatalogueInterval avec les bonnes valeurs
    // il verifie que les valeurs sont correctes
    //
    // @param nomFichier le nom du fichier à charger
    //
    
    const void lireCatalogue(const char* nomFichier, const char* laVilleDep, const char* laVilleArr,const char type);
    // Mode d'emploi :
    //
    // lit le fichier nomFichier et ajoute les trajets correspondant aux critères de recherche
    // il utilise les méthodes lireTrajetSimple et lireTrajetCompose afin de charger les trajets
    //
    // @param nomFichier le nom du fichier à charger
    // @param villeDepRequis la ville de départ requise pour la selection, "*" si aucune ville de départ n'est requise
    // @param villeArrRequis la ville d'arrivée requise pour la selection, "*" si aucune ville d'arrivée n'est requise
    // @param type le type de trajet à charger, '*' si tous les types de trajets sont à charger


    const void lireCatalogueIntervalle(char* nomFichier, int indiceDepart, int indiceArrivee);
    // Mode d'emploi :
    //
    // lit le fichier nomFichier et ajoute les trajets correspondant à l'intervalle de trajets
    // il utilise les méthodes lireTrajetSimple et lireTrajetCompose afin de charger les trajets
    //
    // @param nomFichier le nom du fichier à charger
    // @param indiceDepart l'indice du premier trajet à charger
    // @param indiceArrivee l'indice du dernier trajet à charger

    TrajetSimple* chargerTrajetSimple(ifstream &monFlux,const char* villeDepRequis, const char* villeArrRequis);
    // Mode d'emploi :
    //
    // lit la ligne du fichier et crée un trajet simple si les villes correspondent aux critères de recherche
    //
    // @param monFlux le flux de lecture du fichier
    // @param villeDepRequis la ville de départ requise pour la selection, "*" si aucune ville de départ n'est requise
    // @param villeArrRequis la ville d'arrivée requise pour la selection, "*" si aucune ville d'arrivée n'est requise
    // @return un pointeur sur un trajet simple ou NULL si le trajet ne correspond pas aux critères de recherche
    //

    TrajetCompose* chargerTrajetCompose(ifstream &fmonFlux, const char* villeDepRequis, const char* villeArrRequis);
    // Mode d'emploi :
    //
    //
    // lit la ligne du fichier et crée un trajet composé si les villes correspondent aux critères de recherche
    // 
    // @param monFlux le flux de lecture du fichier
    // @param villeDepRequis la ville de départ requise pour la selection, "*" si aucune ville de départ n'est requise
    // @param villeArrRequis la ville d'arrivée requise pour la selection, "*" si aucune ville d'arrivée n'est requise
    // @return un pointeur sur un trajet composé ou NULL si le trajet ne correspond pas aux critères de recherche

    const void charger();
    // Mode d'emploi :
    //
    // demande à l'utilisateur le nom du fichier de sauvegarde, vérifiz qu'il existe et demande le type de chargement
    // il lance ensuite la bonne méthode en fonction du choix de l'utilisateur


    const int lireNbTrajetsFichier(char* nomFichier);
    // Mode d'emploi :
    //
    // lit le fichier nomFichier et renvoie le nombre de trajets qu'il contient dans les métadonnées
    //
    // @param nomFichier le nom du fichier à charger
//----------------------------------------------------- Attributs protégés
    Collection col;


};

#endif // CATALOGUE_H

/*************************************************************************
                           Collection  -  description
                             -------------------
    début                : 06/10/2022
    copyright            : (C) 2022 par GAROUI et BOCANDE
    e-mail               : mathys.garoui(at)insa-lyon.fr, yvan.bocande(at)insa-lyon.fr
*************************************************************************/

//---------- Interface de la classe <Collection> (fichier Collection.h) ----------------

#if ! defined ( COLLECTION_H )
#define COLLECTION_H

//--------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//------------------------------------------------------------- Constantes
const int MAX = 10;

//------------------------------------------------------------------------
// Rôle de la classe <Collection>
// Cette classe permet de stocker des trajets dans un tableau dynamique.
// Elle permet de les ajouter, de les supprimer et de les afficher.
// On peut effectuer toutes sortes d'opérations sur le tableau dynamique: recherche de parcours et de trajet par exemple
//
//------------------------------------------------------------------------

class Collection
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool AjouterTrajet(Trajet & t);
    // Mode d'emploi :
     //
     // Il ajoute un nouvel élément au tableau, et si le tableau est plein, il crée un nouveau tableau deux fois plus grand et y
     // copie les anciens éléments
     //
     // @param t le Trajet à ajouter à la collection
     //
     // @return Une valeur booléenne.
     //

    Trajet * GetTrajet(const int indice) const;
    // Mode d'emploi :
    //
    //Il renvoie le pointeur vers l'objet Trajet à l'index donné
    //
    // @param indice l'indice du Trajet que vous souhaitez obtenir
    //
    // @return Un pointeur vers un objet Trajet.
    //

    int GetNbTrajet() const;
    //
    // GetNbTrajet renvoie le nombre d'objets Trajet dans l'objet Collection
    //
    // @return Le nombre de Trajet dans la collection.
    //

    void Afficher() const;
    // Mode d'emploi : Affiche les trajets qui sont dans la collection

//-------------------------------------------- Constructeurs - destructeur

    Collection (const Collection & uneCollection);
    // Mode d'emploi (constructeur de copie)


    Collection (const int tailleMax = MAX);
    // Mode d'emploi :
    // Il crée une nouvelle collection avec une taille maximale de laTailleMax
    // Le tableau est initialisé avec la taille max renseigné*
    // @param laTailleMax la taille maximale de la collection


    virtual ~Collection( );
    // Mode d'emploi :
    // On supprimer tous les éléments du tableau de pointeurs de trjats pour un supprimer le tableau


protected:
//----------------------------------------------------- Attributs protégés
    Trajet ** elements;
    int tailleMax;
    int tailleActuelle;

};


#endif // COLLECTION_H

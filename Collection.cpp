/*************************************************************************
                           Collection  -  description
                             -------------------
    début                : 06/10/2022
    copyright            : (C) 2022 par GAROUI et BOCANDE
    e-mail               : mathys.garoui(at)insa-lyon.fr, yvan.bocande(at)insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Collection> (fichier Collection.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Collection.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

bool Collection::AjouterTrajet(Trajet & t)
//Algorithme :
//Si la taille de la collection n'est pas suffisante, agrandit la collection
//Ajoute le trajet t en paramètre à la collection elements
{
    if (tailleActuelle == tailleMax)
    {
        Trajet ** newElements = new Trajet*[tailleMax*2];
        for (int i = 0; i < tailleMax; i++)
        {
            newElements[i] = elements[i];
        }

        tailleMax *= 2;

        delete [] elements;
        elements = newElements;
    }

    elements[tailleActuelle] = &t;
    tailleActuelle++;
    return true;
} // Fin de AjouterTrajet


Trajet * Collection::GetTrajet(const int indice) const
{
    return elements[indice];
} // Fin de GetTrajet


int Collection::GetNbTrajet() const
{
    return tailleActuelle;
} // Fin GetNbTrajet


void Collection::Afficher() const{
    for (int i = 0; i < tailleActuelle ; ++i)
    {
        cout << i + 1 << "- ";
        elements[i]->Afficher();
        cout << endl;
    }
} //Fin de Afficher

void Collection::CompterTypeTrajets(int & nbTss, int & nbTcs) const{
    for(int i = 0; i < tailleActuelle; i++){
        elements[i]->CompterTypeTrajet(nbTss, nbTcs);
    }
}

void Collection::Sauvegarder(ofstream & os) const
{
    for(int i = 0; i < tailleActuelle; i++){
        elements[i]->Sauvegarder(os);
    }
}

//-------------------------------------------- Constructeurs - destructeur


Collection::Collection(const int laTailleMax)
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>" << endl;
#endif

    tailleActuelle = 0;
    tailleMax = laTailleMax;
    elements = new Trajet * [tailleMax];
} //----- Fin de Collection

Collection::~Collection()
{

#ifdef MAP
    cout << "Appel au destructeur de <Collection>" << endl;
#endif
    for (int i = 0; i < tailleActuelle; ++i)
    {
        delete elements[i];
    }
    delete [] elements;
} //----- Fin de ~Collection

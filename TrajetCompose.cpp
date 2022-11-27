/*************************************************************************
                           TrajetCompose  -  description
                             -------------------
    début                : 06/10/2022
    copyright            : (C) 2022 par GAROUI et BOCANDE
    e-mail               : mathys.garoui(at)insa-lyon.fr, yvan.bocande(at)insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetCompose> (fichier TrajetCompose.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetCompose.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

const char * TrajetCompose::GetArrivee() const
{
    int nbTrajet = col.GetNbTrajet();
    return col.GetTrajet(nbTrajet-1)->GetArrivee();
}


const char * TrajetCompose::GetDepart() const
{
    return col.GetTrajet(0)->GetDepart();
}


void TrajetCompose::Afficher() const
{
    cout << "Départ : " << GetDepart() << ", arrivée : " << GetArrivee() << ", étapes : ";

    for(int i = 0; i < col.GetNbTrajet() ; i++)
    {
        cout << endl << "\t- ";
        col.GetTrajet(i)->Afficher();
    }
}

void TrajetCompose::AjouterTrajet(TrajetSimple & t)
{
    col.AjouterTrajet(t);
}


Trajet *TrajetCompose::GetTrajet(const int indice) const
{
    return col.GetTrajet(indice);
}

TypeTrajet TrajetCompose::GetTypeTrajet() const
{
   return COMPOSE;
}

void TrajetCompose::Sauvegarder(ofstream & os) const
{
    os << "c;" << GetDepart() << ";" << GetArrivee() << ";" << col.GetNbTrajet() << endl;
    col.Sauvegarder(os, BOTH, "", "", 0, col.GetNbTrajet(), false);
}


//-------------------------------------------- Constructeurs - destructeur

TrajetCompose::TrajetCompose()
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
}

TrajetCompose::~TrajetCompose ()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
}

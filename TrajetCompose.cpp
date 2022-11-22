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
    cout << "Ville de Départ : " << GetDepart() << ", ville d'arrivée : " << GetArrivee() << ", villes intermédiaires : ( " ;
    for(int i = 0; i < col.GetNbTrajet() ; i++)
    {
        col.GetTrajet(i)->Afficher();
        if(i != col.GetNbTrajet() - 1){
            cout << ", ";
        }
    }
    cout << ")";
}

void TrajetCompose::AjouterTrajet(TrajetSimple & t)
{
    col.AjouterTrajet(t);
}


Trajet *TrajetCompose::GetTrajet(const int indice) const
{
    return col.GetTrajet(indice);
}

void TrajetCompose::Sauvegarder(ostream os) const
{
    
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

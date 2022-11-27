/*************************************************************************
                           TrajetSimple  -  description
                             -------------------
    début                : 06/10/2022
    copyright            : (C) 2022 par GAROUI et BOCANDE
    e-mail               : mathys.garoui(at)insa-lyon.fr, yvan.bocande(at)insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <TrajetSimple> (fichier TrajetSimple.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "TrajetSimple.h"

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void TrajetSimple::Afficher() const
{
    cout << "Départ : " << depart << ", arrivée : " << arrivee << ", moyen de transport : ";
    switch (transport) {
        case MoyenTransport::AVION:
            cout << "Avion";
            break;
        case MoyenTransport::BATEAU:
            cout << "Bateau";
            break;
        case MoyenTransport::AUTO:
            cout << "Voiture";
            break;
        case MoyenTransport::TRAIN:
            cout << "Train";
            break;
    }
} // Fin de Afficher

const char * TrajetSimple::GetDepart() const
{
    return depart;
}// Fin de GetDepart

const char * TrajetSimple::GetArrivee() const
{
    return arrivee;
} // Fin de GetArrivee

TypeTrajet TrajetSimple::GetTypeTrajet() const{
    return SIMPLE;
} // Fin de GetTypeTrajet

void TrajetSimple::Sauvegarder(ofstream & os) const
{
    os << "s;" << depart << ";" << arrivee << ";" << transport << endl;
} // Fin de Sauvegarder

//-------------------------------------------- Constructeurs - destructeur


TrajetSimple::TrajetSimple(const char *leDepart, const char *lArrive, MoyenTransport leTransport) : transport(leTransport)
{
#ifdef MAP
    cout << "Appel au constrcuteur de <TrajetSimple>" << endl;
#endif
    depart = new char[strlen(leDepart)+1];
    strcpy(depart, leDepart);
    arrivee = new char[strlen(lArrive)+1];
    strcpy(arrivee, lArrive);
} // Fin de TrajetSimple


TrajetSimple::~TrajetSimple ()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete [] depart;
    delete [] arrivee;
} //----- Fin de ~TrajetSimple

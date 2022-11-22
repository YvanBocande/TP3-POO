/*************************************************************************
                           Catalogue  -  description
                             -------------------
    début                : 06/10/2022
    copyright            : (C) 2022 par GAROUI et BOCANDE
    e-mail               : mathys.garoui(at)insa-lyon.fr, yvan.bocande(at)insa-lyon.fr
*************************************************************************/

//---------- Réalisation de la classe <Catalogue> (fichier Cotalogue.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Catalogue.h"
#include "TrajetCompose.h"

//------------------------------------------------------------- Constantes
const int tailleMaxNomVille = 58 + 1;

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

void Catalogue::AjouterTrajet(Trajet & t)
{
    col.AjouterTrajet(t);
} // Fin de AjouterTrajet

void Catalogue::Afficher() const
{
    int nbTrajets = col.GetNbTrajet();
    if(nbTrajets == 0){
        cout << "Aucun trajet dans le catalogue..." << endl;
    }
    else{
        cout << nbTrajets << " trajet" << ((nbTrajets > 1) ? "s" : "") << " trouvé"
            << ((nbTrajets > 1) ? "s" : "") << " dans le catalogue : " << endl << endl;
        col.Afficher();
    }
} // Fin de Afficher

void Catalogue::LancementMenu()
//Algorithme :
//Dans une boucle infinie, le menu demande à l'utilisateur l'interacton souhaitée
{
    for(;;)
    {
        cout << endl << "Menu : " << endl;
        cout << "\t1: Créer trajet simple" << endl;
        cout << "\t2: Créer Trajet composé" << endl;
        cout << "\t3: Rechercher un parcours" << endl;
        cout << "\t4: Afficher le catalogue" << endl;
        cout << "\t0 : Quitter" << endl;
        int choix;
        cin >> choix;
        switch (choix) {
            case 0:
                cout << "Au revoir !";
                return;
            case 1:
                creerTrajetSimple();
                break;
            case 2:
                creerTrajetCompose();
                break;
            case 3:
                rechercheParcours();
                break;
            case 4:
                afficherCatalogue();
                break;

            default:
                cout << "Choix incorrect";
                continue; // revenir au menu
        }
    }
} // Fin de LancementMenu

//-------------------------------------------- Constructeurs - destructeur

Catalogue::Catalogue ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Catalogue>" << endl;
#endif
} //----- Fin de Catalogue

Catalogue::~Catalogue()
{
#ifdef MAP
    cout << "Appel au destructeur de <Catalogue>" << endl;
#endif
} //----- Fin de ~Catalogue



//------------------------------------------------------------------ PRIVE

//------------------------------------------------------- Méthodes protégées

void Catalogue::afficherCatalogue() const
{
    Afficher();
}// Fin de afficherCatalogue

void Catalogue::rechercheParcours()
{
    char temp[tailleMaxNomVille];
    char *villeDep;
    char * villeArr;

    cout << "Renseignez la ville de départ" << endl;
    cin.ignore();
    cin.getline(temp, tailleMaxNomVille);
    villeDep = new char[strlen(temp) + 1];
    strcpy(villeDep, temp);

    cout << "Renseignez la ville d'arrivée" << endl;
    cin.getline(temp, tailleMaxNomVille);
    villeArr = new char[strlen(temp) + 1];
    strcpy(villeArr, temp);

    int nbParcours = 0;
    int nbTrajets = col.GetNbTrajet();

    for (int i = 0; i < nbTrajets; ++i)
    {
        if(strcmp(villeDep, col.GetTrajet(i)->GetDepart()) == 0
            && strcmp(villeArr, col.GetTrajet(i)->GetArrivee()) == 0)
        {
            cout << ++nbParcours << "- ";
            col.GetTrajet(i)->Afficher();
            cout << endl;
        }
    }

    delete [] villeArr;
    delete [] villeDep;

} //Fin de rechercheParcours

void Catalogue::selectionMoyenTransport(MoyenTransport & mt)
//Algorithme :
//Tant que la valeur entrée est invalide, demande à l'utilisateur un chiffre,
// le vérifie et assigne à mt le moyen de transport souhaité
{
    char choixTransportInput[100];
    int choixTransport = 0;
    bool transportValide = false;
    while (!transportValide)
    {
        cout << "Choisissez un moyen de transport" << endl << "\t1 : Bateau" << endl << "\t2 : Avion"
             << endl << "\t3 : Train" << endl << "\t4 : Auto" << endl;

        cin >> choixTransportInput;
        if(strlen(choixTransportInput)==1 && choixTransportInput[0] <= '9' && choixTransportInput[0] >= '0')
        {
            choixTransport = atoi(choixTransportInput);
        }
        transportValide = true;
        switch (choixTransport)
        {
            case 1:
                mt = BATEAU;
                break;
            case 2:
                mt = AVION;
                break;
            case 3:
                mt = TRAIN;
                break;
            case 4:
                mt = AUTO;
                break;
            default:
                transportValide = false;
                cout << "Mauvais choix" << endl;
                break;
        }
    }
}// Fin de selectionMoyenTransport


void Catalogue::creerTrajetSimple()
//Algorithme :
//Demande une ville de départ, d'arrivée et un moyen de transport et
// instancie un TrajetSimple qui sera ajouté à la collection du catalogue
{
    char temp[tailleMaxNomVille];
    char *villeDep;
    char * villeArr;

    cout << "Renseignez la ville de départ" << endl;
    cin.ignore();
    cin.getline(temp, tailleMaxNomVille);
    villeDep = new char[strlen(temp) + 1];
    strcpy(villeDep, temp);

    cout << "Renseignez la ville d'arrivée" << endl;
    cin.getline(temp, tailleMaxNomVille);
    villeArr = new char[strlen(temp) + 1];
    strcpy(villeArr, temp);

    MoyenTransport moyenTransport;
    selectionMoyenTransport(moyenTransport);

    TrajetSimple * t = new TrajetSimple(villeDep, villeArr, moyenTransport);
    AjouterTrajet(*t);
    delete [] villeDep;
    delete [] villeArr;

}// Fin de creerTrajetSimple


void Catalogue::creerTrajetCompose()
//Algorithme :
//En premier lieu, instancie 2 TrajetSimple qui seront ajouté au TrajetCompose, puis dans une boucle,
// tant que l'utilisateur souhaite rajouter des villes, fabrique un TrajetSimple puis l'ajoute au TrajetCompose
{
    /* Créer un nouvel objet TrajetCompose puis demander à l'utilisateur d'entrer les trois premières villes du trajet composé. */
    TrajetCompose * tc = new TrajetCompose();
    char villeDep[tailleMaxNomVille];
    char villeArr[tailleMaxNomVille];
    int choix;
    MoyenTransport mt;
    cout << "Entre le point de départ" << endl;
    cin >> villeDep;
    cout << "Entrez une étape" << endl;
    cin >> villeArr;
    selectionMoyenTransport(mt);
    TrajetSimple * ts1 = new TrajetSimple(villeDep, villeArr, mt);
    tc->AjouterTrajet(*ts1);
    strcpy(villeDep, villeArr);
    cout << "Entrez une étape" << endl;
    cin >> villeArr;
    selectionMoyenTransport(mt);
    TrajetSimple * ts2 = new TrajetSimple(villeDep, villeArr, mt);
    tc->AjouterTrajet(*ts2);

    /* Boucle qui permet de rentrer n villes supplémentaires */
    for(;;)
    {
        cout << "Souhaitez vous ajouter une étape ?" << endl;
        cout << "\t 1 : Non" << endl;
        cout << "\t 2 : Oui" << endl;
        cin >> choix;
        if(choix == 1)
        {
            break;
        }
        else if (choix == 2)
        {
            cout << "Entrez une étape" << endl;
            strcpy(villeDep, villeArr);
            cin >> villeArr;
            selectionMoyenTransport(mt);
            TrajetSimple * ts = new TrajetSimple(villeDep, villeArr, mt);
            tc->AjouterTrajet(*ts);
        }
        else {
            cout << "Choix erronné" << endl;
        }
    }
    AjouterTrajet(*tc);
}

const bool Catalogue::lireCatalogue(char* nomFichier)
{
    ifstream monFlux(nomFichier);

    if(monFlux)
    {
        char tmp;
        int nbTs;
        int nbTc;
        monFlux >> nbTs;
        monFlux >> tmp;
        monFlux >> nbTc;
        cout << "nbTs : " << nbTs << endl;
        cout << "nbTc : " << nbTc << endl;
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}
//----- Fin de creerTrajetCompose


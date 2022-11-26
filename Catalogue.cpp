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
#include <fstream>
#include <string>
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
        cout << "\t5: Sauvegarde" << endl;
        cout << "\t6: Charger" << endl;
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
            case 5:
                sauvegarder();
                break;
            case 6:
                charger();
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

const void Catalogue::charger()
{
    lireCatalogue("./data/exemple.data", "*","*");
}

const bool Catalogue::lireCatalogue(char* nomFichier, char* laVilleDep, char* laVilleArr)
{
    ifstream monFlux(nomFichier);

    if(monFlux)
    {
        char tmp;
        int nbTs;
        int nbTc;
        int nbTrajetslus = 0;
        monFlux >> nbTs;
        monFlux >> tmp;
        monFlux >> nbTc;        
        cout << "nbTs : " << nbTs << endl;
        cout << "nbTc : " << nbTc << endl;

        string typeTrajet;
        string villeDep;
        string villeArr;
        string moyenTransport;
        while(getline(monFlux,  typeTrajet, ';') &&  getline(monFlux, villeDep, ';') && getline(monFlux, villeArr, ';') && getline(monFlux, moyenTransport))
        {
            if(nbTrajetslus==0)
            {
                typeTrajet = typeTrajet.substr(1);
            }

            MoyenTransport mt = static_cast<MoyenTransport>(stoi(moyenTransport));

            if(typeTrajet == "s")
            {
                TrajetSimple *ts = chargerTrajetSimple(villeDep, villeArr, mt);
                AjouterTrajet(*ts);
            } else {
                chargerTrajetCompose(villeDep, villeArr, moyenTransport, monFlux);
            }

            nbTrajetslus++;
        }
        
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}

TrajetSimple* Catalogue::chargerTrajetSimple(string villeDepart, string villeArrive, MoyenTransport moyenTransport)
{
    const char* vd = villeDepart.c_str();
    const char* va = villeArrive.c_str();
    TrajetSimple *ts = new TrajetSimple(vd, va, moyenTransport);
    return ts;
}

const bool Catalogue::chargerTrajetCompose(string villeDepart, string villeArrive, string nbTrajets, ifstream &fichier)
{
    for(int i = 0; i < stoi(nbTrajets); i++)
    {
        string typeTrajet;
        string villeDep;
        string villeArr;
        string moyenTransport;
        getline(fichier,  typeTrajet, ';');
        getline(fichier, villeDep, ';');
        getline(fichier, villeArr, ';');
        getline(fichier, moyenTransport);
        MoyenTransport mt = static_cast<MoyenTransport>(stoi(moyenTransport));
    }
}
//----- Fin de creerTrajetCompose

void Catalogue::sauvegarder() const
{
    char nomDuFichier[tailleMaxNomVille];
    cout << "Entrez le nom du fichier de sauvegarde" << endl;
    cin >> nomDuFichier;

    char cheminDuFichier[tailleMaxNomVille + 10] = "./data/";

    strcat(cheminDuFichier, nomDuFichier);

    ofstream os;
    os.open(cheminDuFichier);

    for(;;)
    {
        int choix;

        cout << "Type de sauvegarde :" << endl;
        cout << "\t 1 : Sans critère de sélecetion" << endl;
        cout << "\t 2 : Selon le type" << endl;
        cout << "\t 3 : Selon le départ et / ou l'arrivée" << endl;
        cout << "\t 4 : Selon une sélection" << endl;

        if(cin >> choix){
            if(choix == 1){
                sauvegarderSansCritere(os);
                break;
            }else if(choix == 2){
                sauvegarderParType(os);
                break;
            }else if(choix == 3){
                sauvegarderParDepartArrivee(os);
                break;    
            }else if(choix == 4){
                sauvegarderParSelection(os);
                break;
            }else{
                cout << "Choix erronné";
            }
        }else{
            cout << "Error";
        }
    }

    os.close();
}

void Catalogue::sauvegarderSansCritere(ofstream & os) const
{
    col.Sauvegarder(os, BOTH, "", "", 0, col.GetNbTrajet());
}

void Catalogue::sauvegarderParType(ofstream & os) const
{
    int choix;

    for(;;)
    {
        cout << "Quel type sauvegarder :" << endl;
        cout << "\t 1 : Trajets simples" << endl;
        cout << "\t 2 : Trajet composes" << endl;
        cin >> choix;

        switch(choix){
            case 1:
                break;
            case 2:
                break;
            default:
                cout << "Choix erronné" << endl;
                continue;
        }

        break;
    }

    TypeTrajet typeTrajet = SIMPLE;

    if(choix == 2){
        typeTrajet = COMPOSE;
    }

    col.Sauvegarder(os, typeTrajet, "", "", 0, col.GetNbTrajet());
}

void Catalogue::sauvegarderParDepartArrivee(ofstream & os) const{
    int choixDepart;
    char depart[tailleMaxNomVille];
    char arrivee[tailleMaxNomVille];

    for(;;)
    {
        cout << "Voulez vous indiquer une ville de départ ?" << endl;
        cout << "\t 1 : Oui" << endl;
        cout << "\t 2 : Non" << endl;
        cin >> choixDepart;

        switch(choixDepart){
            case 1:
                break;
            case 2:
                break;
            default:
                cout << "Choix erronné" << endl;
                continue;
        }

        break;
    }

    int choixArrivee = choixDepart == 2 ? 1 : 2;

    if(choixDepart == 1){
        cout << "Indiquez la ville de départ :" << endl;
        cin >> depart;

        for(;;)
        {
            cout << "Voulez vous indiquer une ville d'arrivée ?" << endl;
            cout << "\t 1 : Oui" << endl;
            cout << "\t 2 : Non" << endl;
            cin >> choixArrivee;

            switch(choixArrivee){
                case 1:
                    break;
                case 2:
                    break;
                default:
                    cout << "Choix erronné" << endl;
                    continue;
            }

            break;
        }
    }else{
        depart[0] = '\0';
    }

    if(choixArrivee == 1){
        cout << "Indiquez la ville d'arrivée :" << endl;
        cin >> arrivee;
    }else{
        arrivee[0] = '\0';
    }

    col.Sauvegarder(os, BOTH, depart, arrivee, 0, col.GetNbTrajet());
}

void Catalogue::sauvegarderParSelection(ofstream & os) const
{
    int nbTrajets = col.GetNbTrajet();

    int startIndex;

    for(;;)
    {
        cout << "Indiquez l'indice n du début de l'intervalle (entre 1 et " << nbTrajets << ") :" << endl;
        cin >> startIndex;

        if(startIndex < 1){
            cout << "Indice trop petit" << endl;
            continue;
        }else if(startIndex > nbTrajets){
            cout << "Indice trop grand" << endl;
            continue;
        }

        break;
    }

    int endIndex;

    for(;;)
    {
        cout << "Indiquez l'indice m de la fin de l'intervalle (entre " << startIndex << " et " << nbTrajets << ") :" << endl;
        cin >> endIndex;

        if(endIndex < startIndex){
            cout << "Indice trop petit" << endl;
            continue;
        }else if(startIndex > nbTrajets){
            cout << "Indice trop grand" << endl;
            continue;
        }

        break;
    }

    col.Sauvegarder(os, BOTH, "", "", startIndex - 1, endIndex);
}

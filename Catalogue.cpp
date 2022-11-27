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
        cout << "\t0: Quitter" << endl;
        int choix;
        cin >> choix;
        switch (choix) {
            case 0:
                cout << "Au revoir !" << endl;
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
    char nomDuFichier[tailleMaxNomVille];
    cout << "Entrez le nom du fichier de sauvegarde" << endl;
    cin >> nomDuFichier;

    char cheminDuFichier[tailleMaxNomVille + 10] = "./data/";

    strcat(cheminDuFichier, nomDuFichier);

    ifstream fluxTest(cheminDuFichier);

    if(fluxTest)
    {
        fluxTest.close();
        for(;;)
        {
            int choix;

            cout << "Type de chargement :" << endl;
            cout << "\t 1 : Sans critère de sélecetion" << endl;
            cout << "\t 2 : Selon le type" << endl;
            cout << "\t 3 : Selon le départ et / ou l'arrivée" << endl;
            cout << "\t 4 : Selon un interval" << endl;

            if(cin >> choix){
                if(choix == 1){
                    lireCatalogue(cheminDuFichier, "*", "*", '*');
                    break;
                }else if(choix == 2){
                    chargerParType(cheminDuFichier);
                    break;
                }else if(choix == 3){
                    chargerParDepartArrivee(cheminDuFichier);
                    break;    
                }else if(choix == 4){
                    chargerParSelection(cheminDuFichier);
                    break;
                }else{
                    cout << "Choix erronné";
                }
            }else{
                cout << "Error";
            }
        }
    } else {
        cout << "Le fichier n'existe pas" << endl;
    }
}

void Catalogue::chargerParType(char* nomFichier)
{
    int choix;

    for(;;)
    {
        cout << "Quel type charger :" << endl;
        cout << "\t 1 : Trajets simples" << endl;
        cout << "\t 2 : Trajet composes" << endl;
        cin >> choix;

        switch(choix){
            case 1:
                lireCatalogue(nomFichier, "*", "*", 's');
                break;
            case 2:
                lireCatalogue(nomFichier, "*", "*", 'c');
                break;
            default:
                cout << "Choix erronné" << endl;
                continue;
        }

        break;
    }
}

void Catalogue::chargerParDepartArrivee(char* nomFichier)
{
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
        depart[0] = '*';
        depart[1] = '\0';
    }

    if(choixArrivee == 1){
        cout << "Indiquez la ville d'arrivée :" << endl;
        cin >> arrivee;
    }else{
        arrivee[0] = '*';
        arrivee[1] = '\0';
    }

    lireCatalogue(nomFichier, depart, arrivee, '*');
}

void Catalogue::chargerParSelection(char* nomFichier)
{
    int nbTrajets = lireNbTrajetsFichier(nomFichier);

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

    lireCatalogueIntervalle(nomFichier, startIndex-1, endIndex-1);
}

const int Catalogue::lireNbTrajetsFichier(char* nomFichier){
    ifstream flux(nomFichier);

    if(flux)
    {
        char tmp;
        int nbTs;
        int nbTc;


        flux >> nbTs;
        flux >> tmp;
        flux >> nbTc;

        return nbTs + nbTc;
        flux.close();
        
    }else{
        cout << "Erreur lors de l'ouverture du fichier" << endl;
        return 0;
    }
    return 0;
}

const void Catalogue::lireCatalogue(const char* nomFichier, const char* villeDepRequis, const char* villeArrRequis, const char type)
{
    ifstream monFlux(nomFichier);

    if(monFlux)
    {
        char tmp;
        string trash;
        int nbTs;
        int nbTc;
        int nbTrajetslus = 0;


        monFlux >> nbTs;
        monFlux >> tmp;
        monFlux >> nbTc;        

        string typeTrajet;

        while(getline(monFlux,  typeTrajet, ';'))
        {
            if(nbTrajetslus==0)
            {
                typeTrajet = typeTrajet.substr(1);
            }


            if(typeTrajet == "s")
            {
                if(type == 's' || type == '*')
                {
                    TrajetSimple *ts = chargerTrajetSimple(monFlux, villeDepRequis, villeArrRequis);
                    if(ts != nullptr)
                    {
                        AjouterTrajet(*ts);
                    }
                } else {
                    getline(monFlux, trash);
                }
            } else {
                if(type == 'c' || type == '*')
                {
                    TrajetCompose *tc = chargerTrajetCompose(monFlux, villeDepRequis, villeArrRequis);
                    if(tc != nullptr)
                    {
                        AjouterTrajet(*tc);
                    }
                } else {
                    getline(monFlux, trash, ';');
                    getline(monFlux, trash, ';');

                    string strNbTrajetsSimples;
                    getline(monFlux, strNbTrajetsSimples);

                    int nbTrajetsSimples = stoi(strNbTrajetsSimples);
                    for(int i = 0; i < nbTrajetsSimples; i++)
                    {
                        getline(monFlux, trash);
                    }
                }
            }

            nbTrajetslus++;
        }
        monFlux.close();
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}

const void Catalogue::lireCatalogueIntervalle(char* nomFichier, int indiceDepart, int indiceArrivee)
{
        ifstream monFlux(nomFichier);

    if(monFlux)
    {
        char tmp;
        string trash;

        int nbTs;
        int nbTc;

        monFlux >> nbTs;
        monFlux >> tmp;
        monFlux >> nbTc;        

        string typeTrajet;

        int trajetsParcourus = 0;
        
        getline(monFlux, trash);

        if(indiceDepart > 0)
        {
            while (trajetsParcourus != indiceDepart-1)
            {
                getline(monFlux,  typeTrajet, ';');
                if(typeTrajet == "s")
                {
                    getline(monFlux, trash);
                } else {
                    getline(monFlux, trash, ';');
                    getline(monFlux, trash, ';');

                    string strNbTrajetsSimples;
                    getline(monFlux, strNbTrajetsSimples);

                    int nbTrajetsSimples = stoi(strNbTrajetsSimples);
                    for(int i = 0; i < nbTrajetsSimples; i++)
                    {
                        getline(monFlux, trash);
                    }
                }

                trajetsParcourus++;
            }
        }
        

        for(int i = indiceDepart; i < indiceArrivee+1; ++i)
        {
            getline(monFlux,  typeTrajet, ';');

            if(typeTrajet == "s")
            {
                TrajetSimple *ts = chargerTrajetSimple(monFlux, "*", "*");
                AjouterTrajet(*ts);
            } else {
                TrajetCompose *tc = chargerTrajetCompose(monFlux, "*", "*");
                AjouterTrajet(*tc);
            }

            trajetsParcourus++;
        }
        monFlux.close();
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
}


TrajetSimple* Catalogue::chargerTrajetSimple(ifstream &monFlux, const char* villeDepRequis, const char* villeArrRequis)
{
    string villeDepart;
    string villeArrive;
    string moyenTransport;

    getline(monFlux, villeDepart, ';');
    getline(monFlux, villeArrive, ';');
    getline(monFlux, moyenTransport);

    MoyenTransport mt = static_cast<MoyenTransport>(stoi(moyenTransport));
    const char* vd = villeDepart.c_str();
    const char* va = villeArrive.c_str();

    if((strcmp(villeDepRequis, "*") == 0 && strcmp(villeArrRequis, "*") == 0) || (strcmp(villeDepRequis, vd) == 0 && strcmp(villeArrRequis, "*") == 0) || (strcmp(villeArrRequis, va) == 0 && strcmp(villeDepRequis, "*") == 0) || (strcmp(villeDepRequis, vd) == 0 && strcmp(villeArrRequis, va) == 0))
    {
        TrajetSimple *ts = new TrajetSimple(vd, va, mt);
        return ts;
    }
    else
    {
        return nullptr;
    }
}


TrajetCompose* Catalogue::chargerTrajetCompose(ifstream &monFlux, const char* villeDepRequis, const char* villeArrRequis)
{

    string villeDepart;
    string villeArrive;
    string nbTrajets;
    string trash;

    getline(monFlux, villeDepart, ';');
    getline(monFlux, villeArrive, ';');
    getline(monFlux, nbTrajets);

    string symbol = "*";

    if((villeDepRequis == symbol  && villeArrRequis == symbol) || (villeDepRequis == villeDepart && villeArrRequis == symbol) || (villeArrRequis == villeArrive && villeDepRequis == symbol) || ( villeDepRequis == villeDepart && villeArrRequis == villeArrive))
    {
        TrajetCompose *tc = new TrajetCompose();

        int nbTraj = stoi(nbTrajets);
        for(int i = 0; i < nbTraj; i++)
        {
            getline(monFlux, trash, ';');
            TrajetSimple *ts = chargerTrajetSimple(monFlux,"*", "*");
            tc->AjouterTrajet(*ts);
        }
        return tc;
    } else 
    {
        return nullptr;
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

    ifstream is;
    is.open(cheminDuFichier);

    cout << "Good ? : " << is.good() << endl;

    if(is.good()){
        for(;;)
        {
            int choix;

            cout << "Ce fichier de sauvegarde existe déjà, voulez vous le remplacer ?" << endl;
            cout << "\t 1 : Oui" << endl;
            cout << "\t 2 : Non" << endl;
            cin >> choix;

            switch(choix){
                case 1:
                    break;
                case 2:
                    return;
                default:
                    cout << "Choix erronné" << endl;
                    continue;
            }

            break;
        }
    }

    ofstream os;
    os.open(cheminDuFichier);

    if(col.GetNbTrajet() != 0){
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
    }

    cout << "Sauvegarde effectuée avec succès" << endl;

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



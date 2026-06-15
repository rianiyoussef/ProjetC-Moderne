#pragma once
#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include <memory>

#include "../Joueur/Joueur.h"
#include "../Joueur/StrategieAleatoire.h"
#include "../Paquet/Paquet.h"
#include "../Regles/ReglesJeu.h"
#include "Pli.h"

class Partie
{
private:
    std::vector<std::unique_ptr<Joueur>> joueurs;
    std::unique_ptr<Paquet> paquet;
    std::unique_ptr<ReglesJeu> regles;
    std::vector<Pli> plis;
    int indiceJoueurCourant;
    bool premierTour;
public:

   

    Partie(std::unique_ptr<ReglesJeu> desRegles);

    void ajouterJoueur(const std::string& nom);

    void distribuer();

    void afficherJoueurs() const;

    void afficherMains() const;
    
    void jouerTour();
   

    void jouerManche();

    void afficherScores() const;


    void jouerPartie();

    void nouvelleManche();
};

#endif
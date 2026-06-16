#pragma once
#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include <memory>
#include <functional>

#include "../Joueur/Joueur.h"
#include "../Joueur/StrategieAleatoire.h"
#include "../Paquet/Paquet.h"
#include "../Regles/ReglesJeu.h"
#include "../Joueur/StrategieJoueur.h"
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

    int dernierGagnant;
    int derniersPoints;

public:
    Partie(std::unique_ptr<ReglesJeu> desRegles);

    void ajouterJoueur(
        const std::string& nom,
        std::unique_ptr<StrategieJoueur> strategie
    );
    void distribuer();

    Pli jouerTour(
        const std::function<void(int, const Pli&)>& avantCarte = nullptr,
        const std::function<void(int, const Carte&, const Pli&)>& apresCarte = nullptr
    );

    void nouvelleManche(
        const std::function<void(int, int)>& avantEchange = nullptr,
        const std::function<void(int, int)>& apresEchange = nullptr
    );
    void validerFinManche();

    const std::vector<std::unique_ptr<Joueur>>& getJoueurs() const;
    bool estTerminee() const;

    int getDernierGagnant() const;
    int getDerniersPoints() const;
};

#endif
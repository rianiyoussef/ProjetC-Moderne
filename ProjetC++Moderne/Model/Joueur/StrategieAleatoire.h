#ifndef STRATEGIEALEATOIRE_H
#define STRATEGIEALEATOIRE_H

#include "StrategieJoueur.h"

#include <memory>
#include <vector>

class StrategieAleatoire : public StrategieJoueur
{
public:
    // Choisit une carte à jouer au hasard
    std::shared_ptr<Carte> choisirCarte(
        MainJoueur& main,
        const Pli& pli,
        const ReglesJeu& regles
    ) override;

    // Choisit des cartes à échanger au hasard
    std::vector<std::shared_ptr<Carte>> choisirCartesAEchanger(
        MainJoueur& main,
        int nombreCartes
    ) override;
};

#endif
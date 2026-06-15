#ifndef STRATEGIEALEATOIRE_H
#define STRATEGIEALEATOIRE_H

#include "StrategieJoueur.h"

/*
 * Stratégie simple : choisit une carte au hasard dans la main.
 */
class StrategieAleatoire : public StrategieJoueur
{
public:
    std::shared_ptr<Carte> choisirCarte(
        MainJoueur& main,
        const Pli& pli,
        const ReglesJeu& regles
    ) override;
};

#endif
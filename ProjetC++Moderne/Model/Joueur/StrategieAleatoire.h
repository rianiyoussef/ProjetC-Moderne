#ifndef STRATEGIEALEATOIRE_H
#define STRATEGIEALEATOIRE_H

#include "StrategieJoueur.h"

#include <memory>
#include <vector>

class StrategieAleatoire : public StrategieJoueur
{
public:
    std::shared_ptr<Carte> choisirCarte(
        MainJoueur& main,
        const Pli& pli,
        const ReglesJeu& regles
    ) override;

    std::vector<std::shared_ptr<Carte>> choisirCartesAEchanger(
        MainJoueur& main,
        int nombreCartes
    ) override;
};

#endif

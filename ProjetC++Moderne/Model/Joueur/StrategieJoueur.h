#ifndef STRATEGIEJOUEUR_H
#define STRATEGIEJOUEUR_H

#include <memory>

#include "MainJoueur.h"
#include "../Carte/Carte.h"

class Pli;
class ReglesJeu;

/*
 * Classe abstraite représentant une stratégie de joueur.
 * Elle permet de séparer le joueur de sa manière de choisir une carte.
 */
class StrategieJoueur
{
public:
    virtual std::shared_ptr<Carte> choisirCarte(
        MainJoueur& main,
        const Pli& pli,
        const ReglesJeu& regles
    ) = 0;

    virtual ~StrategieJoueur() = default;
};

#endif
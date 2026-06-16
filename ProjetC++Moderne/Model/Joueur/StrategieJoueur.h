#ifndef STRATEGIEJOUEUR_H
#define STRATEGIEJOUEUR_H

#include <memory>
#include <vector>

#include "MainJoueur.h"
#include "../Carte/Carte.h"

class Pli;
class ReglesJeu;

/*
 * Classe abstraite pour définir une stratégie de jeu.
 * Elle sert à choisir comment jouer une carte
 * ou quelles cartes échanger.
 */
class StrategieJoueur
{
public:
    // Choisit une carte à jouer
    virtual std::shared_ptr<Carte> choisirCarte(
        MainJoueur& main,
        const Pli& pli,
        const ReglesJeu& regles
    ) = 0;

    // Choisit les cartes à échanger
    virtual std::vector<std::shared_ptr<Carte>> choisirCartesAEchanger(
        MainJoueur& main,
        int nombreCartes
    ) = 0;

    // Destructeur
    virtual ~StrategieJoueur() = default;
};

#endif
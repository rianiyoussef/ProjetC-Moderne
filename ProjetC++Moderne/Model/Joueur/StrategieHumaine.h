#pragma once
#ifndef STRATEGIEHUMAINE_H
#define STRATEGIEHUMAINE_H

#include "../../Model/Joueur/StrategieJoueur.h"
#include "../../Vue/InterfaceUtilisateur.h"
#include "../../Model/Regles/ReglesJeu.h"

#include <memory>
#include <vector>

class StrategieHumaine : public StrategieJoueur
{
private:
    // Interface utilisateur
    std::shared_ptr<InterfaceUtilisateur> interfaceUtilisateur;

public:
    // Constructeur
    explicit StrategieHumaine(
        std::shared_ptr<InterfaceUtilisateur> uneInterface
    );

    // Choix d'une carte à jouer
    std::shared_ptr<Carte> choisirCarte(
        MainJoueur& main,
        const Pli& pli,
        const ReglesJeu& regles
    ) override;

    // Choix des cartes à échanger
    std::vector<std::shared_ptr<Carte>> choisirCartesAEchanger(
        MainJoueur& main,
        int nombreCartes
    ) override;
};

#endif
#pragma once
#ifndef STRATEGIEHUMAINE_H
#define STRATEGIEHUMAINE_H

#include "../Model/Joueur/StrategieJoueur.h"
#include "../Vue/InterfaceUtilisateur.h"
#include "../Model/Regles/ReglesJeu.h"

#include <memory>
#include <vector>

class StrategieHumaine : public StrategieJoueur
{
private:
    std::shared_ptr<InterfaceUtilisateur> interfaceUtilisateur;

public:
    explicit StrategieHumaine(
        std::shared_ptr<InterfaceUtilisateur> uneInterface
    );

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

#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

#include <string>
#include <vector>
#include <memory>

#include "../Model/Joueur/Joueur.h"
#include "../Model/Joueur/MainJoueur.h"

class InterfaceUtilisateur
{
public:
    virtual void afficherMessage(const std::string& message) = 0;

    virtual int demanderChoix() = 0;

    virtual void attendreEntree() = 0;

    virtual void effacerEcran() = 0;

    virtual void afficherMain(const MainJoueur& main) = 0;

    virtual void afficherScores(
        const std::vector<std::unique_ptr<Joueur>>& joueurs
    ) = 0;

    virtual ~InterfaceUtilisateur() = default;
};

#endif
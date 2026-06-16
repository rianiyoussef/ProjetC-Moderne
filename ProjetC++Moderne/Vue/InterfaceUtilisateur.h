#ifndef INTERFACEUTILISATEUR_H
#define INTERFACEUTILISATEUR_H

#include <string>
#include <vector>
#include <memory>

#include "../Model/Joueur/Joueur.h"
#include "../Model/Joueur/MainJoueur.h"

// Interface de base pour les interactions avec l'utilisateur
class InterfaceUtilisateur
{
public:
    // Affiche un message
    virtual void afficherMessage(const std::string& message) = 0;

    // Demande un choix à l'utilisateur
    virtual int demanderChoix() = 0;

    // Attend une entrée utilisateur
    virtual void attendreEntree() = 0;

    // Efface l'écran
    virtual void effacerEcran() = 0;

    // Affiche la main du joueur
    virtual void afficherMain(const MainJoueur& main) = 0;

    // Affiche les scores des joueurs
    virtual void afficherScores(
        const std::vector<std::unique_ptr<Joueur>>& joueurs
    ) = 0;

    // Destructeur
    virtual ~InterfaceUtilisateur() = default;
};

#endif
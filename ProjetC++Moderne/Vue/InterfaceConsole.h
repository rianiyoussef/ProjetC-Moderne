#ifndef INTERFACECONSOLE_H
#define INTERFACECONSOLE_H

#include "InterfaceUtilisateur.h"

// Interface utilisateur en mode console
class InterfaceConsole : public InterfaceUtilisateur
{
public:
    // Affiche un message à l'écran
    void afficherMessage(const std::string& message) override;

    // Demande un choix à l'utilisateur
    int demanderChoix() override;

    // Attend que l'utilisateur appuie sur Entrée
    void attendreEntree() override;

    // Efface l'écran
    void effacerEcran() override;

    // Affiche les cartes du joueur
    void afficherMain(const MainJoueur& main) override;

    // Affiche les scores des joueurs
    void afficherScores(const std::vector<std::unique_ptr<Joueur>>& joueurs) override;
};

#endif
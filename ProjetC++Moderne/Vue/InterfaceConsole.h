#ifndef INTERFACECONSOLE_H
#define INTERFACECONSOLE_H

#include "InterfaceUtilisateur.h"

class InterfaceConsole : public InterfaceUtilisateur
{
public:
    void afficherMessage(const std::string& message) override;
    int demanderChoix() override;
    void attendreEntree() override;
    void effacerEcran() override;
    void afficherMain(const MainJoueur& main) override;
    void afficherScores(const std::vector<std::unique_ptr<Joueur>>& joueurs) override;
};

#endif
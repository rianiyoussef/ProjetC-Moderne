#ifndef REGLESDAMEDEPIQUE_H
#define REGLESDAMEDEPIQUE_H

#include "ReglesJeu.h"

class RegleDameDePique : public ReglesJeu
{
private:
    bool coeursCasses;
    bool premierPli;
    int numeroManche;
public:
    RegleDameDePique();

    bool coupAutorise(const Carte& carte, const Pli& pli, const MainJoueur& main) const override;

    int determinerGagnantPli(const Pli& pli) const override;

    std::unique_ptr<Paquet> creerPaquet() const override;

    int calculerPointsPli(const Pli& pli) const override;

    void echangerCartes(
        std::vector<std::unique_ptr<Joueur>>& joueurs,
        const std::function<void(int, int)>& avantEchange = nullptr,
        const std::function<void(int, int)>& apresEchange = nullptr
    ) const override;

    int trouverPremierJoueur(const std::vector<std::unique_ptr<Joueur>>& joueurs) const override;

    bool partieTerminee(const std::vector<std::unique_ptr<Joueur>>& joueurs) const override;

    bool sontCoeursCasses() const;

    void notifierCarteJouee(const Carte& carte, const Pli& pli) override;

    void notifierFinPli(const Pli& pli) override;

    void debutNouvelleManche() override;

    bool estPremierPli() const;

    void appliquerReglesFinManche(
        std::vector<std::unique_ptr<Joueur>>& joueurs
    ) const override;
    void passerMancheSuivante() override;
};

#endif
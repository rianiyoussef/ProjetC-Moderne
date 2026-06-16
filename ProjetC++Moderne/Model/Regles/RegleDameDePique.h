#ifndef REGLESDAMEDEPIQUE_H
#define REGLESDAMEDEPIQUE_H

#include "ReglesJeu.h"

class RegleDameDePique : public ReglesJeu
{
private:
    bool coeursCasses;   // Indique si les cœurs ont déjà été joués
    bool premierPli;    // Indique si on est encore au premier pli
    int numeroManche;   // Numéro de la manche actuelle

public:
    // Constructeur des règles
    RegleDameDePique();

    // Vérifie si une carte peut être jouée
    bool coupAutorise(
        const Carte& carte,
        const Pli& pli,
        const MainJoueur& main
    ) const override;

    // Détermine le gagnant d’un pli
    int determinerGagnantPli(const Pli& pli) const override;

    // Crée le paquet de cartes utilisé
    std::unique_ptr<Paquet> creerPaquet() const override;

    // Calcule les points d’un pli
    int calculerPointsPli(const Pli& pli) const override;

    // Gère l’échange de cartes entre joueurs
    void echangerCartes(
        std::vector<std::unique_ptr<Joueur>>& joueurs,
        const std::function<void(int, int)>& avantEchange = nullptr,
        const std::function<void(int, int)>& apresEchange = nullptr
    ) const override;

    // Trouve le joueur qui commence la manche
    int trouverPremierJoueur(
        const std::vector<std::unique_ptr<Joueur>>& joueurs
    ) const override;

    // Vérifie si la partie est terminée
    bool partieTerminee(
        const std::vector<std::unique_ptr<Joueur>>& joueurs
    ) const override;

    // Indique si les cœurs sont cassés
    bool sontCoeursCasses() const;

    // Notification après qu’une carte est jouée
    void notifierCarteJouee(const Carte& carte, const Pli& pli) override;

    // Notification à la fin d’un pli
    void notifierFinPli(const Pli& pli) override;

    // Prépare une nouvelle manche
    void debutNouvelleManche() override;

    // Indique si c’est le premier pli
    bool estPremierPli() const;

    // Applique les règles spéciales de fin de manche
    void appliquerReglesFinManche(
        std::vector<std::unique_ptr<Joueur>>& joueurs
    ) const override;

    // Passe à la manche suivante
    void passerMancheSuivante() override;
};

#endif
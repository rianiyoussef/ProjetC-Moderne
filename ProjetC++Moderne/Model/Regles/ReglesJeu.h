#ifndef REGLESJEU_H
#define REGLESJEU_H

#include "../Joueur/MainJoueur.h"
#include <vector>
#include <functional>
#include "../Joueur/Joueur.h"
#include <memory>

class Carte;
class Pli;
class Paquet;

/*
 * Interface des règles du jeu.
 * Chaque jeu doit définir ses propres règles.
 */
class ReglesJeu
{
public:
    // Vérifie si une carte peut être jouée
    virtual bool coupAutorise(
        const Carte& carte,
        const Pli& pli,
        const MainJoueur& main
    ) const = 0;

    // Détermine le gagnant d’un pli
    virtual int determinerGagnantPli(const Pli& pli) const = 0;

    // Crée le paquet utilisé pour la partie
    virtual std::unique_ptr<Paquet> creerPaquet() const = 0;

    virtual ~ReglesJeu() = default;

    // Calcule les points d’un pli
    virtual int calculerPointsPli(const Pli& pli) const = 0;

    // Gère l’échange de cartes entre joueurs
    virtual void echangerCartes(
        std::vector<std::unique_ptr<Joueur>>& joueurs,
        const std::function<void(int, int)>& avantEchange = nullptr,
        const std::function<void(int, int)>& apresEchange = nullptr
    ) const = 0;

    // Trouve le joueur qui commence la manche
    virtual int trouverPremierJoueur(
        const std::vector<std::unique_ptr<Joueur>>& joueurs
    ) const = 0;

    // Indique si la partie est terminée
    virtual bool partieTerminee(
        const std::vector<std::unique_ptr<Joueur>>& joueurs
    ) const = 0;

    // Applique les règles spéciales de fin de manche
    virtual void appliquerReglesFinManche(
        std::vector<std::unique_ptr<Joueur>>& joueurs
    ) const = 0;

    // Prépare une nouvelle manche
    virtual void debutNouvelleManche() = 0;

    // Passe à la manche suivante
    virtual void passerMancheSuivante() = 0;

    // Notification quand une carte est jouée
    virtual void notifierCarteJouee(const Carte&, const Pli&) {}

    // Notification à la fin d’un pli
    virtual void notifierFinPli(const Pli&) {}
};

#endif
#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <memory>
#include <vector>

#include "MainJoueur.h"
#include "StrategieJoueur.h"
#include "../Carte/Carte.h"

/*
 * Déclaration anticipée de la classe Pli.
 */
class Pli;

class Joueur
{
private:
    // Nom du joueur
    std::string nom;

    // Score total
    int score;

    // Score de la manche en cours
    int scoreManche;

    // Main du joueur
    MainJoueur main;

    // Stratégie utilisée pour jouer
    std::unique_ptr<StrategieJoueur> strategie;

public:
    // Constructeur
    Joueur(const std::string& unNom,
        std::unique_ptr<StrategieJoueur> uneStrategie);

    // Retourne le nom
    std::string getNom() const;

    // Retourne le score total
    int getScore() const;

    // Ajoute des points au score total
    void ajouterPoints(int points);

    // Retourne la main du joueur
    MainJoueur& getMain();

    // Joue une carte
    std::shared_ptr<Carte> jouerCarte(const Pli& pli, const ReglesJeu& regles);

    // Choisit les cartes à échanger
    std::vector<std::shared_ptr<Carte>> choisirCartesAEchanger(int nombreCartes);

    // Retourne le score de la manche
    int getScoreManche() const;

    // Ajoute des points à la manche
    void ajouterPointsManche(int points);

    // Valide le score de la manche
    void validerScoreManche();

    // Remet le score de la manche à zéro
    void remettreScoreMancheAZero();
};

#endif
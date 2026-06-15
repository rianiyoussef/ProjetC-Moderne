#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include <memory>

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
    std::string nom;
    int score;
    int scoreManche;
    MainJoueur main;
    std::unique_ptr<StrategieJoueur> strategie;

public:
    Joueur(const std::string& unNom,
        std::unique_ptr<StrategieJoueur> uneStrategie);

    std::string getNom() const;

    int getScore() const;

    void ajouterPoints(int points);

    MainJoueur& getMain();

    std::shared_ptr<Carte> jouerCarte(const Pli& pli, const ReglesJeu& regles);

    int getScoreManche() const;
    void ajouterPointsManche(int points);
    void validerScoreManche();
    void remettreScoreMancheAZero();
};

#endif
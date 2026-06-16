#pragma once
#ifndef PARTIE_H
#define PARTIE_H

#include <vector>
#include <memory>
#include <functional>

#include "../Joueur/Joueur.h"
#include "../Joueur/StrategieAleatoire.h"
#include "../Paquet/Paquet.h"
#include "../Regles/ReglesJeu.h"
#include "../Joueur/StrategieJoueur.h"
#include "Pli.h"

// Gère le déroulement complet d’une partie
class Partie
{
private:
    std::vector<std::unique_ptr<Joueur>> joueurs; // Liste des joueurs
    std::unique_ptr<Paquet> paquet;               // Paquet de cartes
    std::unique_ptr<ReglesJeu> regles;             // Règles du jeu
    std::vector<Pli> plis;                         // Plis joués dans la manche

    int indiceJoueurCourant; // Joueur qui commence
    bool premierTour;        // Indique si c’est le premier tour

    int dernierGagnant;      // Dernier joueur gagnant
    int derniersPoints;      // Points du dernier pli

public:
    // Constructeur de la partie
    Partie(std::unique_ptr<ReglesJeu> desRegles);

    // Ajoute un joueur à la partie
    void ajouterJoueur(
        const std::string& nom,
        std::unique_ptr<StrategieJoueur> strategie
    );

    // Distribue les cartes aux joueurs
    void distribuer();

    // Joue un tour complet
    Pli jouerTour(
        const std::function<void(int, const Pli&)>& avantCarte = nullptr,
        const std::function<void(int, const Carte&, const Pli&)>& apresCarte = nullptr
    );

    // Démarre une nouvelle manche
    void nouvelleManche(
        const std::function<void(int, int)>& avantEchange = nullptr,
        const std::function<void(int, int)>& apresEchange = nullptr
    );

    // Applique les règles de fin de manche
    void validerFinManche();

    // Retourne la liste des joueurs
    const std::vector<std::unique_ptr<Joueur>>& getJoueurs() const;

    // Vérifie si la partie est terminée
    bool estTerminee() const;

    // Retourne le dernier gagnant
    int getDernierGagnant() const;

    // Retourne les points du dernier pli
    int getDerniersPoints() const;
};

#endif
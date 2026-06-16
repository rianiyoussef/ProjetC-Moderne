#pragma once
#ifndef DECORATEURCOULEUR_H
#define DECORATEURCOULEUR_H

#include "CarteDecorateur.h"

/*
 * Décorateur ajoutant une couleur à une carte.
 * Exemple : Rouge, Noir, Bleu, Vert.
 */
class DecorateurCouleur : public CarteDecorateur
{
private:
    // Couleur de la carte
    std::string couleur;

public:
    // Constructeur
    DecorateurCouleur(std::shared_ptr<Carte> uneCarte, const std::string& uneCouleur);

    // Nom complet de la carte
    std::string getNom() const override;

    // Destructeur
    ~DecorateurCouleur() override = default;

    // Retourne la couleur
    std::string getCouleur() const override;
};

#endif
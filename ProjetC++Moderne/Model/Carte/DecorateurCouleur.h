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
    std::string couleur;

public:
    DecorateurCouleur(std::shared_ptr<Carte> uneCarte, const std::string& uneCouleur);

    std::string getNom() const override;

    ~DecorateurCouleur() override = default;
    std::string getCouleur() const override;
};

#endif
#pragma once
#ifndef CARTEDECORATEUR_H
#define CARTEDECORATEUR_H

#include "Carte.h"
#include <memory>

/*
 * Classe abstraite du patron Decorator.
 * Elle contient une carte et permet d'ajouter progressivement
 * des informations comme une valeur, un symbole ou une couleur.
 */
class CarteDecorateur : public Carte
{
protected:
    // Carte décorée
    std::shared_ptr<Carte> carte;

public:
    // Constructeur
    explicit CarteDecorateur(std::shared_ptr<Carte> uneCarte);

    // Texte affiché pour la carte
    std::string afficher() const override;

    // Destructeur
    ~CarteDecorateur() override = default;

    // Valeur de la carte
    std::string getValeur() const override;

    // Symbole de la carte
    std::string getSymbole() const override;

    // Couleur de la carte
    std::string getCouleur() const override;
};

#endif
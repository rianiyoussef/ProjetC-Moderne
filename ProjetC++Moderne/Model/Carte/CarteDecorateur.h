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
    std::shared_ptr<Carte> carte;

public:
    explicit CarteDecorateur(std::shared_ptr<Carte> uneCarte);

    std::string afficher() const override;

    ~CarteDecorateur() override = default;
    std::string getValeur() const override;
    std::string getSymbole() const override;
    std::string getCouleur() const override;
};

#endif
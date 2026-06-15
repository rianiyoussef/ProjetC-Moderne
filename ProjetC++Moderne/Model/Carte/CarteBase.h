#ifndef CARTEBASE_H
#define CARTEBASE_H

#include "Carte.h"

class CarteBase : public Carte
{
public:

    CarteBase() = default;

    std::string getNom() const override;

    std::string afficher() const override;

    std::string getValeur() const override;

    std::string getSymbole() const override;

    std::string getCouleur() const override;

    ~CarteBase() override = default;
};

#endif
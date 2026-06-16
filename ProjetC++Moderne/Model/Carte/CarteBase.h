#ifndef CARTEBASE_H
#define CARTEBASE_H

#include "Carte.h"

// Classe de base des cartes
class CarteBase : public Carte
{
public:

    // Constructeur par défaut
    CarteBase() = default;

    // Nom de la carte
    std::string getNom() const override;

    // Texte affiché pour la carte
    std::string afficher() const override;

    // Valeur de la carte
    std::string getValeur() const override;

    // Symbole de la carte
    std::string getSymbole() const override;

    // Couleur de la carte
    std::string getCouleur() const override;

    // Destructeur
    ~CarteBase() override = default;
};

#endif
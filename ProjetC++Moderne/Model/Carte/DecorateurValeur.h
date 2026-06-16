#ifndef DECORATEURVALEUR_H
#define DECORATEURVALEUR_H

#include "CarteDecorateur.h"

/*
 * Décorateur ajoutant une valeur à une carte.
 * Exemple : As, Roi, Dame, 10, 7...
 */
class DecorateurValeur : public CarteDecorateur
{
private:
    // Valeur de la carte
    std::string valeur;

public:
    // Constructeur
    DecorateurValeur(std::shared_ptr<Carte> uneCarte, const std::string& uneValeur);

    // Nom complet de la carte
    std::string getNom() const override;

    // Destructeur
    ~DecorateurValeur() override = default;

    // Retourne la valeur
    std::string getValeur() const override;
};

#endif
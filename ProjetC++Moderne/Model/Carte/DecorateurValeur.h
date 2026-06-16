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
    std::string valeur;

public:
    DecorateurValeur(std::shared_ptr<Carte> uneCarte, const std::string& uneValeur);

    std::string getNom() const override;

    ~DecorateurValeur() override = default;

    std::string getValeur() const override;
};

#endif
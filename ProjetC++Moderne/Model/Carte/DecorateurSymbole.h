#ifndef DECORATEURSYMBOLE_H
#define DECORATEURSYMBOLE_H

#include "CarteDecorateur.h"

/*
 * Décorateur ajoutant un symbole à une carte.
 * Exemple : Pique, Coeur, Carreau, Trèfle.
 */
class DecorateurSymbole : public CarteDecorateur
{
private:
    // Symbole de la carte
    std::string symbole;

public:
    // Constructeur
    DecorateurSymbole(std::shared_ptr<Carte> uneCarte, const std::string& unSymbole);

    // Nom complet de la carte
    std::string getNom() const override;

    // Destructeur
    ~DecorateurSymbole() override = default;

    // Retourne le symbole
    std::string getSymbole() const override;

};

#endif
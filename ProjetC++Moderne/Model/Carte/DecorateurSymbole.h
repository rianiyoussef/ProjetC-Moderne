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
    std::string symbole;

public:
    DecorateurSymbole(std::shared_ptr<Carte> uneCarte, const std::string& unSymbole);

    std::string getNom() const override;

    ~DecorateurSymbole() override = default;

    std::string getSymbole() const override;
    
};

#endif
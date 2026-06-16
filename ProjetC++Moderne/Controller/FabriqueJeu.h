#ifndef FABRIQUEJEU_H
#define FABRIQUEJEU_H

#include <memory>

#include "../Model/Partie/Partie.h"
#include "../Model/Regles/ReglesJeu.h"

// Fabrique de base pour créer un jeu
class FabriqueJeu
{
public:
    // Crée les règles du jeu
    virtual std::unique_ptr<ReglesJeu> creerRegles() const = 0;

    // Crée une nouvelle partie
    virtual std::unique_ptr<Partie> creerPartie() const
    {
        return std::make_unique<Partie>(creerRegles());
    }

    // Destructeur
    virtual ~FabriqueJeu() = default;
};

#endif
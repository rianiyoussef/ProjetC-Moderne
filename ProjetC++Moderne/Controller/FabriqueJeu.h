#ifndef FABRIQUEJEU_H
#define FABRIQUEJEU_H

#include <memory>

#include "../Model/Partie/Partie.h"
#include "../Model/Regles/ReglesJeu.h"

class FabriqueJeu
{
public:
    virtual std::unique_ptr<ReglesJeu> creerRegles() const = 0;

    virtual std::unique_ptr<Partie> creerPartie() const
    {
        return std::make_unique<Partie>(creerRegles());
    }

    virtual ~FabriqueJeu() = default;
};

#endif

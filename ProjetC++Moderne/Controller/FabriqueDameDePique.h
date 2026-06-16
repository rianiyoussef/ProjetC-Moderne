#ifndef FABRIQUEDAMEDEPIQUE_H
#define FABRIQUEDAMEDEPIQUE_H

#include "FabriqueJeu.h"

class FabriqueDameDePique : public FabriqueJeu
{
public:
    std::unique_ptr<ReglesJeu> creerRegles() const override;
};

#endif

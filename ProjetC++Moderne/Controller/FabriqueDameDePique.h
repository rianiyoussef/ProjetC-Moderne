#ifndef FABRIQUEDAMEDEPIQUE_H
#define FABRIQUEDAMEDEPIQUE_H

#include "FabriqueJeu.h"

// Fabrique utilisée pour le jeu Dame de Pique
class FabriqueDameDePique : public FabriqueJeu
{
public:
    // Crée les règles du jeu
    std::unique_ptr<ReglesJeu> creerRegles() const override;
};

#endif
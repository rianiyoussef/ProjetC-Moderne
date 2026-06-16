#include "FabriqueDameDePique.h"

#include "../Model/Regles/RegleDameDePique.h"

std::unique_ptr<ReglesJeu> FabriqueDameDePique::creerRegles() const
{
    return std::make_unique<RegleDameDePique>();
}

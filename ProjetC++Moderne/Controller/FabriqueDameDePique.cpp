#include "FabriqueDameDePique.h"

#include "../Model/Regles/RegleDameDePique.h"

std::unique_ptr<ReglesJeu> FabriqueDameDePique::creerRegles() const
{
    // Crée les règles de la Dame de Pique
    return std::make_unique<RegleDameDePique>();
}
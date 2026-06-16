#include "Pli.h"

void Pli::ajouterCarte(const CarteJouee& carte)
{
    cartesJouees.push_back(carte);
}

bool Pli::estComplet() const
{
    return cartesJouees.size() == 4;
}

int Pli::nombreCartes() const
{
    return (int)cartesJouees.size();
}
const std::vector<CarteJouee>& Pli::getCartesJouees() const
{
    return cartesJouees;
}
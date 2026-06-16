#include "Pli.h"

// Ajoute une carte jouée au pli
void Pli::ajouterCarte(const CarteJouee& carte)
{
    cartesJouees.push_back(carte);
}

// Vérifie si le pli est complet
bool Pli::estComplet() const
{
    return cartesJouees.size() == 4;
}

// Retourne le nombre de cartes jouées
int Pli::nombreCartes() const
{
    return (int)cartesJouees.size();
}

// Retourne les cartes jouées dans le pli
const std::vector<CarteJouee>& Pli::getCartesJouees() const
{
    return cartesJouees;
}
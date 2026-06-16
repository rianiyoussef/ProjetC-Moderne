#include "CarteDecorateur.h"

// Constructeur
CarteDecorateur::CarteDecorateur(std::shared_ptr<Carte> uneCarte)
    : carte(std::move(uneCarte))
{
}

std::string CarteDecorateur::afficher() const
{
    // Retourne le nom de la carte
    return getNom();
}

std::string CarteDecorateur::getValeur() const
{
    // Retourne la valeur de la carte décorée
    return carte->getValeur();
}

std::string CarteDecorateur::getSymbole() const
{
    // Retourne le symbole de la carte décorée
    return carte->getSymbole();
}

std::string CarteDecorateur::getCouleur() const
{
    // Retourne la couleur de la carte décorée
    return carte->getCouleur();
}
#include "CarteDecorateur.h"

CarteDecorateur::CarteDecorateur(std::shared_ptr<Carte> uneCarte)
    : carte(std::move(uneCarte))
{
}

std::string CarteDecorateur::afficher() const
{
    return getNom();
}
std::string CarteDecorateur::getValeur() const
{
    return carte->getValeur();
}

std::string CarteDecorateur::getSymbole() const
{
    return carte->getSymbole();
}

std::string CarteDecorateur::getCouleur() const
{
    return carte->getCouleur();
}
#include "DecorateurSymbole.h"

// Constructeur
DecorateurSymbole::DecorateurSymbole(std::shared_ptr<Carte> uneCarte, const std::string& unSymbole)
    : CarteDecorateur(std::move(uneCarte)), symbole(unSymbole)
{
}

std::string DecorateurSymbole::getNom() const
{
    // Nom de la carte avec son symbole
    return carte->getNom() + " " + symbole;
}

std::string DecorateurSymbole::getSymbole() const
{
    // Retourne le symbole
    return symbole;
}
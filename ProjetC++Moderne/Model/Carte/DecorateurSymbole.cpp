#include "DecorateurSymbole.h"

DecorateurSymbole::DecorateurSymbole(std::shared_ptr<Carte> uneCarte, const std::string& unSymbole)
    : CarteDecorateur(std::move(uneCarte)), symbole(unSymbole)
{
}

std::string DecorateurSymbole::getNom() const
{
    return carte->getNom() + " " + symbole;
}
std::string DecorateurSymbole::getSymbole() const
{
    return symbole;
}
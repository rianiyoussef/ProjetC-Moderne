#include "DecorateurCouleur.h"

DecorateurCouleur::DecorateurCouleur(std::shared_ptr<Carte> uneCarte, const std::string& uneCouleur)
    : CarteDecorateur(std::move(uneCarte)), couleur(uneCouleur)
{
}

std::string DecorateurCouleur::getNom() const
{
    return carte->getNom() + " (" + couleur + ")";
}
std::string DecorateurCouleur::getCouleur() const
{
    return couleur;
}
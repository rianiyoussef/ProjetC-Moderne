#include "DecorateurCouleur.h"

// Constructeur
DecorateurCouleur::DecorateurCouleur(std::shared_ptr<Carte> uneCarte, const std::string& uneCouleur)
    : CarteDecorateur(std::move(uneCarte)), couleur(uneCouleur)
{
}

std::string DecorateurCouleur::getNom() const
{
    // Nom de la carte avec sa couleur
    return carte->getNom() + " (" + couleur + ")";
}

std::string DecorateurCouleur::getCouleur() const
{
    // Retourne la couleur
    return couleur;
}
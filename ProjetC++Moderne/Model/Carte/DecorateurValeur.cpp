#include "DecorateurValeur.h"

// Constructeur
DecorateurValeur::DecorateurValeur(std::shared_ptr<Carte> uneCarte, const std::string& uneValeur)
    : CarteDecorateur(std::move(uneCarte)), valeur(uneValeur)
{
}

std::string DecorateurValeur::getNom() const
{
    // Nom de la carte avec sa valeur
    return valeur + " " + carte->getNom();
}

std::string DecorateurValeur::getValeur() const
{
    // Retourne la valeur
    return valeur;
}
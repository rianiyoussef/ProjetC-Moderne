#include "DecorateurValeur.h"

DecorateurValeur::DecorateurValeur(std::shared_ptr<Carte> uneCarte, const std::string& uneValeur)
    : CarteDecorateur(std::move(uneCarte)), valeur(uneValeur)
{
}

std::string DecorateurValeur::getNom() const
{
    return valeur + " " + carte->getNom();
}
std::string DecorateurValeur::getValeur() const
{
    return valeur;
}
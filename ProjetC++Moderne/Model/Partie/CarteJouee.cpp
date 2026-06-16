#include "CarteJouee.h"

CarteJouee::CarteJouee(std::shared_ptr<Carte> uneCarte,
    int unIndiceJoueur)
    : carte(uneCarte),
    indiceJoueur(unIndiceJoueur)
{
}

std::shared_ptr<Carte> CarteJouee::getCarte() const
{
    return carte;
}

int CarteJouee::getIndiceJoueur() const
{
    return indiceJoueur;
}
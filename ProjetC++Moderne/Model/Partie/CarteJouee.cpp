#include "CarteJouee.h"

// Constructeur de la carte jouée
CarteJouee::CarteJouee(std::shared_ptr<Carte> uneCarte,
    int unIndiceJoueur)
    : carte(uneCarte),          // Carte qui a été jouée
    indiceJoueur(unIndiceJoueur) // Indice du joueur
{
}

// Retourne la carte jouée
std::shared_ptr<Carte> CarteJouee::getCarte() const
{
    return carte;
}

// Retourne l’indice du joueur
int CarteJouee::getIndiceJoueur() const
{
    return indiceJoueur;
}
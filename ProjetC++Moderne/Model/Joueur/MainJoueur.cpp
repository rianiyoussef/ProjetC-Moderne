#include "MainJoueur.h"

#include <stdexcept>

void MainJoueur::recevoirCarte(std::shared_ptr<Carte> carte)
{
    cartes.push_back(carte);
}

std::shared_ptr<Carte> MainJoueur::jouerCarte(int indice)
{
    if (indice < 0 || indice >= static_cast<int>(cartes.size()))
    {
        throw std::out_of_range("Indice de carte invalide dans jouerCarte.");
    }

    std::shared_ptr<Carte> carte = cartes[indice];

    cartes.erase(cartes.begin() + indice);

    return carte;
}

bool MainJoueur::estVide() const
{
    return cartes.empty();
}

int MainJoueur::nombreCartes() const
{
    return static_cast<int>(cartes.size());
}

std::shared_ptr<Carte> MainJoueur::getCarte(int indice) const
{
    if (indice < 0 || indice >= static_cast<int>(cartes.size()))
    {
        throw std::out_of_range("Indice de carte invalide dans getCarte.");
    }

    return cartes[indice];
}

std::shared_ptr<Carte> MainJoueur::retirerCarte(int indice)
{
    if (indice < 0 || indice >= static_cast<int>(cartes.size()))
    {
        throw std::out_of_range("Indice de carte invalide dans retirerCarte.");
    }

    std::shared_ptr<Carte> carte = cartes[indice];

    cartes.erase(cartes.begin() + indice);

    return carte;
}

int MainJoueur::trouverCarte(
    const std::string& valeur,
    const std::string& symbole
) const
{
    for (int i = 0; i < static_cast<int>(cartes.size()); i++)
    {
        if (cartes[i]->getValeur() == valeur &&
            cartes[i]->getSymbole() == symbole)
        {
            return i;
        }
    }

    return -1;
}

bool MainJoueur::possedeSymbole(const std::string& symbole) const
{
    for (int i = 0; i < static_cast<int>(cartes.size()); i++)
    {
        if (cartes[i]->getSymbole() == symbole)
        {
            return true;
        }
    }

    return false;
}

void MainJoueur::viderMain()
{
    cartes.clear();
}

bool MainJoueur::possedeAutreQueSymbole(
    const std::string& symbole
) const
{
    for (int i = 0; i < static_cast<int>(cartes.size()); i++)
    {
        if (cartes[i]->getSymbole() != symbole)
        {
            return true;
        }
    }

    return false;
}

bool MainJoueur::possedeCarteAutreQue(
    const std::string& valeur,
    const std::string& symbole
) const
{
    for (int i = 0; i < static_cast<int>(cartes.size()); i++)
    {
        if (!(cartes[i]->getValeur() == valeur &&
            cartes[i]->getSymbole() == symbole))
        {
            return true;
        }
    }

    return false;
}
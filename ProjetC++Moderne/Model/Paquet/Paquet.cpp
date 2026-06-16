#include "Paquet.h"

#include <algorithm>
#include <random>
#include <stdexcept>
#include <utility>

void Paquet::melanger()
{
    // Mélange les cartes du paquet
    static std::random_device rd;
    static std::mt19937 generateur(rd());

    std::shuffle(cartes.begin(), cartes.end(), generateur);
}

std::shared_ptr<Carte> Paquet::piocher()
{
    // Vérifie si le paquet est vide
    if (cartes.empty())
    {
        throw std::runtime_error("Erreur : le paquet est vide.");
    }

    // Prend la carte du dessus
    std::shared_ptr<Carte> cartePiochee = cartes.back();
    cartes.pop_back();

    return cartePiochee;
}

bool Paquet::estVide() const
{
    return cartes.empty();
}

int Paquet::nombreCartes() const
{
    return static_cast<int>(cartes.size());
}
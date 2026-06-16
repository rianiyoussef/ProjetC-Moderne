#ifndef PLI_H
#define PLI_H

#include <vector>
#include "CarteJouee.h"

// Gère un pli pendant un tour
class Pli
{
private:
    // Cartes jouées dans le pli
    std::vector<CarteJouee> cartesJouees;

public:
    // Ajoute une carte jouée au pli
    void ajouterCarte(const CarteJouee& carte);

    // Vérifie si le pli est complet
    bool estComplet() const;

    // Retourne le nombre de cartes jouées
    int nombreCartes() const;

    // Retourne les cartes jouées dans le pli
    const std::vector<CarteJouee>& getCartesJouees() const;
};

#endif
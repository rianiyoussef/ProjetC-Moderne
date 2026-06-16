#pragma once
#ifndef MAINJOUEUR_H
#define MAINJOUEUR_H

#include <vector>
#include <memory>

#include "../Carte/Carte.h"

class MainJoueur
{
private:
    // Cartes du joueur
    std::vector<std::shared_ptr<Carte>> cartes;

public:
    // Ajoute une carte dans la main
    void recevoirCarte(std::shared_ptr<Carte> carte);

    // Joue une carte selon son indice
    std::shared_ptr<Carte> jouerCarte(int indice);

    // Vérifie si la main est vide
    bool estVide() const;

    // Nombre de cartes dans la main
    int nombreCartes() const;

    // Retourne une carte de la main
    std::shared_ptr<Carte> getCarte(int indice) const;

    // Retire une carte de la main
    std::shared_ptr<Carte> retirerCarte(int indice);

    // Recherche une carte dans la main
    int trouverCarte(const std::string& valeur, const std::string& symbole) const;

    // Vérifie si le joueur possède un symbole
    bool possedeSymbole(const std::string& symbole) const;

    // Supprime toutes les cartes de la main
    void viderMain();

    // Vérifie s'il existe un autre symbole
    bool possedeAutreQueSymbole(const std::string& symbole) const;

    // Vérifie s'il existe une autre carte que celle indiquée
    bool possedeCarteAutreQue(
        const std::string& valeur,
        const std::string& symbole
    ) const;
};

#endif
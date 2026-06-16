#pragma once
#ifndef PAQUET_H
#define PAQUET_H

#include <vector>
#include <memory>

#include "../Carte/Carte.h"

/*
 * Classe abstraite pour un paquet de cartes.
 * Chaque jeu peut avoir son propre paquet.
 */
class Paquet
{
protected:
    // Cartes du paquet
    std::vector<std::shared_ptr<Carte>> cartes;

public:
    /*
     * Initialise les cartes du paquet.
     * Dépend du jeu utilisé.
     */
    virtual void initialiser() = 0;

    /*
     * Mélange les cartes du paquet.
     */
    void melanger();

    /*
     * Pioche une carte du paquet.
     */
    std::shared_ptr<Carte> piocher();

    /*
     * Vérifie si le paquet est vide.
     */
    bool estVide() const;

    /*
     * Retourne le nombre de cartes restantes.
     */
    int nombreCartes() const;

    // Destructeur
    virtual ~Paquet() = default;
};

#endif
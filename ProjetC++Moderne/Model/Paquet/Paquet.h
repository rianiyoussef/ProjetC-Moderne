#pragma once
#ifndef PAQUET_H
#define PAQUET_H

#include <vector>
#include <memory>

#include "../Carte/Carte.h"

/*
 * Classe abstraite représentant un paquet de cartes.
 * Chaque jeu possède son propre type de paquet.
 */
class Paquet
{
protected:
    std::vector<std::shared_ptr<Carte>> cartes;

public:
    /*
     * Initialise les cartes du paquet.
     * Cette méthode dépend du jeu.
     */
    virtual void initialiser() = 0;

    /*
     * Mélange les cartes du paquet.
     */
    void melanger();

    /*
     * Pioche la dernière carte du paquet.
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

    virtual ~Paquet() = default;
};

#endif
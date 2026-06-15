#ifndef PAQUET52CARTES_H
#define PAQUET52CARTES_H

#include "Paquet.h"

/*
 * Paquet classique de 52 cartes.
 * Utilisé pour les jeux comme la Dame de Pique.
 */
class Paquet52Cartes : public Paquet
{
public:
    Paquet52Cartes();

    void initialiser() override;

    ~Paquet52Cartes() override = default;
};

#endif
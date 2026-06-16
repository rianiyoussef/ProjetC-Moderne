#ifndef CARTEJOUEE_H
#define CARTEJOUEE_H

#include <memory>

#include "../Carte/Carte.h"

class CarteJouee
{
private:

    std::shared_ptr<Carte> carte;

    int indiceJoueur;

public:

    CarteJouee(std::shared_ptr<Carte> uneCarte,
        int unIndiceJoueur);

    std::shared_ptr<Carte> getCarte() const;

    int getIndiceJoueur() const;
};

#endif
#ifndef PLI_H
#define PLI_H

#include <vector>
#include "CarteJouee.h"

class Pli
{
private:
    std::vector<CarteJouee> cartesJouees;

public:
    void ajouterCarte(const CarteJouee& carte);

    bool estComplet() const;

    int nombreCartes() const;
    
    const std::vector<CarteJouee>& getCartesJouees() const;

};

#endif
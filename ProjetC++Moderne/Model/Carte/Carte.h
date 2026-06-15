#ifndef CARTE_H
#define CARTE_H

#include <string>

class Carte
{
public:

    virtual std::string getNom() const = 0;

    virtual std::string afficher() const = 0;

    virtual std::string getValeur() const = 0;

    virtual std::string getSymbole() const = 0;

    virtual std::string getCouleur() const = 0;

    virtual ~Carte() = default;
};

#endif
#ifndef CARTE_H
#define CARTE_H

#include <string>

// Classe de base pour toutes les cartes
class Carte
{
public:

    // Nom complet de la carte
    virtual std::string getNom() const = 0;

    // Texte affiché pour la carte
    virtual std::string afficher() const = 0;

    // Valeur de la carte
    virtual std::string getValeur() const = 0;

    // Symbole de la carte
    virtual std::string getSymbole() const = 0;

    // Couleur de la carte
    virtual std::string getCouleur() const = 0;

    // Destructeur virtuel
    virtual ~Carte() = default;
};

#endif
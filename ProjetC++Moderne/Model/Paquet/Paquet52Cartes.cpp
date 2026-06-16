#include "Paquet52Cartes.h"

#include "../Carte/CarteBase.h"
#include "../Carte/DecorateurValeur.h"
#include "../Carte/DecorateurSymbole.h"
#include "../Carte/DecorateurCouleur.h"

// Constructeur
Paquet52Cartes::Paquet52Cartes()
{
    initialiser();
}

void Paquet52Cartes::initialiser()
{
    // Vide le paquet avant l'initialisation
    cartes.clear();

    // Valeurs possibles des cartes
    std::vector<std::string> valeurs =
    {
        "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "J", "Q", "K", "A"
    };

    // Symboles possibles des cartes
    std::vector<std::string> symboles =
    {
        "♣", "♦", "♥", "♠"
    };

    // Création des 52 cartes
    for (const std::string& symbole : symboles)
    {
        for (const std::string& valeur : valeurs)
        {
            // Carte de base
            std::shared_ptr<Carte> carte = std::make_shared<CarteBase>();

            // Ajoute la valeur
            carte = std::make_shared<DecorateurValeur>(carte, valeur);

            // Ajoute le symbole
            carte = std::make_shared<DecorateurSymbole>(carte, symbole);

            // Ajoute la couleur selon le symbole
            if (symbole == "♥" || symbole == "♦")
            {
                carte = std::make_shared<DecorateurCouleur>(carte, "R");
            }
            else
            {
                carte = std::make_shared<DecorateurCouleur>(carte, "N");
            }

            // Ajoute la carte au paquet
            cartes.push_back(carte);
        }
    }
}
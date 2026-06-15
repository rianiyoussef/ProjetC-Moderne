#include "Paquet52Cartes.h"

#include "../Carte/CarteBase.h"
#include "../Carte/DecorateurValeur.h"
#include "../Carte/DecorateurSymbole.h"
#include "../Carte/DecorateurCouleur.h"

Paquet52Cartes::Paquet52Cartes()
{
    initialiser();
}

void Paquet52Cartes::initialiser()
{
    cartes.clear();

    std::vector<std::string> valeurs =
    {
        "2", "3", "4", "5", "6", "7", "8", "9", "10",
        "J", "Q", "K", "A"
    };

    std::vector<std::string> symboles =
    {
        "♣", "♦", "♥", "♠"
    };

    for (int i = 0; i < symboles.size(); i++)
    {
        for (int j = 0; j < valeurs.size(); j++)
        {
            std::shared_ptr<Carte> carte = std::make_shared<CarteBase>();

            carte = std::make_shared<DecorateurValeur>(carte, valeurs[j]);
            carte = std::make_shared<DecorateurSymbole>(carte, symboles[i]);

            if (symboles[i] == "♥" || symboles[i] == "♦")
            {
                carte = std::make_shared<DecorateurCouleur>(carte, "R");
            }
            else
            {
                carte = std::make_shared<DecorateurCouleur>(carte, "N");
            }

            cartes.push_back(carte);
        }
    }
}
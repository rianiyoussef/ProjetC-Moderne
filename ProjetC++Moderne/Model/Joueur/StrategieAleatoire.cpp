#include "StrategieAleatoire.h"
#include "../Regles/ReglesJeu.h"

#include <random>
#include <vector>

std::shared_ptr<Carte> StrategieAleatoire::choisirCarte(
    MainJoueur& main,
    const Pli& pli,
    const ReglesJeu& regles
)
{
    if (main.estVide())
    {
        return nullptr;
    }

    std::vector<int> indicesPossibles;

    for (int i = 0; i < main.nombreCartes(); ++i)
    {
        std::shared_ptr<Carte> carte = main.getCarte(i);

        if (regles.coupAutorise(*carte, pli, main))
        {
            indicesPossibles.push_back(i);
        }
    }

    if (indicesPossibles.empty())
    {
        return nullptr;
    }

    static std::random_device rd;
    static std::mt19937 generateur(rd());

    std::uniform_int_distribution<int> distribution(
        0,
        static_cast<int>(indicesPossibles.size()) - 1
    );

    int indiceChoisi = indicesPossibles[distribution(generateur)];

    return main.jouerCarte(indiceChoisi);
}

std::vector<std::shared_ptr<Carte>> StrategieAleatoire::choisirCartesAEchanger(
    MainJoueur& main,
    int nombreCartes
)
{
    std::vector<std::shared_ptr<Carte>> cartesChoisies;

    static std::random_device rd;
    static std::mt19937 generateur(rd());

    while (!main.estVide() &&
        static_cast<int>(cartesChoisies.size()) < nombreCartes)
    {
        std::uniform_int_distribution<int> distribution(
            0,
            main.nombreCartes() - 1
        );

        int indiceChoisi = distribution(generateur);
        cartesChoisies.push_back(main.retirerCarte(indiceChoisi));
    }

    return cartesChoisies;
}

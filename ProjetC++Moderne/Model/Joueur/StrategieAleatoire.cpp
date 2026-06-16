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
    // Vérifie si la main est vide
    if (main.estVide())
    {
        return nullptr;
    }

    // Indices des cartes jouables
    std::vector<int> indicesPossibles;

    for (int i = 0; i < main.nombreCartes(); ++i)
    {
        std::shared_ptr<Carte> carte = main.getCarte(i);

        // Vérifie si le coup est autorisé
        if (regles.coupAutorise(*carte, pli, main))
        {
            indicesPossibles.push_back(i);
        }
    }

    // Aucun coup possible
    if (indicesPossibles.empty())
    {
        return nullptr;
    }

    // Générateur aléatoire
    static std::random_device rd;
    static std::mt19937 generateur(rd());

    std::uniform_int_distribution<int> distribution(
        0,
        static_cast<int>(indicesPossibles.size()) - 1
    );

    // Choisit une carte au hasard
    int indiceChoisi = indicesPossibles[distribution(generateur)];

    return main.jouerCarte(indiceChoisi);
}

std::vector<std::shared_ptr<Carte>> StrategieAleatoire::choisirCartesAEchanger(
    MainJoueur& main,
    int nombreCartes
)
{
    // Cartes choisies pour l'échange
    std::vector<std::shared_ptr<Carte>> cartesChoisies;

    // Générateur aléatoire
    static std::random_device rd;
    static std::mt19937 generateur(rd());

    while (!main.estVide() &&
        static_cast<int>(cartesChoisies.size()) < nombreCartes)
    {
        std::uniform_int_distribution<int> distribution(
            0,
            main.nombreCartes() - 1
        );

        // Choisit une carte au hasard
        int indiceChoisi = distribution(generateur);
        cartesChoisies.push_back(main.retirerCarte(indiceChoisi));
    }

    return cartesChoisies;
}
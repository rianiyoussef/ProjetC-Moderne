#include "Joueur.h"

Joueur::Joueur(const std::string& unNom,
    std::unique_ptr<StrategieJoueur> uneStrategie)
    : nom(unNom),
    score(0),
    scoreManche(0),
    strategie(std::move(uneStrategie))
{
}

std::string Joueur::getNom() const
{
    return nom;
}

int Joueur::getScore() const
{
    return score;
}

void Joueur::ajouterPoints(int points)
{
    score += points;
}

MainJoueur& Joueur::getMain()
{
    return main;
}

std::shared_ptr<Carte> Joueur::jouerCarte(const Pli& pli, const ReglesJeu& regles)
{
    return strategie->choisirCarte(main, pli, regles);
}

std::vector<std::shared_ptr<Carte>> Joueur::choisirCartesAEchanger(
    int nombreCartes
)
{
    return strategie->choisirCartesAEchanger(main, nombreCartes);
}

int Joueur::getScoreManche() const
{
    return scoreManche;
}

void Joueur::ajouterPointsManche(int points)
{
    scoreManche += points;
}

void Joueur::validerScoreManche()
{
    score += scoreManche;
}

void Joueur::remettreScoreMancheAZero()
{
    scoreManche = 0;
}

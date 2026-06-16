#include "Joueur.h"

// Constructeur
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
    // Ajoute des points au score total
    score += points;
}

MainJoueur& Joueur::getMain()
{
    return main;
}

std::shared_ptr<Carte> Joueur::jouerCarte(const Pli& pli, const ReglesJeu& regles)
{
    // Choix de la carte selon la stratégie
    return strategie->choisirCarte(main, pli, regles);
}

std::vector<std::shared_ptr<Carte>> Joueur::choisirCartesAEchanger(
    int nombreCartes
)
{
    // Choix des cartes à échanger
    return strategie->choisirCartesAEchanger(main, nombreCartes);
}

int Joueur::getScoreManche() const
{
    return scoreManche;
}

void Joueur::ajouterPointsManche(int points)
{
    // Ajoute des points à la manche en cours
    scoreManche += points;
}

void Joueur::validerScoreManche()
{
    // Ajoute le score de la manche au score total
    score += scoreManche;
}

void Joueur::remettreScoreMancheAZero()
{
    // Réinitialise le score de la manche
    scoreManche = 0;
}
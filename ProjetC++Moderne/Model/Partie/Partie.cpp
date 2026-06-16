#include "Partie.h"
#include "../Regles/ReglesJeu.h"

// Constructeur de la partie
Partie::Partie(std::unique_ptr<ReglesJeu> desRegles)
    : regles(std::move(desRegles)),
    indiceJoueurCourant(0),   // Indice du joueur qui commence
    premierTour(true),        // Indique si c’est le tout premier tour
    dernierGagnant(-1),       // Dernier joueur ayant gagné un pli
    derniersPoints(0)         // Points du dernier pli
{
    // Création du paquet selon les règles du jeu
    paquet = regles->creerPaquet();
}

// Ajoute un joueur à la partie
void Partie::ajouterJoueur(
    const std::string& nom,
    std::unique_ptr<StrategieJoueur> strategie
)
{
    joueurs.push_back(
        std::make_unique<Joueur>(
            nom,
            std::move(strategie)
        )
    );
}

// Distribue les cartes à tous les joueurs
void Partie::distribuer()
{
    paquet->melanger(); // Mélange du paquet

    while (!paquet->estVide())
    {
        for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
        {
            if (!paquet->estVide())
            {
                joueurs[i]->getMain().recevoirCarte(paquet->piocher());
            }
        }
    }
}

// Joue un tour complet et retourne le pli
Pli Partie::jouerTour(
    const std::function<void(int, const Pli&)>& avantCarte,
    const std::function<void(int, const Carte&, const Pli&)>& apresCarte
)
{
    Pli pli; // Pli en cours

    for (int tour = 0; tour < static_cast<int>(joueurs.size()); tour++)
    {
        // Calcul de l’indice du joueur courant
        int i = (indiceJoueurCourant + tour) % static_cast<int>(joueurs.size());

        // Action avant que le joueur joue sa carte
        if (avantCarte)
        {
            avantCarte(i, pli);
        }

        std::shared_ptr<Carte> carte;

        // Cas particulier du tout premier tour avec le 2 de trèfle
        if (premierTour && tour == 0)
        {
            int indiceDeuxTrefle =
                joueurs[i]->getMain().trouverCarte("2", "♣");

            if (indiceDeuxTrefle != -1)
            {
                carte = joueurs[i]->getMain().jouerCarte(indiceDeuxTrefle);
            }
            else
            {
                carte = joueurs[i]->jouerCarte(pli, *regles);
            }
        }
        else
        {
            carte = joueurs[i]->jouerCarte(pli, *regles);
        }

        // Si aucune carte n’est jouée, on arrête le tour
        if (carte == nullptr)
        {
            return pli;
        }

        // Ajout de la carte jouée au pli
        CarteJouee cj(carte, i);
        pli.ajouterCarte(cj);

        // Notification aux règles
        regles->notifierCarteJouee(*carte, pli);

        // Action après que la carte est jouée
        if (apresCarte)
        {
            apresCarte(i, *carte, pli);
        }
    }

    // Détermination du gagnant et des points du pli
    int gagnant = regles->determinerGagnantPli(pli);
    int points = regles->calculerPointsPli(pli);

    joueurs[gagnant]->ajouterPointsManche(points);

    // Notification de fin de pli
    regles->notifierFinPli(pli);

    indiceJoueurCourant = gagnant;
    premierTour = false;

    dernierGagnant = gagnant;
    derniersPoints = points;

    plis.push_back(pli);

    return pli;
}

// Lance une nouvelle manche
void Partie::nouvelleManche(
    const std::function<void(int, int)>& avantEchange,
    const std::function<void(int, int)>& apresEchange
)
{
    paquet = regles->creerPaquet(); // Nouveau paquet

    regles->debutNouvelleManche();

    // Vide la main de chaque joueur
    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        joueurs[i]->getMain().viderMain();
    }

    plis.clear(); // Suppression des anciens plis

    premierTour = true;
    dernierGagnant = -1;
    derniersPoints = 0;

    distribuer(); // Distribution des cartes

    // Échange de cartes selon les règles
    regles->echangerCartes(joueurs, avantEchange, apresEchange);

    // Recherche du premier joueur
    indiceJoueurCourant =
        regles->trouverPremierJoueur(joueurs);
}

// Valide la fin de la manche
void Partie::validerFinManche()
{
    regles->appliquerReglesFinManche(joueurs);

    // Validation et remise à zéro des scores de manche
    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        joueurs[i]->validerScoreManche();
        joueurs[i]->remettreScoreMancheAZero();
    }

    regles->passerMancheSuivante();
}

// Retourne la liste des joueurs
const std::vector<std::unique_ptr<Joueur>>& Partie::getJoueurs() const
{
    return joueurs;
}

// Indique si la partie est terminée
bool Partie::estTerminee() const
{
    return regles->partieTerminee(joueurs);
}

// Retourne le dernier gagnant
int Partie::getDernierGagnant() const
{
    return dernierGagnant;
}

// Retourne les points du dernier pli
int Partie::getDerniersPoints() const
{
    return derniersPoints;
}
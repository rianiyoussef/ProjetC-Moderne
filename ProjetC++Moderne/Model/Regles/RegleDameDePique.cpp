#include "RegleDameDePique.h"
#include "../Paquet/Paquet52Cartes.h"

#include "../Partie/Pli.h"
#include "../Partie/CarteJouee.h"

// Constructeur des règles de la Dame de Pique
RegleDameDePique::RegleDameDePique()
    : coeursCasses(false),
    premierPli(true),
    numeroManche(1)
{
}

// Détermine le gagnant d’un pli
int RegleDameDePique::determinerGagnantPli(const Pli& pli) const
{
    const std::vector<CarteJouee>& cartes =
        pli.getCartesJouees();

    if (cartes.empty())
    {
        return -1;
    }

    // Couleur demandée par la première carte
    std::string couleurDemandee =
        cartes[0].getCarte()->getSymbole();

    int gagnant =
        cartes[0].getIndiceJoueur();

    int meilleureValeur = 0;

    for (int i = 0; i < static_cast<int>(cartes.size()); i++)
    {
        std::shared_ptr<Carte> carte =
            cartes[i].getCarte();

        if (carte->getSymbole() == couleurDemandee)
        {
            int valeur = 0;

            std::string v = carte->getValeur();

            // Conversion de la valeur de la carte
            if (v == "A") valeur = 14;
            else if (v == "K") valeur = 13;
            else if (v == "Q") valeur = 12;
            else if (v == "J") valeur = 11;
            else valeur = std::stoi(v);

            if (valeur > meilleureValeur)
            {
                meilleureValeur = valeur;
                gagnant =
                    cartes[i].getIndiceJoueur();
            }
        }
    }

    return gagnant;
}

// Crée un paquet classique de 52 cartes
std::unique_ptr<Paquet> RegleDameDePique::creerPaquet() const
{
    return std::make_unique<Paquet52Cartes>();
}

// Vérifie si un coup est autorisé
bool RegleDameDePique::coupAutorise(const Carte& carte,
    const Pli& pli,
    const MainJoueur& main) const
{
    // Règles spéciales pour le premier pli
    if (premierPli)
    {
        if (carte.getSymbole() == "♥" &&
            main.possedeAutreQueSymbole("♥"))
        {
            return false;
        }

        if (carte.getValeur() == "Q" &&
            carte.getSymbole() == "♠" &&
            main.possedeCarteAutreQue("Q", "♠"))
        {
            return false;
        }
    }

    // Si le joueur ouvre le pli
    if (pli.nombreCartes() == 0)
    {
        if (carte.getSymbole() == "♥" &&
            !coeursCasses &&
            main.possedeAutreQueSymbole("♥"))
        {
            return false;
        }

        return true;
    }

    // Couleur demandée par le pli
    std::string symboleDemande =
        pli.getCartesJouees()[0].getCarte()->getSymbole();

    if (carte.getSymbole() == symboleDemande)
    {
        return true;
    }

    if (main.possedeSymbole(symboleDemande))
    {
        return false;
    }

    return true;
}

// Calcule les points d’un pli
int RegleDameDePique::calculerPointsPli(const Pli& pli) const
{
    int points = 0;

    const std::vector<CarteJouee>& cartes = pli.getCartesJouees();

    for (int i = 0; i < static_cast<int>(cartes.size()); i++)
    {
        std::shared_ptr<Carte> carte = cartes[i].getCarte();

        // Chaque cœur vaut 1 point
        if (carte->getSymbole() == "♥")
        {
            points++;
        }

        // La dame de pique vaut 13 points
        if (carte->getValeur() == "Q" && carte->getSymbole() == "♠")
        {
            points += 13;
        }
    }

    return points;
}

// Gère l’échange de cartes entre joueurs
void RegleDameDePique::echangerCartes(
    std::vector<std::unique_ptr<Joueur>>& joueurs,
    const std::function<void(int, int)>& avantEchange,
    const std::function<void(int, int)>& apresEchange
) const
{
    int typeEchange = (numeroManche - 1) % 4;

    // Une manche sur quatre, aucun échange
    if (typeEchange == 3)
    {
        return;
    }

    std::vector<std::vector<std::shared_ptr<Carte>>> cartesPassees(joueurs.size());

    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        if (avantEchange)
        {
            avantEchange(i, typeEchange);
        }

        // Chaque joueur choisit 3 cartes
        cartesPassees[i] = joueurs[i]->choisirCartesAEchanger(3);

        if (apresEchange)
        {
            apresEchange(i, typeEchange);
        }
    }

    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        int destinataire;

        // Sens de l’échange
        if (typeEchange == 0)
        {
            destinataire = (i + 1) % static_cast<int>(joueurs.size()); // gauche
        }
        else if (typeEchange == 1)
        {
            destinataire = (i - 1 + static_cast<int>(joueurs.size())) %
                static_cast<int>(joueurs.size()); // droite
        }
        else
        {
            destinataire = (i + 2) % static_cast<int>(joueurs.size()); // face
        }

        for (int j = 0; j < static_cast<int>(cartesPassees[i].size()); j++)
        {
            joueurs[destinataire]->getMain().recevoirCarte(cartesPassees[i][j]);
        }
    }
}

// Trouve le joueur qui commence la manche
int RegleDameDePique::trouverPremierJoueur(const std::vector<std::unique_ptr<Joueur>>& joueurs) const
{
    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        MainJoueur& main = joueurs[i]->getMain();

        for (int j = 0; j < main.nombreCartes(); j++)
        {
            std::shared_ptr<Carte> carte = main.getCarte(j);

            if (carte->getValeur() == "2" && carte->getSymbole() == "♣")
            {
                return i;
            }
        }
    }

    return 0;
}

// Vérifie si la partie est terminée
bool RegleDameDePique::partieTerminee(const std::vector<std::unique_ptr<Joueur>>& joueurs) const
{
    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        if (joueurs[i]->getScore() >= 100)
        {
            return true;
        }
    }

    return false;
}

// Indique si les cœurs sont cassés
bool RegleDameDePique::sontCoeursCasses() const
{
    return coeursCasses;
}

// Notification après une carte jouée
void RegleDameDePique::notifierCarteJouee(const Carte& carte, const Pli&)
{
    if (carte.getSymbole() == "♥")
    {
        coeursCasses = true;
    }
}

// Notification à la fin d’un pli
void RegleDameDePique::notifierFinPli(const Pli&)
{
    if (premierPli)
    {
        premierPli = false;
    }
}

// Réinitialise les règles pour une nouvelle manche
void RegleDameDePique::debutNouvelleManche()
{
    coeursCasses = false;
    premierPli = true;
}

// Indique si c’est le premier pli
bool RegleDameDePique::estPremierPli() const
{
    return premierPli;
}

// Applique les règles spéciales de fin de manche
void RegleDameDePique::appliquerReglesFinManche(
    std::vector<std::unique_ptr<Joueur>>& joueurs
) const
{
    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        // Cas où un joueur prend tous les points
        if (joueurs[i]->getScoreManche() == 26)
        {
            joueurs[i]->remettreScoreMancheAZero();

            for (int j = 0; j < static_cast<int>(joueurs.size()); j++)
            {
                if (j != i)
                {
                    joueurs[j]->ajouterPointsManche(26);
                }
            }

            break;
        }
    }
}

// Passe à la manche suivante
void RegleDameDePique::passerMancheSuivante()
{
    numeroManche++;
}
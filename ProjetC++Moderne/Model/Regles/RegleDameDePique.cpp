#include "RegleDameDePique.h"
#include <iostream>
#include "../Paquet/Paquet52Cartes.h"

#include "../Partie/Pli.h"
#include "../Partie/CarteJouee.h"


RegleDameDePique::RegleDameDePique()
    : coeursCasses(false),
    premierPli(true),
    numeroManche(1)
{
}

int RegleDameDePique::determinerGagnantPli(const Pli& pli) const
{
    const std::vector<CarteJouee>& cartes =
        pli.getCartesJouees();

    if (cartes.empty())
    {
        return -1;
    }

    std::string couleurDemandee =
        cartes[0].getCarte()->getSymbole();

    int gagnant =
        cartes[0].getIndiceJoueur();

    int meilleureValeur = 0;

    for (int i = 0; i < cartes.size(); i++)
    {
        std::shared_ptr<Carte> carte =
            cartes[i].getCarte();

        if (carte->getSymbole() == couleurDemandee)
        {
            int valeur = 0;

            std::string v = carte->getValeur();

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



std::unique_ptr<Paquet> RegleDameDePique::creerPaquet() const
{
    return std::make_unique<Paquet52Cartes>();
}

bool RegleDameDePique::coupAutorise(const Carte& carte,
    const Pli& pli,
    const MainJoueur& main) const
{
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
int RegleDameDePique::calculerPointsPli(const Pli& pli) const
{
    int points = 0;

    const std::vector<CarteJouee>& cartes = pli.getCartesJouees();

    for (int i = 0; i < cartes.size(); i++)
    {
        std::shared_ptr<Carte> carte = cartes[i].getCarte();

        if (carte->getSymbole() == "♥")
        {
            points++;
        }

        if (carte->getValeur() == "Q" && carte->getSymbole() == "♠")
        {
            points += 13;
        }
    }

    return points;
}

void RegleDameDePique::echangerCartes(std::vector<std::unique_ptr<Joueur>>& joueurs) const
{
    int typeEchange = (numeroManche - 1) % 4;

    if (typeEchange == 3)
    {
        std::cout << "Aucun echange pour cette manche." << std::endl;
        return;
    }

    std::vector<std::vector<std::shared_ptr<Carte>>> cartesPassees(4);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cartesPassees[i].push_back(joueurs[i]->getMain().retirerCarte(0));
        }
    }

    for (int i = 0; i < 4; i++)
    {
        int destinataire;

        if (typeEchange == 0)
        {
            destinataire = (i + 1) % 4; // gauche
        }
        else if (typeEchange == 1)
        {
            destinataire = (i + 3) % 4; // droite
        }
        else
        {
            destinataire = (i + 2) % 4; // face
        }

        for (int j = 0; j < 3; j++)
        {
            joueurs[destinataire]->getMain().recevoirCarte(cartesPassees[i][j]);
        }
    }
}
int RegleDameDePique::trouverPremierJoueur(const std::vector<std::unique_ptr<Joueur>>& joueurs) const
{
    for (int i = 0; i < joueurs.size(); i++)
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
bool RegleDameDePique::partieTerminee(const std::vector<std::unique_ptr<Joueur>>& joueurs) const
{
    for (int i = 0; i < joueurs.size(); i++)
    {
        if (joueurs[i]->getScore() >= 100)
        {
            return true;
        }
    }

    return false;
}

bool RegleDameDePique::sontCoeursCasses() const
{
    return coeursCasses;
}

void RegleDameDePique::notifierCarteJouee(const Carte& carte, const Pli&)
{
    if (carte.getSymbole() == "♥")
    {
        coeursCasses = true;
    }
}

void RegleDameDePique::notifierFinPli(const Pli&)
{
    if (premierPli)
    {
        premierPli = false;
    }
}
void RegleDameDePique::debutNouvelleManche()
{
    coeursCasses = false;
    premierPli = true;
}

bool RegleDameDePique::estPremierPli() const
{
    return premierPli;
}

void RegleDameDePique::appliquerReglesFinManche(
    std::vector<std::unique_ptr<Joueur>>& joueurs
) const
{
    for (int i = 0; i < joueurs.size(); i++)
    {
        if (joueurs[i]->getScoreManche() == 26)
        {
            std::cout << std::endl;
            std::cout << "===== SHOOT THE MOON =====" << std::endl;
            std::cout << joueurs[i]->getNom()
                << " a capture tous les points !"
                << std::endl;

            joueurs[i]->remettreScoreMancheAZero();

            for (int j = 0; j < joueurs.size(); j++)
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
void RegleDameDePique::passerMancheSuivante()
{
    numeroManche++;
}

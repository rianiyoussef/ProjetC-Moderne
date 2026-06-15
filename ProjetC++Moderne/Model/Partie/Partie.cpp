#include "Partie.h"
#include "../Regles/ReglesJeu.h"
#include <iostream>

Partie::Partie(std::unique_ptr<ReglesJeu> desRegles)
    : regles(std::move(desRegles)),
    indiceJoueurCourant(0),
    premierTour(true)
{
    paquet = regles->creerPaquet();
}

void Partie::ajouterJoueur(const std::string& nom)
{
    joueurs.push_back(
        std::make_unique<Joueur>(
            nom,
            std::make_unique<StrategieAleatoire>()
        )
    );
}


void Partie::distribuer()
{
    paquet->melanger();

    while (!paquet->estVide())
    {
        for (int i = 0; i < joueurs.size(); i++)
        {
            if (!paquet->estVide())
            {
                joueurs[i]->getMain().recevoirCarte(paquet->piocher());
            }
        }
    }
}

void Partie::afficherJoueurs() const
{
    for (int i = 0; i < joueurs.size(); i++)
    {
        std::cout << i << " : " << joueurs[i]->getNom() << std::endl;
    }
}

void Partie::afficherMains() const
{
    for (int i = 0; i < joueurs.size(); i++)
    {
        std::cout << std::endl;
        std::cout << "Main de " << joueurs[i]->getNom() << " :" << std::endl;

        joueurs[i]->getMain().afficherMain();
    }
}
void Partie::jouerTour()
{
    Pli pli;

    for (int tour = 0; tour < joueurs.size(); tour++)
    {
        int i = (indiceJoueurCourant + tour) % joueurs.size();

        std::shared_ptr<Carte> carte;

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
            carte =
                joueurs[i]->jouerCarte(pli, *regles);
        }
        if (carte == nullptr)
        {
            std::cout << "Erreur : aucune carte jouee." << std::endl;
            return;
        }

        CarteJouee cj(carte, i);

        pli.ajouterCarte(cj);

        regles->notifierCarteJouee(*carte, pli);

        std::cout << joueurs[i]->getNom()
            << " joue : "
            << carte->afficher()
            << std::endl;
    }

    int gagnant = regles->determinerGagnantPli(pli);
    int points = regles->calculerPointsPli(pli);

    joueurs[gagnant]->ajouterPointsManche(points);

    regles->notifierFinPli(pli);

    std::cout << "Gagnant du pli : "
        << joueurs[gagnant]->getNom()
        << std::endl;

    std::cout << "Points du pli : "
        << points
        << std::endl;

    indiceJoueurCourant = gagnant;

    premierTour = false;

    plis.push_back(pli);
}


void Partie::afficherScores() const
{
    std::cout << std::endl;
    std::cout << "===== SCORES TOTAUX =====" << std::endl;

    for (int i = 0; i < joueurs.size(); i++)
    {
        std::cout << joueurs[i]->getNom()
            << " : "
            << joueurs[i]->getScore()
            << " points"
            << std::endl;
    }
}



void Partie::jouerManche()
{
    for (int i = 0; i < 13; i++)
    {
        std::cout << std::endl;
        std::cout << "========== PLI "
            << i + 1
            << " =========="
            << std::endl;

        jouerTour();
    }

    regles->appliquerReglesFinManche(joueurs);

    // DEBUG
    std::cout << std::endl;
    std::cout << "===== SCORES DE LA MANCHE =====" << std::endl;

    for (int i = 0; i < joueurs.size(); i++)
    {
        std::cout << joueurs[i]->getNom()
            << " : "
            << joueurs[i]->getScoreManche()
            << " points"
            << std::endl;
    }

    for (int i = 0; i < joueurs.size(); i++)
    {
        joueurs[i]->validerScoreManche();
        joueurs[i]->remettreScoreMancheAZero();
    }

    afficherScores();
    regles->passerMancheSuivante();
}
void Partie::jouerPartie()
{
    while (!regles->partieTerminee(joueurs))
    {
        nouvelleManche();
    }

    std::cout << std::endl;
    std::cout << "===== FIN DE PARTIE =====" << std::endl;

    afficherScores();
}
void Partie::nouvelleManche()
{
    paquet = regles->creerPaquet();

    regles->debutNouvelleManche();

    for (int i = 0; i < joueurs.size(); i++)
    {
        joueurs[i]->getMain().viderMain();
    }

    plis.clear();

    premierTour = true;

    distribuer();

    regles->echangerCartes(joueurs);
    indiceJoueurCourant = regles->trouverPremierJoueur(joueurs);

    jouerManche();
}
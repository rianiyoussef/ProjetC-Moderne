#include "Partie.h"
#include "../Regles/ReglesJeu.h"

Partie::Partie(std::unique_ptr<ReglesJeu> desRegles)
    : regles(std::move(desRegles)),
    indiceJoueurCourant(0),
    premierTour(true),
    dernierGagnant(-1),
    derniersPoints(0)
{
    paquet = regles->creerPaquet();
}
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

void Partie::distribuer()
{
    paquet->melanger();

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

Pli Partie::jouerTour(
    const std::function<void(int, const Pli&)>& avantCarte,
    const std::function<void(int, const Carte&, const Pli&)>& apresCarte
)
{
    Pli pli;

    for (int tour = 0; tour < static_cast<int>(joueurs.size()); tour++)
    {
        int i = (indiceJoueurCourant + tour) % static_cast<int>(joueurs.size());

        if (avantCarte)
        {
            avantCarte(i, pli);
        }

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
            carte = joueurs[i]->jouerCarte(pli, *regles);
        }

        if (carte == nullptr)
        {
            return pli;
        }

        CarteJouee cj(carte, i);
        pli.ajouterCarte(cj);

        regles->notifierCarteJouee(*carte, pli);

        if (apresCarte)
        {
            apresCarte(i, *carte, pli);
        }
    }

    int gagnant = regles->determinerGagnantPli(pli);
    int points = regles->calculerPointsPli(pli);

    joueurs[gagnant]->ajouterPointsManche(points);

    regles->notifierFinPli(pli);

    indiceJoueurCourant = gagnant;
    premierTour = false;

    dernierGagnant = gagnant;
    derniersPoints = points;

    plis.push_back(pli);

    return pli;
}

void Partie::nouvelleManche(
    const std::function<void(int, int)>& avantEchange,
    const std::function<void(int, int)>& apresEchange
)
{
    paquet = regles->creerPaquet();

    regles->debutNouvelleManche();

    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        joueurs[i]->getMain().viderMain();
    }

    plis.clear();

    premierTour = true;
    dernierGagnant = -1;
    derniersPoints = 0;

    distribuer();

    regles->echangerCartes(joueurs, avantEchange, apresEchange);

    indiceJoueurCourant =
        regles->trouverPremierJoueur(joueurs);
}

void Partie::validerFinManche()
{
    regles->appliquerReglesFinManche(joueurs);

    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        joueurs[i]->validerScoreManche();
        joueurs[i]->remettreScoreMancheAZero();
    }

    regles->passerMancheSuivante();
}

const std::vector<std::unique_ptr<Joueur>>& Partie::getJoueurs() const
{
    return joueurs;
}

bool Partie::estTerminee() const
{
    return regles->partieTerminee(joueurs);
}

int Partie::getDernierGagnant() const
{
    return dernierGagnant;
}

int Partie::getDerniersPoints() const
{
    return derniersPoints;
}
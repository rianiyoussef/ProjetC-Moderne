#include "MoteurJeu.h"

#include "FabriqueDameDePique.h"
#include "../Model/Partie/CarteJouee.h"

MoteurJeu::MoteurJeu()
{
}

MoteurJeu& MoteurJeu::getInstance()
{
    static MoteurJeu instance;
    return instance;
}

void MoteurJeu::setInterface(std::shared_ptr<InterfaceUtilisateur> interfaceVue)
{
    interfaceUtilisateur = interfaceVue;
}

int MoteurJeu::compterJoueursHumains() const
{
    int total = 0;

    for (bool estHumain : joueursHumains)
    {
        if (estHumain)
        {
            total++;
        }
    }

    return total;
}

void MoteurJeu::afficherPliCourant(const Pli& pli) const
{
    const std::vector<CarteJouee>& cartesJouees =
        pli.getCartesJouees();

    const std::vector<std::unique_ptr<Joueur>>& joueurs =
        partieCourante->getJoueurs();

    interfaceUtilisateur->afficherMessage("--- Cartes deja posees ---");

    if (cartesJouees.empty())
    {
        interfaceUtilisateur->afficherMessage("Aucune carte pour le moment.");
        return;
    }

    for (int i = 0; i < static_cast<int>(cartesJouees.size()); i++)
    {
        int indiceJoueur = cartesJouees[i].getIndiceJoueur();

        interfaceUtilisateur->afficherMessage(
            joueurs[indiceJoueur]->getNom()
            + " : "
            + cartesJouees[i].getCarte()->afficher()
        );
    }
}

std::string MoteurJeu::nomTypeEchange(int typeEchange) const
{
    if (typeEchange == 0)
    {
        return "vers le joueur de gauche";
    }

    if (typeEchange == 1)
    {
        return "vers le joueur de droite";
    }

    if (typeEchange == 2)
    {
        return "vers le joueur en face";
    }

    return "sans echange";
}

void MoteurJeu::creerPartie()
{
    FabriqueDameDePique fabrique;
    partieCourante = fabrique.creerPartie();
    joueursHumains.clear();
}

void MoteurJeu::ajouterJoueursParDefaut()
{
    joueursHumains.clear();

    partieCourante->ajouterJoueur(
        "Joueur 1",
        std::make_unique<StrategieAleatoire>()
    );
    joueursHumains.push_back(false);

    partieCourante->ajouterJoueur(
        "Joueur 2",
        std::make_unique<StrategieAleatoire>()
    );
    joueursHumains.push_back(false);

    partieCourante->ajouterJoueur(
        "Joueur 3",
        std::make_unique<StrategieAleatoire>()
    );
    joueursHumains.push_back(false);

    partieCourante->ajouterJoueur(
        "Joueur 4",
        std::make_unique<StrategieAleatoire>()
    );
    joueursHumains.push_back(false);
}

void MoteurJeu::afficherJoueurs() const
{
    const std::vector<std::unique_ptr<Joueur>>& joueurs =
        partieCourante->getJoueurs();

    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        interfaceUtilisateur->afficherMessage(
            std::to_string(i) + " : " + joueurs[i]->getNom()
        );
    }
}

void MoteurJeu::afficherMains() const
{
    const std::vector<std::unique_ptr<Joueur>>& joueurs =
        partieCourante->getJoueurs();

    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        interfaceUtilisateur->afficherMessage("");

        interfaceUtilisateur->afficherMessage(
            "Main de " + joueurs[i]->getNom() + " :"
        );

        interfaceUtilisateur->afficherMain(joueurs[i]->getMain());
    }
}

void MoteurJeu::lancerPartie()
{
    interfaceUtilisateur->afficherMessage("===== DEBUT DE LA PARTIE =====");

    while (!partieCourante->estTerminee())
    {
        int nombreHumainsEchange = compterJoueursHumains();

        auto avantEchange =
            [this, nombreHumainsEchange](int indiceJoueur, int typeEchange)
            {
                const std::vector<std::unique_ptr<Joueur>>& joueurs =
                    partieCourante->getJoueurs();

                bool estHumain = joueursHumains[indiceJoueur];
                std::string nomJoueur = joueurs[indiceJoueur]->getNom();
                std::string direction = nomTypeEchange(typeEchange);

                if (estHumain)
                {
                    if (nombreHumainsEchange > 1)
                    {
                        interfaceUtilisateur->afficherMessage("");
                        interfaceUtilisateur->afficherMessage(
                            "Passez le clavier a " + nomJoueur + "."
                        );
                        interfaceUtilisateur->attendreEntree();
                        interfaceUtilisateur->effacerEcran();
                    }

                    interfaceUtilisateur->afficherMessage("");
                    interfaceUtilisateur->afficherMessage(
                        "===== ECHANGE DES CARTES ====="
                    );
                    interfaceUtilisateur->afficherMessage(
                        nomJoueur + ", choisissez 3 cartes a echanger "
                        + direction + "."
                    );
                }
                else
                {
                    interfaceUtilisateur->afficherMessage(
                        nomJoueur + " (IA) choisit 3 cartes a echanger "
                        + direction + "..."
                    );
                }
            };

        auto apresEchange =
            [this](int indiceJoueur, int)
            {
                const std::vector<std::unique_ptr<Joueur>>& joueurs =
                    partieCourante->getJoueurs();

                if (joueursHumains[indiceJoueur])
                {
                    interfaceUtilisateur->afficherMessage(
                        "Cartes selectionnees pour "
                        + joueurs[indiceJoueur]->getNom() + "."
                    );

                    interfaceUtilisateur->attendreEntree();
                }
                else
                {
                    interfaceUtilisateur->afficherMessage(
                        joueurs[indiceJoueur]->getNom()
                        + " (IA) a choisi ses cartes."
                    );
                }
            };

        partieCourante->nouvelleManche(avantEchange, apresEchange);

        for (int i = 0; i < 13; i++)
        {
            interfaceUtilisateur->afficherMessage("");
            interfaceUtilisateur->afficherMessage(
                "========== PLI " + std::to_string(i + 1) + " =========="
            );

            const std::vector<std::unique_ptr<Joueur>>& joueurs =
                partieCourante->getJoueurs();

            int nombreHumains = compterJoueursHumains();

            auto avantCarte =
                [this, &joueurs, nombreHumains](int indiceJoueur, const Pli& pli)
                {
                    bool estHumain = joueursHumains[indiceJoueur];
                    std::string nomJoueur = joueurs[indiceJoueur]->getNom();

                    if (estHumain)
                    {
                        if (nombreHumains > 1)
                        {
                            interfaceUtilisateur->afficherMessage("");
                            interfaceUtilisateur->afficherMessage(
                                "Passez le clavier a " + nomJoueur + "."
                            );
                            interfaceUtilisateur->afficherMessage(
                                "Vous pouvez lire la fin du pli precedent et les cartes deja jouees avant de continuer."
                            );
                            interfaceUtilisateur->attendreEntree();
                            interfaceUtilisateur->effacerEcran();
                        }

                        interfaceUtilisateur->afficherMessage("");
                        interfaceUtilisateur->afficherMessage(
                            "===== A " + nomJoueur + " de jouer ====="
                        );

                        afficherPliCourant(pli);
                    }
                    else
                    {
                        interfaceUtilisateur->afficherMessage("");
                        interfaceUtilisateur->afficherMessage(
                            "Tour de " + nomJoueur + " (IA)..."
                        );
                    }
                };

            auto apresCarte =
                [this, &joueurs](int indiceJoueur, const Carte& carte, const Pli&)
                {
                    std::string typeJoueur = joueursHumains[indiceJoueur]
                        ? ""
                        : " (IA)";

                    interfaceUtilisateur->afficherMessage(
                        joueurs[indiceJoueur]->getNom()
                        + typeJoueur
                        + " joue : "
                        + carte.afficher()
                    );
                };

            Pli pli = partieCourante->jouerTour(
                avantCarte,
                apresCarte
            );

            interfaceUtilisateur->afficherMessage("");
            interfaceUtilisateur->afficherMessage("--- Fin du pli ---");
            afficherPliCourant(pli);

            int gagnant =
                partieCourante->getDernierGagnant();

            interfaceUtilisateur->afficherMessage(
                "Gagnant du pli : " + joueurs[gagnant]->getNom()
            );

            interfaceUtilisateur->afficherMessage(
                "Points du pli : "
                + std::to_string(partieCourante->getDerniersPoints())
            );
        }

        interfaceUtilisateur->afficherMessage("");

        interfaceUtilisateur->afficherMessage(
            "===== SCORES DE LA MANCHE ====="
        );

        const std::vector<std::unique_ptr<Joueur>>& joueurs =
            partieCourante->getJoueurs();

        for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
        {
            interfaceUtilisateur->afficherMessage(
                joueurs[i]->getNom()
                + " : "
                + std::to_string(joueurs[i]->getScoreManche())
                + " points"
            );
        }

        partieCourante->validerFinManche();

        interfaceUtilisateur->afficherScores(
            partieCourante->getJoueurs()
        );
    }

    interfaceUtilisateur->afficherMessage("");
    interfaceUtilisateur->afficherMessage("===== FIN DE PARTIE =====");

    interfaceUtilisateur->afficherScores(
        partieCourante->getJoueurs()
    );
}

void MoteurJeu::demarrer()
{
    int choix = -1;

    interfaceUtilisateur->afficherMessage(
        "Bienvenue dans le jeu de plis !"
    );

    while (choix != 0)
    {
        afficherMenuPrincipal();

        choix = interfaceUtilisateur->demanderChoix();

        traiterChoixJeu(choix);
    }
}

void MoteurJeu::quitter()
{
    interfaceUtilisateur->afficherMessage("Au revoir !");
}
void MoteurJeu::afficherMenuPrincipal() const
{
    interfaceUtilisateur->afficherMessage("");
    interfaceUtilisateur->afficherMessage("===== MENU PRINCIPAL =====");
    interfaceUtilisateur->afficherMessage("1. Dame de Pique");
    interfaceUtilisateur->afficherMessage("2. Belote");
    interfaceUtilisateur->afficherMessage("3. Tarot");
    interfaceUtilisateur->afficherMessage("4. Manille");
    interfaceUtilisateur->afficherMessage("0. Quitter");
}

void MoteurJeu::traiterChoixJeu(int choix)
{
    if (choix == 1)
    {
        configurerDameDePique();
        lancerPartie();
    }
    else if (choix == 0)
    {
        quitter();
    }
    else if (choix == 2 || choix == 3 || choix == 4)
    {
        interfaceUtilisateur->afficherMessage(
            "Desole, ce jeu n'est pas encore en service."
        );
    }
    else
    {
        interfaceUtilisateur->afficherMessage(
            "Choix invalide."
        );
    }
}
void MoteurJeu::configurerDameDePique()
{
    interfaceUtilisateur->afficherMessage("");
    interfaceUtilisateur->afficherMessage(
        "Configuration de la Dame de Pique..."
    );

    creerPartie();

    for (int i = 1; i <= 4; i++)
    {
        interfaceUtilisateur->afficherMessage("");
        interfaceUtilisateur->afficherMessage(
            "Configuration du joueur " + std::to_string(i)
        );

        interfaceUtilisateur->afficherMessage("1. Joueur humain");
        interfaceUtilisateur->afficherMessage("2. IA aleatoire");

        int choixType = interfaceUtilisateur->demanderChoix();

        std::string nom = "Joueur " + std::to_string(i);

        if (choixType == 1)
        {
            partieCourante->ajouterJoueur(
                nom,
                std::make_unique<StrategieHumaine>(
                    interfaceUtilisateur
                )
            );
            joueursHumains.push_back(true);
        }
        else
        {
            partieCourante->ajouterJoueur(
                nom,
                std::make_unique<StrategieAleatoire>()
            );
            joueursHumains.push_back(false);
        }
    }

    interfaceUtilisateur->afficherMessage("");
    interfaceUtilisateur->afficherMessage("Joueurs crees :");

    afficherJoueurs();
}
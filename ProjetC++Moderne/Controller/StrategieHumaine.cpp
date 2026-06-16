#include "StrategieHumaine.h"

StrategieHumaine::StrategieHumaine(
    std::shared_ptr<InterfaceUtilisateur> uneInterface
)
    : interfaceUtilisateur(uneInterface)
{
}

std::shared_ptr<Carte> StrategieHumaine::choisirCarte(
    MainJoueur& main,
    const Pli& pli,
    const ReglesJeu& regles
)
{
    int choix = -1;
    bool choixCorrect = false;

    while (!choixCorrect)
    {
        interfaceUtilisateur->afficherMessage("");
        interfaceUtilisateur->afficherMessage("Votre main :");

        interfaceUtilisateur->afficherMain(main);

        choix = interfaceUtilisateur->demanderChoix();

        if (choix >= 0 && choix < main.nombreCartes())
        {
            if (regles.coupAutorise(
                *main.getCarte(choix),
                pli,
                main
            ))
            {
                choixCorrect = true;
            }
            else
            {
                interfaceUtilisateur->afficherMessage(
                    "Coup non autorise. Choisissez une autre carte."
                );
            }
        }
        else
        {
            interfaceUtilisateur->afficherMessage(
                "Indice invalide. Reessayez."
            );
        }
    }

    return main.jouerCarte(choix);
}

std::vector<std::shared_ptr<Carte>> StrategieHumaine::choisirCartesAEchanger(
    MainJoueur& main,
    int nombreCartes
)
{
    std::vector<std::shared_ptr<Carte>> cartesChoisies;

    interfaceUtilisateur->afficherMessage("");
    interfaceUtilisateur->afficherMessage(
        "Selectionnez les cartes une par une."
    );

    while (static_cast<int>(cartesChoisies.size()) < nombreCartes)
    {
        interfaceUtilisateur->afficherMessage("");
        interfaceUtilisateur->afficherMessage(
            "Cartes restantes dans votre main :"
        );
        interfaceUtilisateur->afficherMain(main);

        interfaceUtilisateur->afficherMessage(
            "Indice de la carte a echanger :"
        );

        int choix = interfaceUtilisateur->demanderChoix();

        if (choix >= 0 && choix < main.nombreCartes())
        {
            cartesChoisies.push_back(main.retirerCarte(choix));
        }
        else
        {
            interfaceUtilisateur->afficherMessage(
                "Indice invalide. Reessayez."
            );
        }
    }

    return cartesChoisies;
}

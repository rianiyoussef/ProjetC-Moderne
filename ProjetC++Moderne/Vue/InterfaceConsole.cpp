#include "InterfaceConsole.h"
#include <iostream>
#include <limits>

// Affiche un message simple à l’écran
void InterfaceConsole::afficherMessage(const std::string& message)
{
    std::cout << message << std::endl;
}

// Demande un choix à l’utilisateur
int InterfaceConsole::demanderChoix()
{
    int choix;
    std::cout << "Votre choix : ";
    std::cin >> choix;
    return choix;
}

// Affiche les cartes de la main avec leurs indices
void InterfaceConsole::afficherMain(const MainJoueur& main)
{
    for (int i = 0; i < main.nombreCartes(); i++)
    {
        std::cout << i << " : "
            << main.getCarte(i)->afficher()
            << std::endl;
    }
}

// Affiche les scores des joueurs
void InterfaceConsole::afficherScores(const std::vector<std::unique_ptr<Joueur>>& joueurs)
{
    std::cout << "\n===== SCORES =====" << std::endl;

    for (int i = 0; i < static_cast<int>(joueurs.size()); i++)
    {
        std::cout << joueurs[i]->getNom()
            << " : "
            << joueurs[i]->getScore()
            << " points"
            << std::endl;
    }
}

// Attend que l’utilisateur appuie sur Entrée
void InterfaceConsole::attendreEntree()
{
    std::cout << "Appuyez sur Entree pour continuer...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// Efface l’écran en affichant des lignes vides
void InterfaceConsole::effacerEcran()
{
    for (int i = 0; i < 40; i++)
    {
        std::cout << std::endl;
    }
}
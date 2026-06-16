#include "InterfaceConsole.h"
#include <iostream>
#include <limits>

void InterfaceConsole::afficherMessage(const std::string& message)
{
    std::cout << message << std::endl;
}

int InterfaceConsole::demanderChoix()
{
    int choix;
    std::cout << "Votre choix : ";
    std::cin >> choix;
    return choix;
}

void InterfaceConsole::afficherMain(const MainJoueur& main)
{
    for (int i = 0; i < main.nombreCartes(); i++)
    {
        std::cout << i << " : "
            << main.getCarte(i)->afficher()
            << std::endl;
    }
}

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

void InterfaceConsole::attendreEntree()
{
    std::cout << "Appuyez sur Entree pour continuer...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

void InterfaceConsole::effacerEcran()
{
    for (int i = 0; i < 40; i++)
    {
        std::cout << std::endl;
    }
}
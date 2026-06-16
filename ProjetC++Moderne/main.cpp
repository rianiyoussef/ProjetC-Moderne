#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Controller/MoteurJeu.h"
#include "Vue/InterfaceConsole.h"

int main()
{
#ifdef _WIN32
    // Active l'affichage UTF-8 dans la console
    SetConsoleOutputCP(CP_UTF8);
#endif

    // Création de l'interface console
    std::shared_ptr<InterfaceUtilisateur> vue =
        std::make_shared<InterfaceConsole>();

    // Récupération du moteur de jeu
    MoteurJeu& moteur = MoteurJeu::getInstance();

    moteur.setInterface(vue);
    moteur.demarrer();

    return 0;
}
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

#include "Controller/MoteurJeu.h"
#include "Vue/InterfaceConsole.h"

int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::shared_ptr<InterfaceUtilisateur> vue =
        std::make_shared<InterfaceConsole>();

    MoteurJeu& moteur = MoteurJeu::getInstance();

    moteur.setInterface(vue);
    moteur.demarrer();

    return 0;
}

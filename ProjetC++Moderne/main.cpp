#include <iostream>
#include <memory>
#ifdef _WIN32
#include <windows.h>
#endif
#include "Model/Partie/Partie.h"
#include "Model/Regles/RegleDameDePique.h"
#include "Model/Paquet/Paquet52Cartes.h"
int main()
{
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::cout << "=== Test des symboles ===" << std::endl;
    std::cout << "♠ ♥ ♦ ♣" << std::endl;

    std::cout << std::endl;
    std::cout << "=== Test d'une carte ===" << std::endl;

    Paquet52Cartes paquetTest;
    paquetTest.melanger();

    std::shared_ptr<Carte> carte = paquetTest.piocher();

    std::cout << "Carte : " << carte->afficher() << std::endl;
    std::cout << "Valeur : " << carte->getValeur() << std::endl;
    std::cout << "Symbole : " << carte->getSymbole() << std::endl;
    std::cout << "Couleur : " << carte->getCouleur() << std::endl;

    std::cout << std::endl;
    std::cout << "=== Test d'une partie ===" << std::endl;

    Partie partie(std::make_unique<RegleDameDePique>());

    partie.ajouterJoueur("Joueur 1");
    partie.ajouterJoueur("Joueur 2");
    partie.ajouterJoueur("Joueur 3");
    partie.ajouterJoueur("Joueur 4");

    partie.jouerPartie();
    return 0;
}
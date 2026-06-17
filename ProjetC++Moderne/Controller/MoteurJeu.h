#ifndef MOTEURJEU_H
#define MOTEURJEU_H

#include <memory>
#include <vector>
#include <string>

#include "../Model/Partie/Partie.h"
#include "../Vue/InterfaceUtilisateur.h"
#include "../Model/Joueur/StrategieAleatoire.h"
#include "../Model/Joueur/StrategieHumaine.h"

class MoteurJeu
{
private:
    // Partie en cours
    std::unique_ptr<Partie> partieCourante;

    // Interface utilisateur
    std::shared_ptr<InterfaceUtilisateur> interfaceUtilisateur;

    // Type des joueurs (humain ou IA)
    std::vector<bool> joueursHumains;

    MoteurJeu();

    // Nombre de joueurs humains
    int compterJoueursHumains() const;

    // Affichage du pli courant
    void afficherPliCourant(const Pli& pli) const;

    // Nom de la direction d'échange
    std::string nomTypeEchange(int typeEchange) const;

public:
    // Instance unique du moteur
    static MoteurJeu& getInstance();

    MoteurJeu(const MoteurJeu&) = delete;
    MoteurJeu& operator=(const MoteurJeu&) = delete;

    void setInterface(std::shared_ptr<InterfaceUtilisateur> interfaceVue);

    void creerPartie();
    void ajouterJoueursParDefaut();

    void afficherJoueurs() const;
    void afficherMains() const;

    void lancerPartie();
    void demarrer();
    void quitter();

    void afficherMenuPrincipal() const;
    void traiterChoixJeu(int choix);
    void configurerDameDePique();
};

#endif
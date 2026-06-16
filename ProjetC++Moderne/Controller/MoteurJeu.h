#ifndef MOTEURJEU_H
#define MOTEURJEU_H

#include <memory>
#include <vector>
#include <string>

#include "../Model/Partie/Partie.h"
#include "../Vue/InterfaceUtilisateur.h"
#include "../Model/Joueur/StrategieAleatoire.h"
#include "StrategieHumaine.h"

class MoteurJeu
{
private:
    std::unique_ptr<Partie> partieCourante;
    std::shared_ptr<InterfaceUtilisateur> interfaceUtilisateur;
    std::vector<bool> joueursHumains;

    MoteurJeu();
    int compterJoueursHumains() const;
    void afficherPliCourant(const Pli& pli) const;
    std::string nomTypeEchange(int typeEchange) const;

public:
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
#ifndef REGLESJEU_H
#define REGLESJEU_H
#include "../Joueur/MainJoueur.h"
#include <vector>
#include <functional>
#include "../Joueur/Joueur.h"

#include <memory>

class Carte;
class Pli;
class Paquet;

class ReglesJeu
{
public:
    virtual bool coupAutorise(const Carte& carte, const Pli& pli, const MainJoueur& main) const = 0;

    virtual int determinerGagnantPli(const Pli& pli) const = 0;

    virtual std::unique_ptr<Paquet> creerPaquet() const = 0;

    virtual ~ReglesJeu() = default;
    
    virtual int calculerPointsPli(const Pli& pli) const = 0;

    virtual void echangerCartes(
        std::vector<std::unique_ptr<Joueur>>& joueurs,
        const std::function<void(int, int)>& avantEchange = nullptr,
        const std::function<void(int, int)>& apresEchange = nullptr
    ) const = 0;

    virtual int trouverPremierJoueur(const std::vector<std::unique_ptr<Joueur>>& joueurs) const = 0;

    virtual bool partieTerminee(const std::vector<std::unique_ptr<Joueur>>& joueurs) const = 0;
    
    virtual void appliquerReglesFinManche(
        std::vector<std::unique_ptr<Joueur>>& joueurs
    ) const = 0;
    virtual void debutNouvelleManche() = 0;

    virtual void passerMancheSuivante() = 0;

    virtual void notifierCarteJouee(const Carte&, const Pli&) {}

    virtual void notifierFinPli(const Pli&) {}
};

#endif
#pragma once
#ifndef MAINJOUEUR_H
#define MAINJOUEUR_H

#include <vector>
#include <memory>

#include "../Carte/Carte.h"

class MainJoueur
{
private:
    std::vector<std::shared_ptr<Carte>> cartes;

public:
    void recevoirCarte(std::shared_ptr<Carte> carte);

    std::shared_ptr<Carte> jouerCarte(int indice);

    bool estVide() const;

    int nombreCartes() const;

    std::shared_ptr<Carte> getCarte(int indice) const;

    std::shared_ptr<Carte> retirerCarte(int indice);

    int trouverCarte(const std::string& valeur, const std::string& symbole) const;

    bool possedeSymbole(const std::string& symbole) const;

    void viderMain();

    bool possedeAutreQueSymbole(const std::string& symbole) const;

    bool possedeCarteAutreQue(
        const std::string& valeur,
        const std::string& symbole
    ) const;
};

#endif
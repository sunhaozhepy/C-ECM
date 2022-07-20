#include <iostream>
#include <string>
#include "Case.h"
#include "Chance.h"
#include "Communaute.h"
#include "Compagnie.h"
#include "De.h"
#include "Depart.h"
#include "Gare.h"
#include "Gobelet.h"
#include "Joueur.h"
#include "Pion.h"
#include "Prison.h"
#include "Propriete.h"
#include "Terrain.h"
#include "Impot.h"
#include "Parc.h"
#include "Police.h"
#include "Jeu.h"
using namespace std;

int main()
{
    cout << "Bienvenue à notre jeu de monopoly via C++!\n";
    int nb_joueurs;
    cout << "Combien y a-t-il de joueurs ?\n";
    cin >> nb_joueurs;

    try
    {
        if (!(3 <= nb_joueurs && nb_joueurs <= 8))
        {
            throw(nb_joueurs);
        };
        Depart c0("Case départ");
        Propriete c1("Boulevard de Belleville", 300, 1200);
        Communaute c2("Caisse de communauté");
        Propriete c3("Rue Lecourbe", 300, 1200);
        Impot c4("Impots sur le revenu");
        Gare c5("Gare Montparnasse", 300, 1200);
        Propriete c6("Rue de Vaugirard", 300, 1200);
        Chance c7("Chance");
        Propriete c8("Rue de Courcelles", 300, 1200);
        Propriete c9("Avenue de la République", 300, 1200);
        Prison c10("Prison");
        Propriete c11("Boulevard de la Villette", 300, 1200);
        Compagnie c12("Compagnie de distribution d'électricité", 300, 1200);
        Propriete c13("Avenue de Neuilly", 300, 1200);
        Propriete c14("Rue de Paradis", 300, 1200);
        Gare c15("Gare de Lyon", 300, 1200);
        Propriete c16("Avenue Mozart", 300, 1200);
        Communaute c17("Caisse de communauté");
        Propriete c18("Boulevard Saint-Michel", 300, 1200);
        Propriete c19("Place Pigalle", 300, 1200);
        Parc c20("Parc Gratuit");
        Propriete c21("Avenue Matignon", 300, 1200);
        Chance c22("Chance");
        Propriete c23("Boulevard Malesherbes", 300, 1200);
        Propriete c24("Avenue Henri-Martin", 300, 1200);
        Gare c25("Gare du Nord", 300, 1200);
        Propriete c26("Faubourg Saint-Honoré", 300, 1200);
        Propriete c27("Place de la Bourse", 300, 1200);
        Compagnie c28("Compagnie de distribution des eaux", 300, 1200);
        Propriete c29("Rue Lafayette", 300, 1200);
        Police c30("Aller en prison");
        Propriete c31("Avenue de Breteuil", 300, 1200);
        Propriete c32("Avenue Foch", 300, 1200);
        Communaute c33("Caisse de communaute");
        Propriete c34("Boulevard des Capucines", 300, 1200);
        Gare c35("Gare Saint-Lazare", 300, 1200);
        Chance c36("Chance");
        Propriete c37("Avenue des Champs-Elysees", 300, 1200);
        Impot c38("Taxe de Luxe");
        Propriete c39("Rue de la Paix", 300, 1200);

        Case plateau[40] = { c0, c1, c2, c3, c4, c5, c6, c7, c8, c9, c10, c11, c12, c13, c14, c15, c16, c17, c18, c19, c20, c21, c22, c23, c24, c25, c26, c27, c28, c29, c30, c31, c32, c33, c34, c35, c36, c37, c38, c39 };
        
        Joueur* joueurs = NULL;
        Pion* pions = NULL;
        joueurs = new Joueur[nb_joueurs];
        pions = new Pion[nb_joueurs];

        for (int i = 0; i < nb_joueurs; i++)
        {
            string nom_joueur;
            cout << "Nom du joueur " << i + 1 << " : ";
            cin >> nom_joueur;
            Joueur joueur(nom_joueur, NULL, 5000);
            joueurs[i] = joueur;
            Pion pion(joueurs + i, plateau);
            pions[i] = pion;
            joueurs[i].setPion(pions + i);
        };

        Jeu jeu(nb_joueurs, joueurs, plateau);
        jeu.commencerLaPartie();
        delete[] joueurs;
        delete[] pions;

    }
    catch (int nb)
    {
        cout << "Le jeu du Monopoly se joue de 3 à 8 joueurs." << endl;
        cout << "Vous avez " << nb << " joueurs." << endl;
        system("pause");
    }
    return 0;
}

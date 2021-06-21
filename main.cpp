/**
 * 
 * @file main.cpp
 * 
 * @author Abderrahmane Zouache / Majdi Kayel
 * @brief 
 * @version 0.1
 * @date 2021-06-17
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>
#include <string>
#include <set>
#include <fstream>

#include "etudiant.hpp"
using namespace std;

/**
 * @brief récupere les donnees des etudiants a partir du fichier "donneesbrutes.txt"
 * 
 * @param fichier 
 * @param etudiants 
 */
void fichierVersProgramme(string fichier, std::set<Etudiant> &etudiants);

/**
 * @brief Affiche le résultat du traitement des données dans le fichier "moyennes.txt"
 * 
 * @param fichier 
 * @param etudiants 
 */
void programmeVersFichier(string fichier, std::set<Etudiant> &etudiants);

int main()
{
	const std::string 
		fichierDonnees{"donneesbrutes.txt"},
		fichierMoyennes{"moyennes.txt"};
	
	std::set<Etudiant> etudiants;

	fichierVersProgramme(fichierDonnees, etudiants);
	programmeVersFichier(fichierMoyennes, etudiants);
}

void fichierVersProgramme(string fichier, std::set<Etudiant> &etudiants)
{
	std::ifstream fichierEtudiants(fichier);

	while (!fichierEtudiants.eof())
	{
		Etudiant etudiant;
		fichierEtudiants >> etudiant; //lecture d'une ligne à la fois
				
		if (etudiant)
			etudiants.insert(etudiant);
	}

	fichierEtudiants.close();
}

void programmeVersFichier(string fichier, std::set<Etudiant> &etudiants)
{
	std::ofstream fichierMoyennes(fichier);

	for (auto iter = etudiants.begin(); iter != etudiants.end(); iter++)
		fichierMoyennes << (*iter);

	fichierMoyennes.close();
}

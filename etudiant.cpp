#include <iostream>

#include "etudiant.hpp"

Etudiant::Etudiant() {}
Etudiant::Etudiant(std::string un_identifiant, long matricule)
{
	un_identifiant = un_identifiant;
	matricule = matricule;
}

double Etudiant::getMoyenne() const
{
	return somme / nombreNotes; 
}

std::istream &operator>>(std::istream &is, Etudiant &etudiant)
{
	//Format : Nom étudiant __ matricule __ nombre de notes __ Notes
	is >> etudiant.un_identifiant >> etudiant.matricule >> etudiant.nombreNotes;

	for (int i{}; i < etudiant.nombreNotes; i++)
	{
		double note{};
		is >> note;
		if (is.fail())
		{
			std::cout << etudiant.MESSAGE_ERREUR << etudiant.un_identifiant << std::endl;
			is.clear();
			break;
		}
		etudiant.notes.push_back(note);
		etudiant.somme += note;
	}
	return is;
}

std::ostream &operator<<(std::ostream &os, const Etudiant &etudiant) 
{
	if (etudiant.nombreNotes == etudiant.notes.size())
		os << etudiant.matricule << " " << etudiant.getMoyenne() << std::endl;
	return os;
}

bool operator<(const Etudiant &_this, const Etudiant &autre)
{
	return _this.matricule < autre.matricule;
}

Etudiant::operator bool() const
{
	return nombreNotes == notes.size();
}
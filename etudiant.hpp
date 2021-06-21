

#ifndef _ETUDIANT_HPP
#define _ETUDIANT_HPP

#include <string>
#include <list>

class Etudiant
{
private:
	std::string un_identifiant;
	long matricule;
	int nombreNotes{};
	std::list<double> notes; //Relevet de notes 
	double somme{};
	

public:
	Etudiant();
	Etudiant(std::string un_identifiant, long matricule);
    double getMoyenne() const;
	//Opérateurs surchargés
	friend std::istream &operator>>(std::istream &, Etudiant &);
	friend std::ostream &operator<<(std::ostream &, const Etudiant &);
	operator bool() const;
	friend bool operator<(const Etudiant &_this, const Etudiant &autre);

	//Constantes
	const std::string MESSAGE_ERREUR = "Erreur pour l'étudiant(e) : "; 
};

#endif
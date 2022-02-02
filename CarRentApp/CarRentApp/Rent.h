#pragma once
#include "Cars.h"
#include <time.h>
#include <stdio.h>
#include "Menu.h"

class Rent {
public:
	Rent();
	int Option;
	void ViewCarsForRent(Cars Obj1, Menu Obj2);
	void AddRent(Cars Obj1, Menu Obj2);
	void RentingProcess(Cars Obj1);
	vector<string> NrRejWyp;
	void SaveRents();
	void LoadRents();
	void ShowCurrentRents(Menu Obj1, Cars Obj2);
	int CountNumberRents();
	int CountNumberClients();

	struct Klient {
		string Imie;
		string Nazwisko;
		string Pesel;
		string NrTel;
		int LiczbaDni;
		int Kwota;
		string Nr_rejA;
		int DzienStartu;
		int DzienKonca;

	};

	vector<Klient> Klienci;
	void CalculateTime();
	int DaysSinceEpoch();
	void CorrectRents();
	void ArchiveRent(int i); 
	void CutRent();
};


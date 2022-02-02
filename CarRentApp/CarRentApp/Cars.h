#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <windows.h>
#include <chrono>
#include <thread>


using namespace std;


class Cars {
public:

	void LoadCars();
	void AddCar();
	void RemoveCar();
	void CountLine();
	int LineNumber;
	void SaveCars();
	void ViewCars();
	struct Samochod {
		string Marka;
		string Model;
		string NrRej;
		int Rocznik;
		long int Przebieg;
		float CenaZaDzien;
		int Moc;
	};
	void UpdateMileage();
	void UpdatePrice();

	vector<Samochod> Samochody;
	Cars();
	~Cars();
};

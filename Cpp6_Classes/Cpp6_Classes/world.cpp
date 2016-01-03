
#include "world.h"

#include <iostream>
#include <random>
#include <string>
using namespace std;

World::World() 
{
	// Create a world with random materials
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 1000);

	elementZero = dis(gen);
	iridium = dis(gen);
	palladium = dis(gen);
	platinum = dis(gen);

	// Create a world with a random name
	vector<string> names = { "Urdak", "Laena", "Gotha", "Earth", "Sanctum",
		"Neptune", "Tula", "Imorkan", "Bast", "Nephros",
		"Anedia", "Lorek", "Jontan", "Rescel", "Etamis",
		"Daratar", "Gragas", "Korar" };
	uniform_int_distribution<> disNames(0, names.size()-1);
	uniform_int_distribution<> disNumber(1, 7);

	name = names[disNames(gen)] + " " + to_string(disNumber(gen));

	scannedWorlds++;
}

int World::scannedWorlds = 0;		// Static member variable initialization

void World::Scan() 
{

	cout << "\nScanned planet number " << scannedWorlds << ". Several minerals are present in planet \'" << name << "\':\n";
	cout << "Element Zero: " << elementZero << "\n";
	cout << "Iridium: " << iridium << "\n";
	cout << "Palladium: " << palladium << "\n";
	cout << "Platinum: " << this->platinum << "\n";			// Note: "this" returns the pointer for the object!

}

void World::DisplayTotal() 
{
	cout << "Total planets scanned (call static function): " << scannedWorlds << "\n";
}


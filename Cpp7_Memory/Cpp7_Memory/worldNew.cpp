
#include "worldNew.h"

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

	elementZero = new int(dis(gen));
	iridium = new int(dis(gen));
	palladium = new int(dis(gen));
	platinum = new int(dis(gen));

	// Create a world with a random name
	vector<string> names = { "Urdak", "Laena", "Gotha", "Earth", "Sanctum",
		"Neptune", "Tula", "Imorkan", "Bast", "Nephros",
		"Anedia", "Lorek", "Jontan", "Rescel", "Etamis",
		"Daratar", "Gragas", "Korar" };
	uniform_int_distribution<> disNames(0, names.size() - 1);
	uniform_int_distribution<> disNumber(1, 7);

	name = new string(names[disNames(gen)] + " " + to_string(disNumber(gen)));

	scannedWorlds++;
}

int World::scannedWorlds = 0;		// Static member variable initialization

void World::Scan()
{

	cout << "Several minerals are present in planet \'" << *name << "\':\n";
	cout << "Element Zero: " << *elementZero << "\n";
	cout << "Iridium: " << *iridium << "\n";
	cout << "Palladium: " << *palladium << "\n";
	cout << "Platinum: " << *platinum << "\n";	
}

void World::DisplayTotal()
{
	cout << "Total planets scanned (call static function): " << scannedWorlds << "\n";
}

World::~World()
{
	delete name;
	delete elementZero;
	delete iridium;
	delete palladium;
	delete platinum;
	
	name = 0; 
	elementZero = 0;
	iridium = 0;
	palladium = 0;
	platinum = 0;
}

World& World::operator=(const World& w) 
{
	if (this != &w)
	{
		delete name;
		delete elementZero;
		delete iridium;
		delete palladium;
		delete platinum;

		name = new string(*(w.name));
		elementZero = new int(*(w.elementZero));
		iridium = new int(*(w.iridium));
		palladium = new int(*(w.palladium));
		platinum = new int(*(w.platinum));

	}

	return *this;
}


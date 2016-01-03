#pragma once

#include <string>
using namespace std;

class World
{
public:
	string name = "unknown";		// Name of the planet
	static int scannedWorlds;		// Static variable

	World();						// Constructor prototype
	void Scan();
	static void DisplayTotal();		// Static Function
	friend int CalculateMinerals(const World& aWorld); // Friend function

private:
	int elementZero, iridium, palladium, platinum;

};


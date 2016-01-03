// source: example of classes and namespaces
// V1.0

/* Extra tasks
1) play and break with the code.
2) Find out how .h files work and how to create your own.
*/

#include <iostream>
using namespace std;

// Example to include an external header file - please notice we use here quotes instead of <>
#include "intro.h"

// Namespaces examples
namespace Turians
{
	void DisplayInfo()
	{
		cout << "Garrus Vakarian is a turian, formerly part of C-Sec's Investigation Division. \n";
	}
}

namespace Krogan
{
	void DisplayInfo()
	{
		cout << "Urdnot Wrex is a famed krogan mercenary and bounty hunter. \n";
	}
}

namespace Human
{
	void DisplayInfo()
	{
		cout << "Ashley Williams is a human soldier who served in the Systems Alliance as a Gunnery Chief. \n";
	}
}
using namespace Human;

// Class example
#include "world.h"
#include "universe.h"

// Friend example
int CalculateMinerals(const World& aWorld)
{
	return aWorld.elementZero + aWorld.iridium + aWorld.palladium + aWorld.platinum;	// Able to access private variables from class
}

// Friend with operator overload
ostream& operator<<(ostream& os, const Universe& aUniverse)
{
	os << "Planet names in our universe: ";
	for (int i = 0; i < aUniverse.worlds.size(); i++) {
		os << "'" << aUniverse.worlds[i].name << "' ";
	}
	os << endl;

	return os;
}

int main(int argc, char* argv[])
{

	// Example of an external include and header file
	DisplayIntro();

	// Example of namespaces
	cout << endl << "Example of namespaces: \n";
	DisplayInfo();
	Krogan::DisplayInfo();
	Turians::DisplayInfo();

	// Example of classes
	Universe universe;

	World w1;
	w1.Scan();
	universe.Add(w1);

	World w2;
	w2.Scan();
	cout << "Total minerals in w2: " << CalculateMinerals(w2) << endl;
	universe.Add(w2);

	cout << "\nTotal planets scanned: " << World::scannedWorlds << "\n\n";	// Example of static variable
	World::DisplayTotal(); // Example of an static function

	cout << universe;

	return 0;
}
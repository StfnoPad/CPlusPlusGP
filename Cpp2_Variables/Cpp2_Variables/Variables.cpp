// Variables: C++ Arithmetic operators, variables and enumerators
// V 1.0

/*
Extra tasks:
1) play and break the code.
2) Create a small text based game using varibles, enumerators and constants.
*/
#include <iostream>
using namespace std;

int main() {

	// Arithmetic operators
	cout << "Super Mario Bros Stats (using operators as example):" << endl;
	cout << "A coin gives you " << 100 + 100 << " points" << endl;
	cout << "A super mushroom gives you " << 1200 - 200 << " points" << endl;
	cout << "A fire flower gives you " << 10 * 100 << " points" << endl;
	cout << "A super star gives you " << 5000 / 5 << " points" << endl;
	cout << "A 1-up mushroom gives you " << 100 % 100 << " point but " << 101 % 100 << " life" << endl;

	// Varibles examples
	short int			redKoopa = -30;
	unsigned short int	flyingKoopa = 30;
	int					goomba = 100000;
	unsigned int		boo = 4000000;
	long int			megaMole = -32165111;
	float				iggyKoopa = 0.2562352f;
	double				lemmyKoopa = 1.12345615641561;
	long double			ludwigVonKoopa = 5.2564226e250;
	char				pokey = 'y';			// 128 ASCII character set 
	bool				again = true;

	cout << endl << "Testing some variables:" << endl;
	cout << "redKoopa: " << redKoopa << endl;
	cout << "flyingKoopa: " << flyingKoopa << endl;
	cout << "goomba: " << goomba << endl;
	cout << "boo: " << boo << endl;
	cout << "megaMole: " << megaMole << endl;
	cout << "iggyKoopa: " << iggyKoopa << endl;
	cout << "lemmyKoopa: " << lemmyKoopa << endl;
	cout << "ludwigVonKoopa: " << ludwigVonKoopa << endl;
	cout << "pokey: " << pokey << endl;
	cout << "again: " << again << endl;

	// Wrapping around in variables
	redKoopa = 32767;
	cout << endl << "Warp around variable:" << endl;
	cout << "Short int redKoopa: " << redKoopa++ << endl;
	cout << "redKoopa+1: " << redKoopa << endl;

	// Constants
	const int COIN_VALUE = 200;
	unsigned int collectedCoins = 123;
	int score = collectedCoins * COIN_VALUE;
	cout << endl << "Using constants:" << endl;
	cout << "Total score (coints * COINT_VALUE): " << score << endl;

	// Enumerators
	enum difficulty { SETTLER, CHIEFTAIN, WARLORD, PRINCE, KING, EMPERATOR, IMMORTAL, DEITY };
	difficulty defaultDifficulty = difficulty::WARLORD;
	cout << endl << "Using enumerators:" << endl;
	cout << "Default Difficulty: " << defaultDifficulty;

	return 0;
}
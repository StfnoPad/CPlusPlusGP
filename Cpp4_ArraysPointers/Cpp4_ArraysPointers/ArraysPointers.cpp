// ArraysPoints: Simple file showing arrays and pointers.
// V1.0

#include <iostream>
#include <string>
using namespace std;

/*
	Extra tasks:
	1) play and break with the code.
	2) What is the difference between * and & for pointers?
	3) What happens if you dereference a null pointer like pScore?
	4) Research why char* are evil.
	5) On that char* note, have a look at buffer overrun problems.
*/

int main()
{
	// Defining arrays
	int diceSides[6] = { 1, 2, 3, 4, 5, 6 };
	cout << "The lowest number in a dice is: " << diceSides[0] << endl << endl;

	// Referencing example - ps. think of them as nicknames. 
	int myScore = 5000;
	int& onlineScore = myScore;	// Create a reference
	//int& extraScore;	// Illegal - compile error as references always need to be initialised.
	cout << "myScore equals: " << myScore << ", onlineScore equals: " << onlineScore << endl;
	myScore += 1000;
	cout << "(myScore += 1000) myScore equals: " << myScore << ", onlineScore equals: " << onlineScore << endl;
	onlineScore += 500;
	cout << "(onlineScore += 500) myScore equals: " << myScore << ", onlineScore equals: " << onlineScore << endl << endl;

	// Referencing note: a reference always refers to the variable with it was initialised.
	int score1 = 1000;
	int& rScore = score1;
	int score2 = 2000;
	rScore = score2;
	cout << "score1 equals: " << score1 << ", rScore equals: " << rScore << ", score2 equals: " << score2 << endl <<endl;

	// Pointers
	int		score = 120;
	int*	pScore = nullptr;	// Note you can also use 0 or NULL but both have their disadvantages.
	int*	scorePointer = &score;	// Asign pointer scorePointer address to variable score

	cout << "Value of your score: " << score << endl;
	cout << "Address of the score variable: " << &score << endl;
	cout << "Value of scorePointer variable: " << scorePointer << endl;
	cout << "Value of dereferenced scorePointer: " << *scorePointer << endl;
	cout << "Value of dereferenced scorePointer + 10: " << *scorePointer+10 << endl << endl;
	// cout << "Value of dereferenced pScore: " << *pScore << endl; // Dereferencing a null pointer - big problem!

	cout << "Adding 1000 to score..." << endl;
	score += 1000;
	cout << "score equals: " << score << endl;
	cout << "*score equals: " << *scorePointer << endl;

	cout << "Adding 1000 to *scorePointer..." << endl;
	*scorePointer += 1000;
	cout << "score equals: " << score << endl;
	cout << "*score equals: " << *scorePointer << endl << endl;

	cout << "Assigning &newScore to scorePointer" << endl;
	int newScore = 3500;
	scorePointer = &newScore;
	cout << "&newScore equals: " << &newScore << endl;
	cout << "scorePointer equals: " << scorePointer << endl;
	cout << "newScore equals: " << newScore << endl;
	cout << "*scorePointer equals " << *scorePointer << endl << endl;




	// Pointers and arrays
	for (int i = 0; i < 6; i++) {
		cout << "Value of array at position " << i << ": " << *(diceSides + i) << " with location " << &(diceSides[i]) << endl;
	}
	// Note *(diceSides +1) is the same as diceSides[1];

	cout << endl << "What if we use bigger numbers?\n";
	double bignumbers[6] = { 1.2353e10, 0.01123123, 2.12345453, 456784156, 12.000005e-5, 37467.324343443 };
	for (int i = 0; i < 6; i++) {
		cout << "Value of array at position " << i << ": " << *(bignumbers + i) << " with location " << &(bignumbers[i]) << endl;
	}

	// Multidimensional arrays
	const int ROWS = 3;
	const int COLS = 3;

	char board[ROWS][COLS] = {  {'X', 'O', 'O'},
								{'O', 'X', 'O'},
								{'O', 'X', 'X'} };
	cout << endl << "Anyone for a tic-tac-toe game?" << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << board[i][j];
		}
		cout << endl;
	}



	// Array sizes using Char Arrays (Old C Style)
	char name[128];		// need to define length. This will cause lots of problems in the future so avoid.
	cout << "\nWhat is your name? (Old c style)" << endl;
	cin >> name;
	cout << "Hiya " << name << " (size: " << strlen(name) << ")" << endl;	// Spaces here will cause problems and when names are longer than the size of the array.
	
	// Strings (new Style) - if possible always use strings instead of char*.
	string nameString;
	cout << "\nWhat is your name? (new style)" << endl;
	cin >> nameString;
	cout << "Hi again " << nameString << "!" << endl << endl;

	const int NUMBEROFITEMS = 8;
	string inventory[NUMBEROFITEMS] = { "Super Mushroom", "Fire Flower", "Super Leaf", "Star", "Tanooki Suit", "Frog Suit", "Hammer Suit", "Kuribo's Shoe" };
	cout << "Can you guess which game has the following power-ups?" << endl;
	for (int i = 0; i < NUMBEROFITEMS; i++)
	{ 
		cout << i << ") " << inventory[i] << endl;
	}
	cout << endl;

	// Assigning strings
	string str = "It's a-me, Mario!";
	string* pStr = &str;
	cout << "str equals: " << str << endl;
	cout << "*pStr equals: " << *pStr << endl;
	cout << "(*pStr).size() equals: " << (*pStr).size() << endl;
	cout << "pStr->size() equals: " << pStr->size() << endl << endl;

	// Note: Arrays can be difficult in C++ - specially when getting lengths
	cout << "One last thing about arrays..." << endl;
	cout << "Size of items in inventory: " << NUMBEROFITEMS << endl;
	cout << "Size of inventory array using ->size(): " << inventory->size() << endl;
	cout << "Correct size of inventory: " << sizeof(inventory) / sizeof(inventory[0]) << endl;
	cout << "sizeof(inventory) equals: " << sizeof(inventory) << endl;
	cout << "sizeof(inventory[0]) equals: " << sizeof(inventory[0]) << endl;
	cout << "sizeof(*inventory) equals: " << sizeof(*inventory) << endl;
	cout << "This might not work for some pointers and it is a bit confusing.\nThat is why if possible you should always use C++ vectors (see next examples). " << endl;

	return 0;
}
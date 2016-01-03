// Blocks: Simple file showing functions, and building blocks in C++.
// V1.0

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
Extra tasks:
1) play and break with the code.
2) How do references work?
3) Find out what is the point of inline functions
4) Create your own function to calculate an array of scores without duplicating the data.
*/

const int DOTSMULT = 10;	// Defining globals for main and functions.
int ghostMult = 3000;		// You can change this global

void DisplayScore(int dots, int fruit, int ghosts)
{
	cout << "Your score is " << (dots * DOTSMULT) + (fruit * 500) + (ghosts * ghostMult) << endl;
}

int CalculateScore(int dots, int fruit, int ghosts);	// Adding the function after main - needs to be declared here.

void CalculateScore(int dots, int fruit, int ghosts, int* score)
{
	*score = (dots * DOTSMULT) + (fruit * 500) + (ghosts * ghostMult);
}

void DisplayScore(int dots, int fruit, int ghosts, int* level)	// Pointeres
{
	cout << "Your score in level " << *level << " is " << (dots * DOTSMULT) + (fruit * 500) + (ghosts * ghostMult) <<  endl;
}

void SwapScores(int* const scoreA, int* const scoreB)
{
	int temp = *scoreA;
	*scoreA = *scoreB;
	*scoreB = temp;
	// note: The parameters are constant pointers because, although the plan is to change the values they point to, 
	// the pointers themselves will not be changed.
}

void CalculateScore(int dots, int fruit, int ghosts, int& score) // References
{
	score = (dots * DOTSMULT) + (fruit * 500) + (ghosts * ghostMult);
}

void SwapScores(int& scoreA, int& scoreB)
{
	int temp = scoreA;
	scoreA = scoreB;
	scoreB = temp;
}

void ShowDiceSides(int* const array, const int NUM_ELEMENTS)
{
	cout << "Numbers in a dice: ";
	for (int i = 0; i < 6; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}



struct scoreItems
{
	int dots;
	int fruit;
	int ghosts;
};

int ReturnScore(scoreItems scoreI)
{
	return  (scoreI.dots * DOTSMULT) + (scoreI.fruit * 500) + (scoreI.ghosts * ghostMult);
}

inline int ReturnScoreInline(scoreItems scoreI)	// Request compiler to copy function to gain performance.
{
	return  (scoreI.dots * DOTSMULT) + (scoreI.fruit * 500) + (scoreI.ghosts * ghostMult);
}

string* pointerToElement(vector<string>* const pVec, int i)
{
	return &((*pVec)[i]);
}

string* badPointer()
{
	string local = "This string will ceae to exist once the function ends.";
	string* pLocal = &local;
	return pLocal;
}



int main(int argc, char* argv[])
{

	// Simple function examples
	DisplayScore(1554, 20, 52);

	cout << "Your calculated score is " << CalculateScore(1554, 20, 52) << endl;

	// Passing by pointer
	int score = 0; 
	CalculateScore(1554, 20, 52, &score);	// Passing by pointer
	cout << "Your calculated score is " << score << endl << endl;

	//int level;	// Uncomment this, does it work? why not?
	//DisplayScore(1554, 20, 52, &level);
	// // DisplayScore(1554, 20, 52, nullptr); //  This compiles but will crash the program.

	//Swapping by pointer
	int sA = 750;
	int sB = 1250;
	cout << "Swap pointers:" << endl;
	cout << "sA equals: " << sA << ", sB equals: " << sB << endl;
	SwapScores(&sA, &sB);
	cout << "sA equals: " << sA << ", sB equals: " << sB << endl << endl;

	// Passing by reference - this has the advantage of not having to copy variable.
	int score2 = 0;
	CalculateScore(1554, 20, 52, score2);	// Passing by reference
	cout << "Your calculated score2 is " << score2 << endl;

	// Swapping by reference
	int s1 = 500;
	int s2 = 1000;
	cout << "Swap references:" << endl;
	cout << "s1 equals: " << s1 << ", s2 equals: " << s2 << endl;
	SwapScores(s1, s2);
	cout << "s1 equals: " << s1 << ", s2 equals: " << s2 << endl << endl;

	// Passing arrays
	int diceSides[6] = { 1, 2, 3, 4, 5, 6 };
	ShowDiceSides(diceSides, 6);
	cout << endl;

	// C-Style and C++ structures
	scoreItems scoreStruct;			
	scoreStruct.dots = 1554;
	scoreStruct.fruit = 20;
	scoreStruct.ghosts = 52;
	cout << "Your calculated score using a structure is " << ReturnScore(scoreStruct) << endl;

	// Inline functions
	cout << "Your inline calculated score using a structure is " << ReturnScoreInline(scoreStruct) << endl << endl;

	//Returning a pointer
	cout << "Returning pointer examples..." << endl;
	vector<string> myInventory;
	myInventory.push_back("Super Mushroom");
	myInventory.push_back("Fire Flower");
	myInventory.push_back("Super Leaf");
	cout << "Sending the object pointed to by returned pointer to cout: " << endl;
	cout << *(pointerToElement(&myInventory, 1)) << endl;
	cout << "Expensive assigment - copying: " << endl;
	string pItemCopy = *(pointerToElement(&myInventory, 0));
	cout << pItemCopy << endl;
	cout << "Inexpensive assigment - one pointer to another: " << endl;
	string* pItem = pointerToElement(&myInventory, 0);
	cout << *pItem << endl;
	cout << "Altering pointer: " << endl;
	*pItem = "Super Mushroom Power!";
	cout << myInventory[0] << endl;	// Note: See how myInventory changed.

	string* danglingPointer = badPointer();
	// Please uncomment the next paragraph to see some possible matrix grids from memory being overrun.
	//cout << "Careful, this dangling pointer will break your code at run time: " << *danglingPointer;

	return 0;
}

int CalculateScore(int dots, int fruit, int ghosts)
{
	return (dots * DOTSMULT) + (fruit * 500) + (ghosts * ghostMult);
}
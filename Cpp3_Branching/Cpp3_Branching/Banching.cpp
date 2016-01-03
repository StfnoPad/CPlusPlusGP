// Branching: Examples of branching and loops.
// V 1.0

/* Extra tasks:
   1) play and break the code
   2) change the lopps to disply more information
   3) find out what mt19937 does
   4) expand the guessing game
*/

#include <iostream>
#include <random>
using namespace std;

int main() 
{
	// Example of some if statements
	int MAX_SCORE = 3333360;
	long score = (663000 + 1220 + 540) + (2459600 + 5000) + (204000); // http://gaming.stackexchange.com/questions/185772/why-is-3333360-the-maximum-score-in-pac-man

	if (score == MAX_SCORE)
	{
		cout << "Congratulations, you have reached the maximum score at Pac-man!\n";
	}

	if (score)
	{
		cout << "Also, at least your score is not zero!\n";
	}

	score = -1;
	cout << endl << "What was the score from your last Pac-man game? ";
	cin >> score;

	if (score > MAX_SCORE)
	{
		cout << "I know you cheated in Pac-man!\n";
	}
	else if (score == MAX_SCORE)
	{
		cout << "Congratulations, you have reached the maximun score at Pac-man!\n";
	}
	else if (score >= 1000000) {
		cout << "Congratulations, that was impressive!\n";
	}
	else if (score >= 10000) {
		cout << "Not bad, but you need to play more!\n";
	}
	else if (score == -1) {
		cout << "Note: c++ cin only allows 32-bit numbers - your score was too high to fit.\n";
	}

	
	// Example of case statements
	int favoriteGhost;
	cout << endl << "The Original Pac-man had 4 ghost:\n";
	cout << " 1) The red one\n 2) The pink one\n 3) The Cyan one\n 4) The orange one\nPlease select the number of your favorite Pac-man ghost: ";
	cin >> favoriteGhost;

	switch (favoriteGhost)
	{
	case 1:
		cout << "You picked Blinky - the red ghost. In the original game they follow Pac-man.";
		break;
	case 2:
		cout << "You picked Pinky - the pink ghost. In the original game they position themselves in front of Pac-man.";
		break;
	case 3:
		cout << "You picked Inky - the cyan ghost. In the original game they have a fickle mood.";
		break;
	case 4:
		cout << "You picked Clyde - the orange ghost. In the original game they act stupid.";
		break;
	default:
		cout << "Looks like Pac-man picked you by default!";
	}
	cout << "\n\n";
	

	// Example for loops and random number using C++11 or newer.
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 6);
	cout << "Lets roll some dice:\n";
	for (int n = 0; n < 10; n++)
	{
		cout << dis(gen) << ' ';
	}
	cout << '\n';

	// Lets try to build a small game...
	uniform_int_distribution<> disGame(1, 100);
	int number = disGame(gen);
	int guess;

	cout << "\n\nSuper 'Guess My Number' game\n";
	cout << "I'm thinking of a number between 1 and 100. Can you guess it?\n";

	do
	{
		cout << "\nEnter a guess: ";
		cin >> guess;

		if (guess > number)
		{
			cout << "That is too high!\n";
		}
		else if (guess < number)
		{
			cout << "That is too low!\n";
		}
		else 
		{
			cout << "That is the right number - well done!\n";
		}
	} while (guess != number);

	return 0;


}
// Intro.cpp : Running our first c++ program
// V 1.0

/*
Extra tasks:
1) try to compile this small program as a console application.
2) play and break the code.
3) change the output to the console.
4) add a namespace to the include to avoid typing std:: all the time.
5) change this simple code with the main idea of a game.
*/

#include <iostream>

int main()
{
	std::cout << std::endl << "*Mario travels to the first castle and beats the boss*" << std::endl;

	char foundBowser = 'n';
	while (foundBowser != 'y')
	{
		std::cout << "Thank you Mario! But our princess is in another castle!" << std::endl;
		std::cout << std::endl << "*Mario travels to the next castle* " << std::endl << "Mario, did you beat Bowser in this castle? ";
		std::cin >> foundBowser;
	}

	std::cout << std::endl << "Thank you Mario! Your Quest is over.";

	return 0;
}


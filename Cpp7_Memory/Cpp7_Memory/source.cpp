// source: Examples of memory management (stack and heap)
// v1.0

/* Extra tasks:
1) play and break with the code.
2) Find out how much memoery you can allocate in the heap.
3) Try using another STL template - like lists or "hashmaps".
*/

#include <iostream>
#include <chrono>
#include <random>
using namespace std;

#include "worldNew.h"

int* intOnHeap(int number) {		// Allocate memory using a function
	int* pTemp = new int(number);
	return pTemp;
}

void leak1()
{
	int* temp = new int(100);		// Example of a memory leak
}

void leak2()						// Another example of memory leak
{
	int* temp = new int(100);
	temp = new int(200);
	delete temp;
}

int main(int argc, char* argv[])
{
	// Simple example of dynamically allocating memory
	int* pVariable = new int;		// notice the inclusion of the keyword new - this goes to heap memory.
	*pVariable = 100;
	cout << "Variable stored in heap : " << *pVariable << " with address: " << pVariable << endl;

	int* pVariable2 = intOnHeap(150);
	cout << "Variable stored in heap (function): " << *pVariable2 << " with address: " << pVariable2 << endl;

	cout << "Free memory pointer to by pVariable and pVariable2.\n";
	delete pVariable; 
	delete pVariable2;

	// Get rid of dangling pointers
	pVariable = 0; pVariable2 = 0;

	// Lets try allocating and assigning lots of variable to memory at the same time
	const int ROLLTIMES = 1234567;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1, 6);

	cout << "Rolling " << ROLLTIMES << " dices, allocating memory and storing the number from the roll...\n";
	auto t0 = chrono::high_resolution_clock::now(); // start measuring time
	vector<int*> rolls;
	for (int i = 0; i < ROLLTIMES; i++)
	{	
		rolls.push_back(new int(dis(gen)));
	}
	auto t1 = chrono::high_resolution_clock::now();
	chrono::milliseconds total_ms = chrono::duration_cast<chrono::milliseconds>(t1 - t0);
	cout << "Time spend initializing and allocating " << ROLLTIMES << " dice rolls: " << total_ms.count() << " miliseconds\n";

	cout << sizeof(int) * rolls.capacity();
	for (int i = 0; i < ROLLTIMES; i++)
	{
		delete rolls[i];	// deallocating memory 
		rolls[i] = 0;		// removing dangling pointers
	}


	// Now, lets try allocating memory in one go, then assigning the values to the allocated memory.
	cout << "Rolling " << ROLLTIMES << " dices, allocating memory at once then storing the number from the roll...\n";
	t0 = chrono::high_resolution_clock::now(); // start measuring time
	int* rollsFast = new int[ROLLTIMES];
	for (int i = 0; i < ROLLTIMES; i++)
	{
		rollsFast[i] = dis(gen);
	}
	t1 = chrono::high_resolution_clock::now();
	total_ms = chrono::duration_cast<chrono::milliseconds>(t1 - t0);
	cout << "Time spend allocating then storing " << ROLLTIMES << " dice rolls: " << total_ms.count() << " miliseconds\n";

	delete[] rollsFast;
	rollsFast = 0;

	// Example deconstructors
	cout << "\nCreating 10000 worlds..." << endl;
	t0 = chrono::high_resolution_clock::now(); // start measuring time
	World* worldsArray = new World[10000];		// Create a bunch of worlds in memory
	t1 = chrono::high_resolution_clock::now();
	total_ms = chrono::duration_cast<chrono::milliseconds>(t1 - t0);
	cout << "Time spend creating 10000 worlds: " << total_ms.count() << " miliseconds\n";
	
	t0 = chrono::high_resolution_clock::now(); // start measuring time
	delete[] worldsArray;						// delete all
	worldsArray = 0;
	t1 = chrono::high_resolution_clock::now();
	total_ms = chrono::duration_cast<chrono::milliseconds>(t1 - t0);
	cout << "Time destroying all the worlds: " << total_ms.count() << " miliseconds\n";

	// Example of copying classes with heap memory allocations
	World w1; World w2; World w3; 
	cout << endl;
	cout << "World1 name: " << *(w1.name) << " with address for name: " << w1.name << endl;
	cout << "World2 name: " << *(w2.name) << " with address for name: " << w2.name << endl;
	cout << "World3 name: " << *(w3.name) << " with address for name: " << w3.name << endl;
	
	w2 = w3;
	cout << "\nW2 = W3\n";
	cout << "World1 name: " << *(w1.name) << " with address for name: " << w1.name << endl;
	cout << "World2 name: " << *(w2.name) << " with address for name: " << w2.name << endl;
	cout << "World3 name: " << *(w3.name) << " with address for name: " << w3.name << endl;


	// Memory leaks example 1
	for (int i = 0; i < ROLLTIMES; i++) {
		leak1();	// Please check memory snapshot
	}

	// Memory leaks example 2
	for (int i = 0; i < ROLLTIMES; i++) {
		leak2();	// Please check memory snapshot
	}
	
	return 0;



}




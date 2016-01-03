#pragma once

#include <iostream>
#include <vector>
using namespace std;

#include "world.h"


class Universe
{
public: 
	
	void Add(const World& aWorld);
	friend ostream& operator<<(ostream& os, const Universe& aUniverse);

private:
	vector<World> worlds;	

};
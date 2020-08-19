#pragma once
#include "Header.h"
#include "Coordinates.h"
using namespace std;

class CParser
{
private:
	vector<CCoordinates> barrenLand;
	string input;
	void parseInput();
	vector<CCoordinates> getBarrenArea() { return barrenLand; }
	void enterValues();
public:
	vector<CCoordinates> getBarrenAreaFromUser(string inputRect) 
	{ 
		input = inputRect;
		parseInput();
		return getBarrenArea();
	}

	vector<CCoordinates> getBarrenAreaFromUser()
	{
		enterValues();
		parseInput();
		return getBarrenArea();
	}
};

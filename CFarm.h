#pragma once
#include "Constants.h"
#include "Coordinates.h"
#include "Parser.h"

class CFarm
{
private:
	vector<vector<int>> entireLand;
	map<int, int> fertileAreas;
	queue<pair<int, int>> fertileLand;
	vector<int> fertileLandSize;
	void setBarren(vector<CCoordinates> coordinates);
	void addQueue(int row, int col);
	void BFSFertileLand();
	void CalculateFertileArea();
	void printFertileArea();
public:
	CFarm();	
	void showBarrenLand();
	void runTestSuite1();
	void runTestSuite2();
};


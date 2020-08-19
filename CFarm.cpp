#include "CFarm.h"
#include "Timer.h"

CFarm::CFarm()
{
	for (int index = 0; index < ROW; index++)
	{
		vector<int> vecRow(COL, 0);
		entireLand.push_back(vecRow);
	}
}

void CFarm::setBarren(vector<CCoordinates> coordinates)
{
	for (auto iter = coordinates.begin(); iter != coordinates.end(); iter++)
	{
		for (int row = iter->getTop(); row <= iter->getBottom(); row++)
		{
			for (int col = iter->getLeft(); col <= iter->getRight(); col++)
			{
				entireLand[row][col] = 1;
			}
		}
	}
}

void CFarm::addQueue(int row, int col)
{
	if (entireLand[row][col] == 0)
	{
		fertileLand.push({ row ,col });
	}
}

void CFarm::BFSFertileLand()
{
	CTimer calculate;
	int count = 1;
	int currentRow = 0;
	int currentColumn = 0;

	while (currentRow < ROW && currentColumn < COL)
	{
		if (fertileLand.empty())
		{
			if (entireLand[currentRow][currentColumn] == 0)
			{
				count++;
				fertileAreas[count] = 0;
				fertileLand.push({ currentRow, currentColumn });
			}

			if (currentRow == (ROW - 1))
			{
				currentRow = 0;
				currentColumn++;
			}
			else
				currentRow++;
		}

		while (!fertileLand.empty())
		{
			pair<int, int> item = fertileLand.front();
			fertileLand.pop();

			int row = item.first;
			int col = item.second;

			if (entireLand[row][col] == 0) 
			{
				if (row > 0)
					addQueue(row - 1, col);
				if (row < (ROW - 1))
					addQueue(row + 1, col);
				if (col > 0)
					addQueue(row, col - 1);
				if (col < (COL - 1))
					addQueue(row, col + 1);

				entireLand[row][col] = count;
				fertileAreas[count]++;
			}
		}
	}
	CalculateFertileArea();
}

void CFarm::CalculateFertileArea() 
{
	int index = 0;
	for (auto iter : fertileAreas) 
	{
		fertileLandSize.push_back(iter.second);
	}

	sort(fertileLandSize.begin(), fertileLandSize.end());
}

void CFarm::printFertileArea()
{
	cout << "Size of fertile Lands are as below " << endl;
	for (auto iter : fertileLandSize)
	{
		cout << iter << endl;
	}
}

void CFarm::showBarrenLand()
{
	CParser parser;
	setBarren(parser.getBarrenAreaFromUser());
	BFSFertileLand();
	printFertileArea();
}

void CFarm::runTestSuite1()
{
	CParser parser;
	setBarren(parser.getBarrenAreaFromUser("0 292 399 307"));
	BFSFertileLand();

	assert(fertileLandSize.size() == 2 && "Output of Fertile land returned is wrong");
	assert(fertileLandSize[0] == 116800 && "Size of Fertile Land1 returned should be 116800");
	assert(fertileLandSize[1] == 116800 && "Size of Fertile Land2 returned should be 116800");
	cout << "Test case1 passed";
}

void CFarm::runTestSuite2()
{
	CParser parser;
	setBarren(parser.getBarrenAreaFromUser("48 192 351 207 , 48 392 351 407 , 120 52 135 547 , 260 52 275 547"));
	BFSFertileLand();

	assert(fertileLandSize.size() == 2 && "Output of Fertile land returned is wrong");
	assert(fertileLandSize[0] == 22816 && "Size of Fertile Land1 returned should be 22816");
	assert(fertileLandSize[1] == 192608 && "Size of Fertile Land2 returned should be 192608");

	cout << "Test case2 passed";
}
#pragma once
#include "Parser.h"

void CParser::parseInput()
{
	string remove = "{}(),.'\"";
	int nsize = int(remove.length());
	for (int nIndex = 0; nIndex < nsize; nIndex++)
	{
		replace(input.begin(), input.end(), remove[nIndex], ' ');
	}

	istringstream iss(input);
	vector<std::string> results(istream_iterator<string>{iss}, istream_iterator<std::string>());

	if (results.size() % 4 != 0)
	{
		cout << "Number of arguments provided =" << results.size() << endl;
		cout << "Number of arguments should be divisible by 4 " << endl;
		cout << "Existing the app";
		exit(1);
	}

	try
	{
		int nSize = int(results.size());
		for (int nIndex = 0; nIndex < nSize; nIndex += 4)
		{
			int left = stoi(results[nIndex + 1]);
			int right = stoi(results[nIndex + 3]);
			int top = stoi(results[0 + nIndex]);
			int bottom = stoi(results[2 + nIndex]);
			CCoordinates temp(bottom, left, top, right);
			temp.validate();
			barrenLand.push_back(temp);
		}
		input = "";
	}
	catch (const exception &e)
	{
		cout << endl << "Invalid coordinates entered ";
	    cout << e.what();
		cout << endl << "Exiting the program";
		exit(1);
	}
}

void CParser::enterValues()
{
	cout << "Entire land is of size : " << ROW << " X " << COL << endl;
	cout << "Please enter the co-ordinates of Barren land separated by space or comma :  ";
	getline(cin, input);
}


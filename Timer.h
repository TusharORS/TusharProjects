#pragma once
#include <chrono>
#include <iostream>
using namespace std::chrono;

class CTimer
{
private:
	std::chrono::steady_clock::time_point start;
public:
	CTimer()
	{
		start = high_resolution_clock::now();
	}
	~CTimer()
	{
		auto end = high_resolution_clock::now();
		auto duration = duration_cast<milliseconds>(end - start);
		auto secs = duration_cast<seconds>(end - start);
		std::cout << "Calulating Barren Land took : " << duration.count() << " MiliSecs" << endl;
	}
};
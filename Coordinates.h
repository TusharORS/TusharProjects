#pragma once
#include "Constants.h"
#include <cassert>

class CCoordinates
{
	int left, top, right, bottom;
public:
	int getLeft()
	{
		return left;
	}

	int getRight()
	{
		return right;
	}

	int getTop()
	{
		return top;
	}

	int getBottom()
	{
		return bottom;
	}

	CCoordinates(int bottom, int left, int top, int right)
	{
		this->bottom = bottom;
		this->left = left;
		this->top = top;
		this->right = right;
		validate();
	}

	void validate()
	{
		assert(between(top, 0, ROW) && "Top coordinate is wrong");
		assert(between(bottom, top, ROW) && "Bottom coordinate is wrong");
		assert(between(left, 0, COL) && "Left coordinate is wrong");
		assert(between(right, left, COL) && "Right coordinate is wrong");
	}

	bool between(int value, int low, int high)
	{
		return value >= low && value <= high;
	}
};

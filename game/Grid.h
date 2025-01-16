#pragma once
#include <vector>
#include "raylib.h"


class Grid
{
public:
	static const int rows =20;
	Grid();
	void Initialize();
	void Print();
	int grid[rows][10];
	void Draw();

private:

	int numRows;
	int numCols;
	int cellSize;
	std::vector<Color> colours;

};


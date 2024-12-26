#pragma once
#include <vector>
#include "raylib.h"


class Grid
{
public:
	Grid();
	void Initialize();
	void Print();
	int grid[20][10];
	void Draw();
private:

	std::vector<Color> GetCellColours();
	int numRows;
	int numCols;
	int cellSize;
	std::vector<Color> colours;

};


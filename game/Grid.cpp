#include "Grid.h"
#include <iostream>
#include "colour.h"

//const int Grid::rows = 10;
//int Grid::colmuns = 10;
Grid::Grid()
{
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	Initialize();
	colours = GetCellColours();
}

void Grid::Initialize()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int colmn = 0; colmn < numCols; colmn++)
		{
			grid[row][colmn] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int colmn = 0; colmn < numCols; colmn++)
		{
			std::cout << grid[row][colmn] << " ";
		}
		std::cout << std::endl;
	}
}


void Grid::Draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int colmn = 0; colmn < numCols; colmn++)
		{
			int cellValue = grid[row][colmn];
			DrawRectangle(colmn * cellSize + 1 , row * cellSize + 1, cellSize - 1, cellSize - 1, colours[cellValue]);
		}
	}
}

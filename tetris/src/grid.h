#pragma once
#include "vector.h"
#include "raylib.h"

class Grid
{
public:
    Grid(int cols);
    Grid();
    void Initialize();
    void Print();
    void Draw();
    bool IsCellOutside(int row, int column);
    bool IsCellEmpty(int row, int column);
    int ClearFullRows();
    int **grid;

private:
    bool IsRowFull(int row);
    void ClearRow(int row);
    void MoveRowDown(int row, int numRows);
    int numRows;
    int numCols;
    int cellSize;
    vectorClass<Color> colors;
};
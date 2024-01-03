#include "grid.h"
#include <iostream>
#include "colors.h"

Grid::Grid()
{
    // Varsayılan değerler
    numRows = 20; // Varsayılan satır sayısı
    numCols = 10; // Varsayılan sütun sayısı
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}


Grid::Grid(int cols)
{
    numCols = cols;
    numRows = 20;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize()
{
    // İki boyutlu dizi için bellekte yer ayırma
        grid = new int*[numRows];
        for (int row = 0; row < numRows; row++)
        {
            grid[row] = new int[numCols];

            // Her hücreyi 0 ile doldurma
            for (int column = 0; column < numCols; column++)
            {
                grid[row][column] = 0;
            }
        }
}

void Grid::Print()
{
    for (int row = 0; row < numRows; row++)
    {
        for (int column = 0; column < numCols; column++)
        {
            std::cout << grid[row][column] << " ";
        }
        std::cout << std::endl;
    }
}

void Grid::Draw()
{
    for (int row = 0; row < numRows; row++)
    {
        //std::cout << "drawing xxxxxxx" << std::endl;
        for (int column = 0; column < numCols; column++)
        {
            //std::cout << "drawing" << std::endl;
            int cellValue = grid[row][column];
            DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors.get(cellValue));
        }
    }
}

bool Grid::IsCellOutside(int row, int column)
{
    if (row >= 0 && row < numRows && column >= 0 && column < numCols)
    {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int column)
{
    if (grid[row][column] == 0)
    {
        return true;
    }
    return false;
}

int Grid::ClearFullRows()
{
    int completed = 0;
    for (int row = numRows - 1; row >= 0; row--)
    {
        if (IsRowFull(row))
        {
            ClearRow(row);
            completed++;
        }
        else if (completed > 0)
        {
            MoveRowDown(row, completed);
        }
    }
    return completed;
}

bool Grid::IsRowFull(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        if (grid[row][column] == 0)
        {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row][column] = 0;
    }
}

void Grid::MoveRowDown(int row, int numRows)
{
    for (int column = 0; column < numCols; column++)
    {
        grid[row + numRows][column] = grid[row][column];
        grid[row][column] = 0;
    }
}

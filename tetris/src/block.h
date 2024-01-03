#pragma once
#include <map>
#include "position.h"
#include "colors.h"
#include "vector.h"

class Block
{
public:
    Block();
    void Draw(int offsetX, int offsetY);
    void Move(int rows, int columns);
    vectorClass<Position> GetCellPositions();
    void Rotate();
    void UndoRotation();
    int id;
    std::map<int, vectorClass<Position>> cells;
    int rowOffset;
    int columnOffset;

private:
    int cellSize;
    int rotationState;
    vectorClass<Color> colors;

};
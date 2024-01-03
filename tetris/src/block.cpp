#include "block.h"
#include "vector.h"

Block::Block()
{
    cellSize = 30;
    rotationState = 0;
    colors = GetCellColors();
    rowOffset = 0;
    columnOffset = 0;
}

void Block::Draw(int offsetX, int offsetY)
{
    vectorClass<Position> tiles = GetCellPositions();
    for(int i = 0; i < tiles.getcapacity(); i++){
        DrawRectangle(tiles.get(i).column * cellSize + offsetX, tiles.get(i).row * cellSize + offsetY, cellSize - 1, cellSize - 1, colors.get(id));
    }
}

void Block::Move(int rows, int columns)
{
    rowOffset += rows;
    columnOffset += columns;
}

vectorClass<Position> Block::GetCellPositions()
{
    vectorClass<Position> tiles = cells[rotationState];
    vectorClass<Position> movedTiles;

    for(int i = 0; i < tiles.getcapacity(); i++){
        Position newPos = Position(tiles.get(i).row + rowOffset, tiles.get(i).column + columnOffset);
        movedTiles.push(newPos);
    }
    return movedTiles;
}

void Block::Rotate()
{
    rotationState++;
    if (rotationState == (int)cells.size())
    {
        rotationState = 0;
    }
}

void Block::UndoRotation()
{
    rotationState--;
    if (rotationState == -1)
    {
        rotationState = cells.size() - 1;
    }
}

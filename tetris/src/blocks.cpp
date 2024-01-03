#include "block.h"
#include "position.h"

class LBlock : public Block
{
public:
    LBlock()
    {
        id = 1;
        vectorClass<Position> cells0;
        cells0.push(Position(0, 2));
        cells0.push(Position(1, 0));
        cells0.push(Position(1, 1));
        cells0.push(Position(1, 2));
        cells[0] = cells0;

        vectorClass<Position> cells1;
        cells1.push(Position(0, 1));
        cells1.push(Position(1, 1));
        cells1.push(Position(2, 1));
        cells1.push(Position(2, 2));
        cells[1] = cells1;
        
        vectorClass<Position> cells2;
        cells2.push(Position(1, 0));
        cells2.push(Position(1, 1));
        cells2.push(Position(1, 2));
        cells2.push(Position(2, 0));
        cells[2] = cells2;

        vectorClass<Position> cells3;
        cells3.push(Position(0, 0));
        cells3.push(Position(0, 1));
        cells3.push(Position(1, 1));
        cells3.push(Position(2, 1));
        cells[3] = cells3;

        Move(0, 3);
    }
};

class JBlock : public Block
{
public:
    JBlock()
    {
        id = 2;

        vectorClass<Position> cells0;
        cells0.push(Position(0, 0));
        cells0.push(Position(1, 0));
        cells0.push(Position(1, 1));
        cells0.push(Position(1, 2));
        cells[0] = cells0;

        vectorClass<Position> cells1;
        cells1.push(Position(0, 1));
        cells1.push(Position(0, 2));
        cells1.push(Position(1, 1));
        cells1.push(Position(2, 1));
        cells[1] = cells1;

        vectorClass<Position> cells2;
        cells2.push(Position(1, 0));
        cells2.push(Position(1, 1));
        cells2.push(Position(1, 2));
        cells2.push(Position(2, 2));
        cells[2] = cells2;

        vectorClass<Position> cells3;
        cells3.push(Position(0, 1));
        cells3.push(Position(1, 1));
        cells3.push(Position(2, 0));
        cells3.push(Position(2, 1));
        cells[3] = cells3;

        Move(0, 3);
    }
};

class IBlock : public Block
{
public:
    IBlock()
    {
        id = 3;

        vectorClass<Position> cells0;
        cells0.push(Position(1, 0));
        cells0.push(Position(1, 1));
        cells0.push(Position(1, 2));
        cells0.push(Position(1, 3));
        cells[0] = cells0;


        vectorClass<Position> cells1;
        cells1.push(Position(0, 2));
        cells1.push(Position(1, 2));
        cells1.push(Position(2, 2));
        cells1.push(Position(3, 2));
        cells[1] = cells1;

        vectorClass<Position> cells2;
        cells2.push(Position(2, 0));
        cells2.push(Position(2, 1));
        cells2.push(Position(2, 2));
        cells2.push(Position(2, 3));
        cells[2] = cells2;

        vectorClass<Position> cells3;
        cells3.push(Position(0, 1));
        cells3.push(Position(1, 1));
        cells3.push(Position(2, 1));
        cells3.push(Position(3, 1));
        cells[3] = cells3;

        Move(-1, 3);
    }
};

class OBlock : public Block
{
public:
    OBlock()
    {
        id = 4;

        vectorClass<Position> cells0;
        cells0.push(Position(0, 0));
        cells0.push(Position(0, 1));
        cells0.push(Position(1, 0));
        cells0.push(Position(1, 1));
        cells[0] = cells0;

        Move(0, 4);
    }
};

class SBlock : public Block
{
public:
    SBlock()
    {
        id = 5;

        vectorClass<Position> cells0;
        cells0.push(Position(0, 1));
        cells0.push(Position(0, 2));
        cells0.push(Position(1, 0));
        cells0.push(Position(1, 1));
        cells[0] = cells0;

        vectorClass<Position> cells1;
        cells1.push(Position(0, 1));
        cells1.push(Position(1, 1));
        cells1.push(Position(1, 2));
        cells1.push(Position(2, 2));
        cells[1] = cells1;

        vectorClass<Position> cells2;
        cells2.push(Position(1, 1));
        cells2.push(Position(1, 2));
        cells2.push(Position(2, 0));
        cells2.push(Position(2, 1));
        cells[2] = cells2;

        vectorClass<Position> cells3;
        cells3.push(Position(0, 0));
        cells3.push(Position(1, 0));
        cells3.push(Position(1, 1));
        cells3.push(Position(2, 1));
        cells[3] = cells3;

        Move(0, 3);
    }
};

class TBlock : public Block
{
public:
    TBlock()
    {
        id = 6;

        vectorClass<Position> cells0;
        cells0.push(Position(0, 1));
        cells0.push(Position(1, 0));
        cells0.push(Position(1, 1));
        cells0.push(Position(1, 2));
        cells[0] = cells0;
    
        vectorClass<Position> cells1;
        cells1.push(Position(0, 1));
        cells1.push(Position(1, 1));
        cells1.push(Position(1, 2));
        cells1.push(Position(2, 1));
        cells[1] = cells1;

        vectorClass<Position> cells2;
        cells2.push(Position(1, 0));
        cells2.push(Position(1, 1));
        cells2.push(Position(1, 2));
        cells2.push(Position(2, 1));
        cells[2] = cells2;

        vectorClass<Position> cells3;
        cells3.push(Position(0, 1));
        cells3.push(Position(1, 0));
        cells3.push(Position(1, 1));
        cells3.push(Position(2, 1));
        cells[3] = cells3;

        Move(0, 3);
    }
};

class ZBlock : public Block
{
public:
    ZBlock()
    {
        id = 7;

        vectorClass<Position> cells0;
        cells0.push(Position(0, 0));
        cells0.push(Position(0, 1));
        cells0.push(Position(1, 1));
        cells0.push(Position(1, 2));
        cells[0] = cells0;
    
        vectorClass<Position> cells1;
        cells1.push(Position(0, 2));
        cells1.push(Position(1, 1));
        cells1.push(Position(1, 2));
        cells1.push(Position(2, 1));
        cells[1] = cells1;

        vectorClass<Position> cells2;
        cells2.push(Position(1, 0));
        cells2.push(Position(1, 1));
        cells2.push(Position(2, 1));
        cells2.push(Position(2, 2));
        cells[2] = cells2;

        vectorClass<Position> cells3;
        cells3.push(Position(0, 1));
        cells3.push(Position(1, 0));
        cells3.push(Position(1, 1));
        cells3.push(Position(2, 0));
        cells[3] = cells3;

        Move(0, 3);
    }
};
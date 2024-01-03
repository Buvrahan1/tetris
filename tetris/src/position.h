#pragma once
#ifndef POSITION_H
#define POSITION_H

class Position {
public:
    int row;
    int column;

    Position(); 
    Position(int row, int column);
};

#endif  // POSITION_H
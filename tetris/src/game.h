#pragma once
#include "grid.h"
#include "blocks.cpp"
#include "vector.h"


class Game
{
public:
    Game(int setRow = 10);
    ~Game();
    void Draw();
    void HandleInput();
    void MoveBlockDown();
    bool gameOver;
    int score;
    float gameSpeed;
    Music music;
    int rotateLeft;
    int rotateLeftInit;
    float setSpeed;
    void setGameSpeed();
    void ManagePortal();
    int initPortal;
    Image portalImage;
    Texture2D portalTexture;
    int setRow;
    void setColumn(int column);
    Block nextBlock;
    Block swappedBlock;
    int isSwapped;

private:

    void MoveBlockLeft();
    void MoveBlockRight();
    Block GetRandomBlock();
    vectorClass<Block> GetAllBlocks();
    bool IsBlockOutside();
    void RotateBlock();
    void LockBlock();
    bool BlockFits();
    void Reset();
    void UpdateScore(int linesCleared, int moveDownPoints);
    void SwapBlocks();
    Grid grid;
    vectorClass<Block> blocks;
    Block currentBlock;
    Sound rotateSound;
    Sound clearSound;
    bool isPortalActive;
    int portalPositionX;
    int tempPortalScore;
    int counter;
};
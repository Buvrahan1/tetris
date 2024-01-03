#include "game.h"
#include <random>
#include "vector.h"
Game::Game(int setRow)
{
    grid = Grid(setRow);
    std::cout << "setRow = " << setRow << std::endl;
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    gameOver = false;
    score = 0;
    gameSpeed = 0.2;
    InitAudioDevice();
    music = LoadMusicStream("Sounds/music.mp3");
    PlayMusicStream(music);
    rotateSound = LoadSound("Sounds/rotate.mp3");
    clearSound = LoadSound("Sounds/clear.mp3"); 
    rotateLeft = rotateLeftInit;
    isSwapped = false;
    isPortalActive = false;
    initPortal = 0;
    counter = 0;
}

Game::~Game()
{
    UnloadSound(rotateSound);
    UnloadSound(clearSound);
    UnloadMusicStream(music);
    CloseAudioDevice();
}


Block Game::GetRandomBlock()
{
    static int index;
    if (blocks.empty())
    {
        blocks = GetAllBlocks();
    }
    int randomIndex = rand() % blocks.size();
    while (index == randomIndex)
    {
        randomIndex = rand() % blocks.size();
    }
    index = randomIndex;
    Block block = blocks.get(randomIndex);
    return block;
}

vectorClass<Block> Game::GetAllBlocks()
{
    vectorClass<Block> Blocks;
    Blocks.push(IBlock());
    Blocks.push(JBlock());
    Blocks.push(LBlock());
    Blocks.push(OBlock());
    Blocks.push(SBlock());
    Blocks.push(TBlock());
    Blocks.push(ZBlock());

    return Blocks;
}

void Game::Draw()
{
    grid.Draw();
    std::cout << "setRow DRAW = " << this->setRow << std::endl;
    currentBlock.Draw(11, 11);
    switch (nextBlock.id)
    {
    case 3:
        nextBlock.Draw((static_cast<float>(255 + (30 * (setRow - 10)))), 290);
        break;
    case 4:
        nextBlock.Draw((static_cast<float>(255 + (30 * (setRow - 10)))), 280);
        break;
    default:
        nextBlock.Draw((static_cast<float>(270 + (30 * (setRow - 10)))), 270);
        break;
    }

    if(isSwapped){
    switch (swappedBlock.id)
    {
    case 3:
        swappedBlock.Draw((static_cast<float>(345 + (30 * (setRow - 10)))), 490);
        break;
    case 4:
        swappedBlock.Draw((static_cast<float>(375 + (30 * (setRow - 10)))), 505);
        break;
    default:
        swappedBlock.Draw((static_cast<float>(360 + (30 * (setRow - 10)))), 495);
        break;
    }        
    }



}

void Game::HandleInput()
{
    int keyPressed = GetKeyPressed();
    if (gameOver && keyPressed != 0)
    {
        gameOver = false;
        Reset();
    }
    switch (keyPressed)
    {
    case KEY_LEFT:
        MoveBlockLeft();
        break;
    case KEY_RIGHT:
        MoveBlockRight();
        break;
    case KEY_DOWN:
        MoveBlockDown();
        UpdateScore(0, 1);
        setGameSpeed();
        break;
    case KEY_UP:
        if(rotateLeft > 0){
            RotateBlock();
            rotateLeft --;
        }
        break;
    case KEY_ENTER: 
        SwapBlocks();
        break;
    }
}

void Game::MoveBlockLeft()
{
    if (!gameOver)
    {
        currentBlock.Move(0, -1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, 1);
        }
    }
}

void Game::MoveBlockRight()
{
    if (!gameOver)
    {
        currentBlock.Move(0, 1);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(0, -1);
        }
    }
}

void Game::MoveBlockDown()
{
    if (!gameOver)
    {
        currentBlock.Move(1, 0);
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.Move(-1, 0);
            LockBlock();
            rotateLeft = rotateLeftInit;
        }
    }
}

bool Game::IsBlockOutside()
{
    vectorClass<Position> tiles = currentBlock.GetCellPositions();

    for(int i = 0; i < tiles.getcapacity(); i++){
        if(grid.IsCellOutside(tiles.get(i).row, tiles.get(i).column)){
            return true;
        }
    }
    return false;
}   

void Game::RotateBlock()
{
    if (!gameOver)
    {
        currentBlock.Rotate();
        if (IsBlockOutside() || BlockFits() == false)
        {
            currentBlock.UndoRotation();
        }
        else
        {
            PlaySound(rotateSound);
        }
    }
}

void Game::LockBlock()
{
    vectorClass<Position> tiles = currentBlock.GetCellPositions();


    for (int i = 0; i < tiles.getcapacity(); i++)
    {
        grid.grid[tiles.get(i).row][tiles.get(i).column] = currentBlock.id;
    }
    currentBlock = nextBlock;
    if (BlockFits() == false)
    {
        gameOver = true;
    }
    nextBlock = GetRandomBlock();
    int rowsCleared = grid.ClearFullRows();
    if (rowsCleared > 0)
    {
        PlaySound(clearSound);
        UpdateScore(rowsCleared, 0);
        setGameSpeed();
    }
}

bool Game::BlockFits()
{
    vectorClass<Position> tiles = currentBlock.GetCellPositions();
    for (int i = 0; i < tiles.getcapacity(); i++)
    {
        if (grid.IsCellEmpty(tiles.get(i).row, tiles.get(i).column) == false)
        {
            return false;
        }
    }
    return true;
}

void Game::Reset()
{
    grid.Initialize();
    blocks = GetAllBlocks();
    currentBlock = GetRandomBlock();
    nextBlock = GetRandomBlock();
    score = 0;
    gameSpeed = 0.2;
    initPortal = 0;
    isPortalActive = false;
    counter = 0;
}

void Game::UpdateScore(int linesCleared, int moveDownPoints)
{
    switch (linesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }

    score += moveDownPoints;
}

void Game::SwapBlocks()
{
    if (!gameOver)
    {
        int tempRow = currentBlock.rowOffset;
        int tempColumn = currentBlock.columnOffset;
        if(!isSwapped){
        swappedBlock = currentBlock;
        currentBlock = nextBlock;
        nextBlock = GetRandomBlock();
        isSwapped = true;
        }
        else{
            Block tempBlock = currentBlock;
            currentBlock = swappedBlock;
            swappedBlock = tempBlock;
            
        }
        currentBlock.rowOffset = tempRow;
        currentBlock.columnOffset = tempColumn;
        swappedBlock.rowOffset = 0;
        swappedBlock.columnOffset = 0;
        if (IsBlockOutside() || BlockFits() == false)
        {
            SwapBlocks();
        }
    }
}



void Game::setGameSpeed(){

    gameSpeed = (2 + (3-setSpeed)*0.25)/10;

    if(score > 300){
        gameSpeed -= 0.15;
    }
    else if(score > 200){
        gameSpeed -= 0.1;
    }
    else if(score > 100){
        gameSpeed -= 0.05;
    }
}


void Game::ManagePortal() {

    if (static_cast<int>((score) / 200) - initPortal > 0 && !isPortalActive) {
        portalPositionX = GetRandomValue(0, 8);
        isPortalActive = true;
        tempPortalScore = score;
        if(counter > 2){
            isPortalActive = false;
        }
    }

    if (isPortalActive) {
        if(!grid.IsCellEmpty(6, portalPositionX) || !grid.IsCellEmpty(6, portalPositionX+1)){
            portalPositionX = GetRandomValue(0, 8);
            counter++;
        }

        DrawTexture(portalTexture, 10+portalPositionX*30, 190, WHITE);
        
        vectorClass<Position> tiles = currentBlock.GetCellPositions();
        for(int i = 0; i < tiles.getcapacity(); i++){
            if(((tiles.get(i).row == 6) && (tiles.get(i).column == portalPositionX)) || (tiles.get(i).row == 6 && tiles.get(i).column == portalPositionX + 1)){
                for(int i = 0; i < 14; i++){
                    currentBlock.Move(1,0);
                    if (IsBlockOutside() || BlockFits() == false)
                    {
                    currentBlock.Move(-1, 0);
                    }
            }
        }
        
        if(score - tempPortalScore > 50){
            initPortal = static_cast<int>((score) / 200);
            isPortalActive = false;
        }
        if(counter > 5){
            isPortalActive = false;
        }
    }
}
}

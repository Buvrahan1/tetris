
#include "pages.h"
#include "utils.h"
#include <iostream>

const int screenWidth = 500;
const int screenHeight = 620;

const char *fullName = "Metehan KARABOGA";
const char *number = "20210702083";




Color themeColor1 = {97, 118, 75, 255};
Color themeColor2 = {250, 214, 165, 255};
Color yellowButton = { 255, 255, 0, 255 };
Color themeColor2Hover = {250, 214, 165, 160};
Color textColor = WHITE;
Image portalImage = LoadImage("img/greenPortal1.png");
int rotationChance = 10;
int gameSpeedSettings = 1;
bool isPaused = false;
double lastUpdateTime = 0;
int setRow = 10;

Vector2 portalPosition = {0, 0};


bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


void playGame()
{
    SetWindowSize((200 + (setRow * 30)), 620);
    SetTargetFPS(60);
    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);
    std::cout << "setRowGame = " << setRow << std::endl;
    Game game = Game(setRow);
    game.setRow = setRow;
    game.portalImage = portalImage;
    game.portalTexture = LoadTextureFromImage(game.portalImage);
    game.rotateLeftInit = rotationChance;
    game.setSpeed = gameSpeedSettings;
    game.setGameSpeed();
    game.rotateLeft = game.rotateLeftInit;
    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);

        if(IsKeyPressed(KEY_SPACE)){
            isPaused = !isPaused;
        }

        if(!isPaused){
            game.HandleInput();

            if (EventTriggered(game.gameSpeed)){
            game.MoveBlockDown();
            }
        }

        BeginDrawing();
        ClearBackground(themeColor1);

        DrawTextEx(font, "Score", {(static_cast<float>(365 + (30 * (setRow - 10)))), 15}, 38, 2, textColor);
        DrawTextEx(font, "Rotation", {(static_cast<float>(328 + (30 * (setRow - 10)))), 95}, 38, 2, textColor);
        DrawTextEx(font, "Next", {(static_cast<float>(370 + (30 * (setRow - 10)))), 175}, 38, 2, textColor);
        DrawTextEx(font, "Hold", {(static_cast<float>(370 + (30 * (setRow - 10)))), 400}, 38, 2, textColor);
        

    
        DrawRectangleRounded({static_cast<float>(320 + (30 * (setRow - 10))), 55.0f, 170.0f, 40.0f}, 0.3f, 6, themeColor2);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);
        DrawTextEx(font, scoreText, {(static_cast<float>(320 + (30 * (setRow - 10)))) + (170 - textSize.x) / 2, 52}, 38, 2, textColor);
        
        DrawRectangleRounded({(static_cast<float>(320 + (30 * (setRow - 10)))), 135, 170, 40}, 0.3, 6, themeColor2);
        char leftText[10];
        sprintf(leftText, "%d", game.rotateLeft);
        Vector2 leftSize = MeasureTextEx(font, leftText, 38, 2);
        DrawTextEx(font, leftText, {(static_cast<float>(320 + (30 * (setRow - 10)))) + (170 - leftSize.x) / 2 , 135}, 38, 2, textColor);


        DrawRectangleRounded({(static_cast<float>(320 + (30 * (setRow - 10)))), 215, 170, 180}, 0.3, 6, themeColor2);
        DrawRectangleRounded({(static_cast<float>(320 + (30 * (setRow - 10)))), 440, 170, 180}, 0.3, 6, themeColor2);
        
        game.Draw();
             std::cout << "nextblock = " << game.nextBlock.id << std::endl;
    
        if(isPaused){
            DrawRectangle(0, 0, screenWidth, screenHeight, Fade(WHITE, 0.5f));
            DrawText("PAUSED!", screenWidth/2 - MeasureText("PAUSED!", 40)/2, screenHeight/2-20, 40, BLACK);
            DrawText("Press ESC to Menu", screenWidth/2 - MeasureText("Press ESC to Menu", 40)/2, screenHeight/2+20, 40, BLACK);
        }
        
        game.ManagePortal();

        if (game.gameOver)
        {
            DrawRectangle(0, 0, screenWidth, screenHeight, Fade(WHITE, 0.8f));
            DrawText("GAME OVER!", screenWidth/2 - MeasureText("GAME OVER!", 60)/2, screenHeight/2-60, 60, RED);
            DrawText("Press any key to restart", screenWidth/2 - MeasureText("Press any key to restart", 30)/2, screenHeight/2+20, 30, RED);
            DrawText("Press ESC to Menu", screenWidth/2 - MeasureText("Press ESC to Menu", 30)/2, screenHeight/2+60, 30, RED);

        }

        EndDrawing();
    }
    UnloadFont(font);
}


void settings(){
    


    Font font = LoadFontEx("Font/monogram.ttf", 64, 0, 0);

    Rectangle greenButton =  {static_cast<float>(10), static_cast<float>(150), 60, 60};
    Rectangle redButton =  {static_cast<float>(150), static_cast<float>(150), 60, 60};
    Rectangle blueButton =  {static_cast<float>(290), static_cast<float>(150), 60, 60};
    Rectangle purpleButton =  {static_cast<float>(430), static_cast<float>(150), 60, 60};


    Rectangle easyButton=  {static_cast<float>(10), static_cast<float>(310), 140, 60};
    Color easyColor = themeColor2;
    Rectangle mediumButton =  {static_cast<float>(175), static_cast<float>(310), 140, 60};
    Color mediumColor = themeColor2;
    Rectangle hardButton =  {static_cast<float>(340), static_cast<float>(310), 140, 60};
    Color hardColor = themeColor2;

    Color greenButtonColor = {47, 230, 23, 255};
    Color redButtonColor = {232, 18, 18, 255};
    Color blueButtonColor = {13, 64, 216, 255};
    Color purpleButtonColor = {166, 0, 247, 255};

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePoint = GetMousePosition();

        BeginDrawing();
        ClearBackground(themeColor1);
        DrawTextEx(font, "SETTINGS", {screenWidth/2-120, 10}, 60, 2, textColor);
        DrawTextEx(font, "Theme:", {10, 90}, 42, 2, textColor);
        DrawRectangleRec(greenButton, greenButtonColor);
        DrawRectangleRec(redButton, redButtonColor);
        DrawRectangleRec(blueButton, blueButtonColor);
        DrawRectangleRec(purpleButton, purpleButtonColor);

        DrawTextEx(font, "Difficulty:", {10, 250}, 42, 2, textColor);
        DrawRectangleRec(easyButton, easyColor);
        DrawText("Easy", static_cast<int>(easyButton.x) + 70 - MeasureText("Easy", 30)/2 , static_cast<int>(easyButton.y) + 15, 30, textColor);

        DrawRectangleRec(mediumButton, mediumColor);
        DrawText("Medium", static_cast<int>(mediumButton.x) + 70 - MeasureText("Medium", 30)/2 , static_cast<int>(mediumButton.y) + 15, 30, textColor);

        DrawRectangleRec(hardButton, hardColor);
        DrawText("Hard", static_cast<int>(hardButton.x) + 70 - MeasureText("Hard", 30)/2 , static_cast<int>(hardButton.y) + 15, 30, textColor);

        DrawTextEx(font, "Game Speed:", {10, 400}, 42, 2, textColor);

        char rotateText[10];
        sprintf(rotateText, "%d", rotationChance);
        DrawTextEx(font, rotateText, {400, 440}, 42, 2, textColor);

        DrawTextEx(font, "Rotation Chance: ", {10, 440}, 42, 2, textColor);

        char speed[10];
        sprintf(speed, "%d", gameSpeedSettings);
        DrawTextEx(font, speed, {400, 400}, 42, 2, textColor);
        DrawTextEx(font, "/3", {425, 400}, 42, 2, textColor);




        if (!IsWindowMinimized() && !IsWindowResized() && !IsWindowFullscreen())
        {
            if (CheckCollisionPointRec(mousePoint, greenButton))
            {
                greenButtonColor = {47, 230, 23, 160};

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {

                    themeColor1 = {97, 118, 75, 255};
                    themeColor2 = {250, 214, 165, 255};
                    themeColor2Hover = {250, 214, 165, 160};
                    textColor = WHITE;
                    portalImage = LoadImage("img/greenPortal1.png");
                    
                }
            }
            else
            {
                greenButtonColor = {47, 230, 23, 255};
            }  
        }


        if (!IsWindowMinimized() && !IsWindowResized() && !IsWindowFullscreen())
        {
            if (CheckCollisionPointRec(mousePoint, redButton))
            {
                redButtonColor = {232, 18, 18, 160};

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {

                    themeColor1 = {191, 49, 49, 255};
                    themeColor2 = {243, 237, 200, 255};
                    themeColor2Hover = {243, 237, 200, 160};
                    textColor = BLACK;
                    portalImage = LoadImage("img/redPortal1.png");
                }
            }
            else
            {
                redButtonColor = {232, 18, 18, 255};
            }  
        }

        if (!IsWindowMinimized() && !IsWindowResized() && !IsWindowFullscreen())
        {
            if (CheckCollisionPointRec(mousePoint, blueButton))
            {
                blueButtonColor = {13, 64, 216, 160};

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {

                    themeColor1 = {43, 42, 76, 255};
                    themeColor2 = {234, 144, 108, 255};
                    themeColor2Hover = {234, 144, 108, 160};
                    textColor = WHITE;
                    portalImage = LoadImage("img/bluePortal1.png");

                }
            }
            else
            {
                blueButtonColor = {13, 64, 216, 255};
            }  
        }

        if (!IsWindowMinimized() && !IsWindowResized() && !IsWindowFullscreen())
        {
            if (CheckCollisionPointRec(mousePoint, purpleButton))
            {
                purpleButtonColor = {166, 0, 247, 160};

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {   
                    themeColor1 = {154, 32, 140, 255};
                    themeColor2 = {255, 234, 234, 255};
                    themeColor2Hover = {255, 234, 234, 160};
                    textColor = BLACK;
                    portalImage = LoadImage("img/purplePortal1.png");
                }
            }
            else
            {
                purpleButtonColor = {166, 0, 247, 255};
            }  
        }



        if (!IsWindowMinimized() && !IsWindowResized() && !IsWindowFullscreen())
        {
            if (CheckCollisionPointRec(mousePoint, easyButton))
            {
                easyColor = themeColor2Hover;

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    //
                    gameSpeedSettings = 1;
                    rotationChance = 10;
                    setRow = 10;
                    std::cout << "setRowSettings = " << setRow << std::endl;

                }
            }
            else
            {
                easyColor = themeColor2;
            }  
        }

        if (!IsWindowMinimized() && !IsWindowResized() && !IsWindowFullscreen())
        {
            if (CheckCollisionPointRec(mousePoint, mediumButton))
            {
                mediumColor = themeColor2Hover;

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    //
                    gameSpeedSettings = 2;
                    rotationChance = 5;
                    setRow = 15;
                    std::cout << "setRowSettings = " << setRow << std::endl;

                }
            }
            else
            {
                mediumColor = themeColor2;
            }  
        }

        if (!IsWindowMinimized() && !IsWindowResized() && !IsWindowFullscreen())
        {
            if (CheckCollisionPointRec(mousePoint, hardButton))
            {
                hardColor = themeColor2Hover;

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    //
                    gameSpeedSettings = 3;
                    rotationChance = 3;
                    setRow = 20;
                    std::cout << "setRowSettings = " << setRow << std::endl;
                }
            }
            else
            {
                hardColor = themeColor2;
            }  
        }

        EndDrawing();
    }

    UnloadFont(font);

}


void menu(){
    SetWindowSize(500, 620);
    Font font = LoadFont("resources/font.ttf");
    Texture2D background = LoadTexture("resources/background.png");

    float buttonX = 0;
    float buttonY = 0;
    float buttonWidth = 0;

    buttonWidth = (screenWidth / 4);
    buttonX = (screenWidth / 10);

    Rectangle buttonPlay = {buttonX, static_cast<float>(200), buttonWidth, 80};
    Color btnPlayColor = MAGENTA;

    buttonX += buttonWidth + (screenWidth * 0.025); 
    Rectangle buttonSettings = {buttonX, static_cast<float>(300), buttonWidth, 80};
    Color btnSettingsColor = yellowButton;
    buttonX += buttonWidth + (screenWidth * 0.025);

    Rectangle buttonQuit = {buttonX, static_cast<float>(400), buttonWidth, 80};
    Color btnQuitColor = yellowButton;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        Vector2 mousePoint = GetMousePosition();

        BeginDrawing();
        ClearBackground(themeColor1);
        DrawTexture(background, 0, 0, WHITE);

        if (!IsWindowMinimized() && !IsWindowResized() && !IsWindowFullscreen())
        {
            if (CheckCollisionPointRec(mousePoint, buttonPlay))
            {
                btnPlayColor = themeColor2Hover;

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {   
                    std::cout << "AFTER PLAYGAME" << std::endl;
                    playGame();
                    SetWindowSize(500, 620);
                }
            }
            else
            {
                btnPlayColor = MAGENTA;
            }

            if (CheckCollisionPointRec(mousePoint, buttonSettings))
            {
                btnSettingsColor = themeColor2Hover;

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    settings();

                }
            }
            else
            {
                btnSettingsColor = YELLOW;
            }

            if (CheckCollisionPointRec(mousePoint, buttonQuit))
            {
                btnQuitColor = themeColor2Hover;

                if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                {
                    CloseWindow();
                    break;
                }
            }
            else
            {
                btnQuitColor = GREEN;
            }

            DrawText("TETRIS", screenWidth/2 - MeasureText("TETRIS",90)/2, 30, 90, textColor);
            DrawText(fullName, screenWidth/2 - MeasureText(fullName,20)/2, 120, 20, textColor);
            DrawText(number, screenWidth/2 - MeasureText(number,20)/2, 140, 20, textColor);
            DrawText("Space For Pause", screenWidth/2 - MeasureText("Space For Pause",20)/2, 500, 20, textColor);
            DrawText("Enter For Hold", screenWidth/2 - MeasureText("Enter For Hold",20)/2, 530, 20, textColor);
            DrawText("ESC For Back", screenWidth/2 - MeasureText("ESC For Back",20)/2, 560, 20, textColor);
            DrawText("ENJOY!", screenWidth/2 - MeasureText("ENJOY!",20)/2, 590, 20, textColor);

            DrawButtonWithBorder(buttonPlay, btnPlayColor, 5, 5); 
            DrawText("Play Game", static_cast<int>(buttonPlay.x) + (buttonWidth / 2) - MeasureText("Play Game", 25)/2 , static_cast<int>(buttonPlay.y) + 25, 25, textColor);

            DrawButtonWithBorder(buttonSettings, btnSettingsColor, 5 ,5);
            DrawText("Settings", static_cast<int>(buttonSettings.x) + (buttonWidth / 2) - MeasureText("Settings", 25)/2 , static_cast<int>(buttonSettings.y) + 25, 25, textColor);

            DrawButtonWithBorder(buttonQuit, btnQuitColor, 5, 5);
            DrawText("Quit", static_cast<int>(buttonQuit.x) + (buttonWidth / 2) - MeasureText("Quit", 25)/2 , static_cast<int>(buttonQuit.y) + 25, 25, textColor);

        }

        EndDrawing();
    }
    UnloadTexture(background);
    UnloadFont(font);
}



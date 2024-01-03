#include "raylib.h"
#include "game.h"
#include "colors.h"
#include <iostream>
#include "vector.h"

extern Color themeColor1;
extern Color themeColor2;
extern Color themeColor2Hover;
extern Color textColor;
extern Image portalImage;
extern int rotationChance;
extern int gameSpeedSettings;
extern bool isPaused;
extern double lastUpdateTime;
extern Vector2 portalPosition;


bool EventTriggered(double interval);
void playGame();
void settings();
void menu();
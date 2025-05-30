#include <raylib.h>
#include "game.h"
#include "colors.h"
#include <iostream>

const int WW = 500;
const int WH = 620;
const int FPS = 60;

double lastUpdTime = 0;
bool EventTriggered(double interval)
{
    double currentTime = GetTime();
    if (currentTime - lastUpdTime >= interval)
    {
        lastUpdTime = currentTime;
        return true;
    }
    return false;
}

int main()
{
    InitWindow(WW, WH, "Raylib Tetris!");
    SetTargetFPS(FPS);

    Font font = LoadFontEx("assets/monogram.ttf", 64, 0, 0);

    Game game = Game();

    while (!WindowShouldClose())
    {
        UpdateMusicStream(game.music);
        game.HandleInput();
        if (EventTriggered(0.2)) // falling speed
        {
            game.MoveBlockDown();
        }
        BeginDrawing();
        ClearBackground(NAVY);
        DrawTextEx(font, "Score", {365, 15}, 38, 2, WHITE);
        DrawTextEx(font, "Next", {370, 175}, 38, 2, WHITE);
        if (game.gameOver)
        {
            DrawTextEx(font, "GAME OVER!\n restart?\n\t[SPACE]", {320, 450}, 38, 2, WHITE);
        }
        DrawRectangle(320, 55, 170, 60, BLACK);

        char scoreText[10];
        sprintf(scoreText, "%d", game.score);
        Vector2 textSize = MeasureTextEx(font, scoreText, 38, 2);

        DrawTextEx(font, scoreText, {320+(170-textSize.x)/2, 65}, 38, 2, WHITE);
        DrawRectangle(320, 250, 170, 180, BLACK);

        game.Draw();

        EndDrawing();
    }

    CloseWindow();
}

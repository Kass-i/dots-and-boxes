// Dots and Boxes
// Made with raylib
// Katarzyna Idasz
// https://github.com/Kass-i

#include "Menus.h"
#include "MakeLine.h"
#include "EndGame.h"

box    boxes[NumberOfDotsInLine][NumberOfDotsInLine];
player players[4];
global game;

int main()
{
    initGlobal();
    InitWindow(ScreenWidth, ScreenHeight, "Dots and Boxes");
    SetTargetFPS(FPS);
    HideCursor();

    
    while(!WindowShouldClose())
    {
        BeginDrawing();
            DrawFPS(20, 20);

            switch(game.screen)
            {
                case Rules:
                    drawWelcomeScreen(game.frames/FPS);
                    break;
                case Choose:
                    chooseNumberOfPlayers();
                    break;
                case Game:
                    ClearBackground(RAYWHITE);
                    drawScores();

                    drawBoardGrid();
                    drawBoxes();
                    drawLines();
                    drawDots();

                    showMoronText();

                    checkIfGameEnded();

                    drawMouseLine();
                    makeLine();
                    break;
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}

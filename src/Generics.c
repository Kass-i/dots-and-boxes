#include "Generics.h"

void initPlayers()
{
    players[0].line   = DARKBLUE;
    players[0].square = SKYBLUE;
    players[0].score  = 0;
    strcpy(players[0].colorName, "BLUE");

    players[1].line   = MAROON;
    players[1].square = RED;
    players[1].score  = 0;
    strcpy(players[1].colorName, "RED");

    players[2].line   = GOLD;
    players[2].square = YELLOW;
    players[2].score  = 0;
    strcpy(players[2].colorName, "YELLOW");

    players[3].line   = DARKGREEN;
    players[3].square = GREEN;
    players[3].score  = 0;
    strcpy(players[3].colorName, "GREEN");
}

void initGlobal()
{
    game.screen           = Rules;
    game.numberOfPlayers  = 0;
    game.allPoints        = 0;
    game.Round            = 0;
    game.End              = false;
    game.GraczJestDebilem = false;
    game.frames           = 0;

    game.mousePosition.x  = -100.0f;
    game.mousePosition.y  = -100.0f;
    game.direction        = Vertical;
}

void initBoxes()
{
    for(int Y = 0; Y < NumberOfDotsInLine; Y++)
    {
        for(int X = 0; X < NumberOfDotsInLine; X++)
        {
            boxes[X][Y].left  = WHITE;
            boxes[X][Y].right = WHITE;
            boxes[X][Y].up    = WHITE;
            boxes[X][Y].down  = WHITE;
            boxes[X][Y].color = WHITE;

            boxes[X][Y].coord.height = BoxLength;
            boxes[X][Y].coord.width  = BoxLength;
            boxes[X][Y].coord.x      = (X + 1) * BoxLength;
            boxes[X][Y].coord.y      = (Y + 1) * BoxLength;
        }
    }
}

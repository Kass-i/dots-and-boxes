#include "BasicBoard.h"

void drawScores()
{
    int fontSize = 100;
    const int posXColor = 1000;
    const int posXScore = 1250;
    int posY = 100;
    char title[10] = "";

    DrawText("SCORES:", posXColor, posY, fontSize, GridLineColor);

    fontSize /= 2;
    posY += BoxLength;

    for(int i = 0; i < game.numberOfPlayers; i++)
    {
        posY += BoxLength;
        setTitle(title, players[i].colorName);

        DrawText(title, posXColor, posY, fontSize, players[i].line); //Color Text
        DrawText(TextFormat("%02i", players[i].score), posXScore, posY, fontSize, players[i].line); //Score Text
    }
}

void setTitle(char *title, char *text)
{
    strcpy(title, text);
    strcat(title, ": ");
}

void drawDots()
{
    for(int y = BoxLength; y < BoxLength + NumberOfDotsInLine * BoxLength; y += BoxLength)
    {
        for(int x = BoxLength; x < BoxLength + NumberOfDotsInLine * BoxLength; x += BoxLength)
        {
            DrawCircle(x, y, R, DotColor);
        }
    }
}

void drawBoardGrid()
{
    const int pos0 = BoxLength;
    const int lineLength = (NumberOfDotsInLine - 1) * BoxLength;

    for(int iterator = pos0; iterator <= pos0 + lineLength; iterator += BoxLength)
    {
        DrawLine(pos0, iterator, pos0 + lineLength, iterator, GridLineColor); // horizontal
        DrawLine(iterator, pos0, iterator, pos0 + lineLength, GridLineColor); // vertical
    }
}

void drawMouseLine()
{
    game.mousePosition = GetMousePosition();

    Vector2 startPos;
    Vector2 endPos;

    if(game.direction == Vertical)
    {
        startPos.x = game.mousePosition.x;                      startPos.y  = game.mousePosition.y - MouseLineLength/2;
        endPos.x   = game.mousePosition.x;                      endPos.y    = game.mousePosition.y + MouseLineLength/2;
    }
    else // Horizontal
    {
        startPos.x = game.mousePosition.x - MouseLineLength/2;  startPos.y  = game.mousePosition.y;
        endPos.x   = game.mousePosition.x + MouseLineLength/2;  endPos.y    = game.mousePosition.y;
    }

    DrawLineEx(startPos, endPos, LineThickness, players[game.Round].line);
    checkDirectionChange();
}

void checkDirectionChange()
{
    if(IsMouseButtonPressed(MOUSE_RIGHT_BUTTON))
    {
        if(game.direction == Horizontal)
            game.direction = Vertical;
        else
            game.direction = Horizontal;
    }
}

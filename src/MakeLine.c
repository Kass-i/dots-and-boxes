#include "MakeLine.h"

void showMoronText()
{
    if(game.GraczJestDebilem)
    {
        if(game.frames > 0)
        {
            DrawText("ALREADY TAKEN!", 100, 35, 45, VIOLET);
            game.frames--;
        }
        else
        {
            game.frames = FPS;
            game.GraczJestDebilem = false;
        }
    }
}

void makeLine()
{
    if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
    {
        Rectangle mouseLine;

        if(game.direction == Vertical)
        {
            mouseLine.height = MouseLineLength;
            mouseLine.width = LineThickness;
            mouseLine.x = game.mousePosition.x - LineThickness/2;
            mouseLine.y = game.mousePosition.y - MouseLineLength/2;

            collisionVertical(mouseLine);

        }
        else
        {
            mouseLine.height = LineThickness;
            mouseLine.width = MouseLineLength;
            mouseLine.x = game.mousePosition.x - MouseLineLength/2;
            mouseLine.y = game.mousePosition.y - LineThickness/2;

            collisionHorizontal(mouseLine);
        }

        game.Round %= game.numberOfPlayers;
    }
}

void collisionHorizontal(Rectangle mouseLine)
{
    for(int Y = 0; Y < NumberOfDotsInLine; Y++)
    {
        for(int X = 0; X < NumberOfDotsInLine-1; X++)
        {
            Vector2 firstDot = {boxes[X][Y].coord.x,   boxes[X][Y].coord.y};
            Vector2 secondDot = {boxes[X+1][Y].coord.x, boxes[X+1][Y].coord.y};

            bool firstDotCollision  = CheckCollisionCircleRec(firstDot, 2 * R, mouseLine);
            bool secondDotCollision = CheckCollisionCircleRec(secondDot, 2 * R, mouseLine);

            if(firstDotCollision && secondDotCollision && rightPlaceToColor(boxes[X][Y].up))
            {
                boxes[X][Y].up = players[game.Round].line;
                if(Y != 0)
                    boxes[X][Y-1].down = players[game.Round].line;

                colorNeededBoxes(X, Y);
                return;
            }
        }
    }
}

void collisionVertical(Rectangle mouseLine)
{
    for(int Y = 0; Y < NumberOfDotsInLine-1; Y++)
    {
        for(int X = 0; X < NumberOfDotsInLine; X++)
        {
            Vector2 firstDot = {boxes[X][Y].coord.x,   boxes[X][Y].coord.y};
            Vector2 secondDot = {boxes[X][Y+1].coord.x, boxes[X][Y+1].coord.y};

            bool firstDotCollision  = CheckCollisionCircleRec(firstDot, 2 * R, mouseLine);
            bool secondDotCollision = CheckCollisionCircleRec(secondDot, 2 * R, mouseLine);

            if(firstDotCollision && secondDotCollision && rightPlaceToColor(boxes[X][Y].left))
            {
                boxes[X][Y].left = players[game.Round].line;
                if(X != 0)
                    boxes[X-1][Y].right = players[game.Round].line;

                colorNeededBoxes(X, Y);
                return;
            }
        }
    }
}

bool rightPlaceToColor(Color C)
{
    if(!colorcompare(C, WHITE))
    {
        game.GraczJestDebilem = true;
        return false;
    }

    return true;
}

void colorNeededBoxes(int x, int y)
{
    int points = 0;

    for(int Y = y - 1; Y < y + 1; Y++)
    {
        for(int X = x - 1; X < x + 1; X++)
        {
            if(boxShouldBeColored(boxes[X][Y]))
            {
                boxes[X][Y].color = players[game.Round].square;
                points++;
            }
        }
    }

    if(points > 0)
    {
        players[game.Round].score += points;
        game.allPoints += points;
    }
    else
        game.Round++;

}

bool boxShouldBeColored(box k)
{
    bool l = colorcompare(k.left,  WHITE);
    bool r = colorcompare(k.right, WHITE);
    bool u = colorcompare(k.up,    WHITE);
    bool d = colorcompare(k.down,  WHITE);
    bool c = colorcompare(k.color, WHITE);

    if(l == false && r == false && u == false && d == false && c == true)
        return true;
    else
        return false;
}

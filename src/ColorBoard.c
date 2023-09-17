#include "ColorBoard.h"

bool colorcompare(Color A, Color B)
{
   if(A.a != B.a || A.b != B.b || A.g != B.g || A.r != B.r)
        return false;
   else
        return true;
}

void drawBoxes()
{
    for(int Y = 0; Y < NumberOfDotsInLine; Y++)
    {
        for(int X = 0; X < NumberOfDotsInLine; X++)
        {
            if(!colorcompare(boxes[X][Y].color, WHITE))
                DrawRectangleRec(boxes[X][Y].coord, boxes[X][Y].color);
        }
    }
}

void drawLines()
{
    for(int Y = 0; Y < NumberOfDotsInLine ; Y++)
    {
        for(int X = 0; X < NumberOfDotsInLine; X++)
        {
           Vector2 startPos = {boxes[X][Y].coord.x , boxes[X][Y].coord.y};

            if(!colorcompare(boxes[X][Y].left, WHITE))
            {
                Vector2 endPos = startPos;
                endPos.y      += BoxLength;

                DrawLineEx(startPos, endPos, LineThickness, boxes[X][Y].left);
            }
            if(!colorcompare(boxes[X][Y].up, WHITE))
            {
                Vector2 endPos = startPos;
                endPos.x      += BoxLength;

                DrawLineEx(startPos, endPos, LineThickness, boxes[X][Y].up);
            }
        }
    }
}

#include "Menus.h"

void drawWelcomeScreen(int frames)
{
    ClearBackground(RAYWHITE);
    char t[374];
    int fontSize = 75;

    strcpy(t, "   WELCOME TO\nDOTS AND BOXES!");
    scaleAndDrawText(t, ScreenWidth,  20, fontSize, ORANGE);

    fontSize = 40;
    strcpy(t, "THE RULES ARE PRETTY SIMPLE.\nEACH TURN, DRAW ONE HORIZONTAL\nOR VERTICAL LINE TO CONNECT TWO DOTS.\nIF YOU DRAW THE 4TH SIDE OF A BOX,\nYOU EARN A POINT AND TAKE AN EXTRA TURN!\nTHE GAME ENDS WHEN THE WHOLE BOARD IS COVERED.\nPLAYERS WITH THE LARGEST NUMBER OF BOXES WIN\n(YES, A TIE IS POSSIBLE).\nLEFT  MOUSE BUTTON - DRAW A LINE\nRIGHT MOUSE BUTTON - CHANGE DIRECTION\nESC - EXIT");
    scaleAndDrawText(t, 1250,         220, fontSize, GRAY);

    strcpy(t, "PRESS ENTER TO START THE GAME");
    scaleAndDrawText(t, ScreenWidth, 825, fontSize, GridLineColor);


    animation(frames);
    game.frames++;

    if(IsKeyPressed(KEY_ENTER))
        game.screen = Choose;
}

void chooseNumberOfPlayers()
{
    ClearBackground(RAYWHITE);
    scaleAndDrawText("  CHOOSE NUMBER OF PLAYERS\nBY PRESSING A KEY FROM 2 TO 4", ScreenWidth, 350, 60, GridLineColor);

    if(IsKeyPressed(KEY_TWO) || IsKeyPressed(KEY_THREE) || IsKeyPressed(KEY_FOUR))
    {
        game.numberOfPlayers = (GetCharPressed() -'0');
        initBoxes();
        initPlayers();
        game.screen = Game;
        game.frames = FPS;
    }
}

void animation(int frames)
{
    const int numberOfDotsInLineAnimation = 3;

    // Lines
    const int length = (numberOfDotsInLineAnimation - 1) * BoxLength;

    for(int iterator = Ypos0; iterator <= Ypos0 + length; iterator += BoxLength)
        DrawLine(Xpos0, iterator, Xpos0 + length, iterator, GridLineColor); // horizontal

    for(int iterator = Xpos0; iterator <= Xpos0 + length; iterator += BoxLength)
        DrawLine(iterator, Ypos0, iterator, Ypos0 + length, GridLineColor); // vertical


    // Animation
    Vector2 startPos;
    Vector2 endPos;
    Rectangle Rec;
    Rec.height = BoxLength;
    Rec.width  = BoxLength;

    switch(frames)
    {
        case 17:
            DrawText(" BLUE WINS!", Xpos0, 650, 30, DARKBLUE);
        case 16:
            Rec.x = Xpos0;
            Rec.y = Ypos0 + BoxLength;
            DrawRectangleRec(Rec, SKYBLUE);
        case 15:
            startPos.x = Xpos0;
            startPos.y = Ypos0 + BoxLength;
            endPos    = startPos;
            endPos.y += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, DARKBLUE);
        case 14:
            Rec.x = Xpos0 + BoxLength;
            Rec.y = Ypos0 + BoxLength;
            DrawRectangleRec(Rec, SKYBLUE);
        case 13:
            startPos.x = Xpos0 + BoxLength;
            startPos.y = Ypos0 + BoxLength;
            endPos    = startPos;
            endPos.y += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, DARKBLUE);
        case 12:
            Rec.x = Xpos0 + BoxLength;
            Rec.y = Ypos0;
            DrawRectangleRec(Rec, SKYBLUE);
        case 11:
            startPos.x = Xpos0 + 2 * BoxLength;
            startPos.y = Ypos0;
            endPos    = startPos;
            endPos.y += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, DARKBLUE);
        case 10:
            startPos.x = Xpos0 + BoxLength;
            startPos.y = Ypos0 + BoxLength;
            endPos    = startPos;
            endPos.x += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, MAROON);
        case 9:
            Rec.x = Xpos0;
            Rec.y = Ypos0;
            DrawRectangleRec(Rec, RED);
        case 8:
            startPos.x = Xpos0 + BoxLength;
            startPos.y = Ypos0;
            endPos    = startPos;
            endPos.y += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, MAROON);
        case 7:
            startPos.x = Xpos0;
            startPos.y = Ypos0 + BoxLength;
            endPos    = startPos;
            endPos.x += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, DARKBLUE);
        case 6:
            startPos.x = Xpos0 + 2 * BoxLength;
            startPos.y = Ypos0 + BoxLength;
            endPos    = startPos;
            endPos.y += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, MAROON);
        case 5:
            startPos.x = Xpos0;
            startPos.y = Ypos0;
            endPos    = startPos;
            endPos.y += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, DARKBLUE);
        case 4:
            startPos.x = Xpos0;
            startPos.y = Ypos0 + 2 * BoxLength;
            endPos    = startPos;
            endPos.x += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, MAROON);
        case 3:
            startPos.x = Xpos0 + BoxLength;
            startPos.y = Ypos0;
            endPos    = startPos;
            endPos.x += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, DARKBLUE);
        case 2:
            startPos.x = Xpos0 + BoxLength;
            startPos.y = Ypos0 + 2 * BoxLength;
            endPos    = startPos;
            endPos.x += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, MAROON);
        case 1:
            startPos.x = Xpos0;
            startPos.y = Ypos0;
            endPos    = startPos;
            endPos.x += BoxLength;
            DrawLineEx(startPos, endPos, LineThickness, DARKBLUE);
            break;
        case 18:
            game.frames = 0;
            break;
        default:
            break;
    }


    // Dots
    for(int y = Ypos0; y < Ypos0 + numberOfDotsInLineAnimation * BoxLength; y += BoxLength)
    {
        for(int x = Xpos0; x < Xpos0 + numberOfDotsInLineAnimation * BoxLength; x += BoxLength)
        {
            DrawCircle(x, y, R, DotColor);
        }
    }
}

void scaleAndDrawText(char *t, float x, int y, int Size, Color C)
{
    int d = MeasureText(t, Size);
    x = (x - d)/2;
    DrawText(t, x, y, Size, C);
}

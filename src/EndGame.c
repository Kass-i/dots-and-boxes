#include "EndGame.h"

void checkIfGameEnded()
{
    if(game.allPoints == 49)
        showResults();

    if(game.End)
    {
        initGlobal();
        game.screen = Choose;
    }
}

void showResults()
{
    char winnerText[32] = "";

    setWinnerText(winnerText);
    drawPlayAgainText();

    if(IsKeyPressed(KEY_ENTER))
        game.End = true;
}

void setWinnerText(char *winnerText)
{
    int mx = setTheBestPlayer();
    int numberOfWinners = 1;
    Color winnerColor;

    strcpy(winnerText, players[mx].colorName);
    for(int i = 0; i < game.numberOfPlayers; i++) // Check if there are multiple winners
    {
        if(players[i].score == players[mx].score && i != mx)
        {
            strcat(winnerText, " & ");
            strcat(winnerText, players[i].colorName);
            numberOfWinners++;
        }
    }

    if(numberOfWinners == 1)
    {
        strcat(winnerText, " WINS!");
        winnerColor = players[mx].line;
    }
    else
    {
        strcat(winnerText, " WIN!");
        winnerColor = VIOLET;
    }

    scaleAndDrawWinnerText(winnerText, winnerColor);
}

void scaleAndDrawWinnerText(char *winnerText, Color winnerColor)
{
    int Size = 100;
    int d    = MeasureText(winnerText, Size);

    while(d > 750)
    {
        Size -= 5;
        d     = MeasureText(winnerText, Size);
    }

    float x = ScreenWidth/2 + ((ScreenWidth/2 - d)/2);
    DrawText(winnerText, x, 730, Size, winnerColor);
}

int setTheBestPlayer()
{
    int mx = 0;
    if(players[mx].score < players[1].score) mx = 1;
    if(players[mx].score < players[2].score) mx = 2;
    if(players[mx].score < players[3].score) mx = 3;

    return mx;
}

void drawPlayAgainText()
{
    char *text = "PRESS ENTER TO PLAY AGAIN";
    const int fontSize = 50;
    int   d = MeasureText(text, fontSize);
    float x = (ScreenWidth - d)/2;
    DrawText(text, x, 840, fontSize, GridLineColor);
}

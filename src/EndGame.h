#ifndef ENDGAME_H_INCLUDED
#define ENDGAME_H_INCLUDED

#include "Generics.h"

void checkIfGameEnded();
void showResults();
void setWinnerText(char *winnerText);
void scaleAndDrawWinnerText(char *winnerText, Color winnerColor);
int setTheBestPlayer();
void drawPlayAgainText();

#endif // ENDGAME_H_INCLUDED

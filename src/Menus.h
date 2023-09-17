#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "Generics.h"

////////////Defines////////////
#define Xpos0 1250
#define Ypos0 400
///////////////////////////////

void drawWelcomeScreen(int frames);
void chooseNumberOfPlayers();
void animation(int frames);
void scaleAndDrawText(char *t, float x, int y, int Size, Color C);

#endif // MENUS_H_INCLUDED

#ifndef GENERICS_H_INCLUDED
#define GENERICS_H_INCLUDED

#include "raylib.h"
#include <stdio.h>
#include <string.h>

////////////Defines////////////
#define ScreenWidth 1600
#define ScreenHeight 900
#define FPS 60

#define Vertical 0
#define Horizontal 1

#define BoxLength 100
#define NumberOfDotsInLine 8
#define R 10

#define LineThickness 15.0f
#define MouseLineLength 114.0f

#define DotColor BLACK
#define GridLineColor LIGHTGRAY

enum Scrn {Rules, Choose, Game};
///////////////////////////////

typedef struct box
{
    Rectangle coord;
    Color     left;
    Color     right;
    Color     up;
    Color     down;
    Color     color;
} box;

typedef struct player
{
    Color line;
    Color square;
    int   score;
    char  colorName[10];
} player;

typedef struct global
{
    enum Scrn     screen;
    int           numberOfPlayers;
    int           allPoints;
    int           Round;
    bool          End;
    bool          GraczJestDebilem;
    unsigned int  frames;

    Vector2 mousePosition;
    bool    direction;
}global;


extern box    boxes[NumberOfDotsInLine][NumberOfDotsInLine];
extern player players[4];
extern global game;


void initPlayers();
void initGlobal();
void initBoxes();

#endif // GENERICS_H_INCLUDED

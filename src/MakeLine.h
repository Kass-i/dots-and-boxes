#ifndef MAKELINE_H_INCLUDED
#define MAKELINE_H_INCLUDED

#include "ColorBoard.h"

void showMoronText();
void makeLine();
void collisionHorizontal(Rectangle mouseLine);
void collisionVertical(Rectangle mouseLine);
bool rightPlaceToColor(Color C);
void colorNeededBoxes(int x, int y);
bool boxShouldBeColored(box k);

#endif // MAKELINE_H_INCLUDED

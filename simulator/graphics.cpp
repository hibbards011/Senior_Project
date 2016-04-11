/****************************************************
* Program:
*   graphics.cpp
* Author:
*   Samuel Hibbard
* Summary:
*   Defining all the functions that are a part of the
*       graphics class.
****************************************************/

#include "graphics.h"
#include "uiDraw.h"

/****************************************************
* Graphics
*   Constructor for the Graphics class.
****************************************************/
Graphics::Graphics() : fuelText(655, 380), fuelNum(640, 370), distText(-80, 380), distNum(-40, 370), timeText(-695, 380), timeNum(-695, 370)
{
}

/****************************************************
* draw
*   Draw all the graphics on the screen.
****************************************************/
void Graphics::draw(int fuel, int dist, int time) const
{
    // Draw time text with it's number
    drawText(timeText, "Time");
    drawNumber(timeNum, time);

    // Draw the distance the user has traveled with it's number
    drawText(distText, "Distance Traveled");
    drawNumber(distNum, dist);

    // Draw the fuel text with the ship's fuel number
    drawText(fuelText, "Fuel");
    drawNumber(fuelNum, fuel);

    return;
}
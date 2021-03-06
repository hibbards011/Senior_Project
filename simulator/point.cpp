/***********************************************************************
 * Source File:
 *    Point : The representation of a position on the screen
 * Author:
 *    Br. Helfrich & Samuel Hibbard
 * Summary:
 *    Everything we need to know about a location on the screen, including
 *    the location and the bounds.
 ************************************************************************/

#include "point.h"
#include <math.h>
#include <cassert>
using namespace std;

/******************************************
 * POINT : CONSTRUCTOR WITH X,Y
 * Initialize the point to the passed position
 *****************************************/
Point::Point(float x, float y) : x(0.0), y(0.0), check(false), dead(false), wrap(false)
{
   setX(x);
   setY(y);
}

/*******************************************
 * POINT : SET X
 * Set the x position if the value is within range
 *******************************************/
void Point::setX(float x)
{
   assert(xMin < xMax);

    //HERE is where I changed it.
   if (getWrap())
   {
      this->x = x;
      wrapAround();
   }
   else if (!check || (x >= xMin && x <= xMax))
      this->x = x;
   else
   {
      dead = true;
   }
}

/********************************************
 * POINT : Assignmenet
 *******************************************/
const Point & Point :: operator = (const Point & rhs)
{
   x        = rhs.x;
   y        = rhs.y;
   check    = rhs.check;
   dead     = rhs.dead;

   return *this;
}

/*******************************************
 * POINT : SET Y
 * Set the y position if the value is within range
 *******************************************/
void Point::setY(float y)
{
   assert(yMin < yMax);

    //HERE is where I changed it.
   if (getWrap())
   {
      this->y = y;
      wrapAround();
   }
   else if (!check || (y >= yMin && y <= yMax))
      this->y = y;
   else
   {
      dead = true;
   }
}


/******************************************
 * POINT insertion
 *       Display coordinates on the screen
 *****************************************/
std::ostream & operator << (std::ostream & out, const Point & pt)
{
   out << "(" << pt.getX() << ", " << pt.getY() << ")";
   return out;
}

/*******************************************
 * POINT extraction
 *       Prompt for coordinates
 ******************************************/
std::istream & operator >> (std::istream & in, Point & pt)
{
   float x;
   float y;
   in >> x >> y;

   pt.setX(x);
   pt.setY(y);

   return in;
}

/***********************************
 * WRAP
 *      Wrap around the screen!
 *      I created this wrap.
 **********************************/
void Point::wrapAround()
{
    assert(xMin < xMax); //these better be this way!
    assert(yMin < yMax);

    if (x > xMax)
    {
        x -= (xMax - xMin);
    }
    if (x < xMin)
    {
        x += (xMax - xMin);
    }
    if (y > yMax)
    {
        y -= (yMax - yMin);
    }
    if (y < yMin)
    {
        y += (yMax - yMin);
    }

    assert(x <= xMax);  //everything should be now correct!
    assert(x >= xMin);
    assert(y <= yMax);
    assert(y > yMin);
}

void Point::addXY(float x, float y)
{
    setX(getX() + x);
    setY(getY() + y);
}

/****************************************************
* grabDistance
*   This will grab the distance between two points.
****************************************************/
float Point::grabDistance(const Point & rhs)
{
    float newX = rhs.x - this->x;
    float newY = rhs.y - this->y;
    return sqrtf((newX * newX) + (newY * newY));
}
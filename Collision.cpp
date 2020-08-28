#include "Collisions.h"

//Collision Funcs.
//All Collisions
bool Collision(RectBound Obj1, RectBound Obj2)
{
  if (CollisionX(Obj1, Obj2) || CollisionY(Obj1, Obj2))
    return true;
  else
    return false;
}

//Y coord
bool CollisionsGround(RectBound Obj1, RectBound Obj2)
{
  if (Obj1.y >= Obj2.y - Obj1.height)
    return true;
  else
    return false;
}

bool CollisionY(RectBound Obj1, RectBound Obj2)
{
  if (CollisionBottom(Obj1, Obj2) || CollisionTop(Obj1, Obj2))
    return true;
  else
    return false;
}

bool CollisionBottom(RectBound Obj1, RectBound Obj2)
{
  if (Obj1.y <= (Obj2.y + Obj2.height) && (Obj1.y + Obj1.height) >= Obj2.y)
    return true;
  else
    return false;
}
bool CollisionTop(RectBound Obj1, RectBound Obj2)
{
  if (Obj1.y >= (Obj2.y + Obj2.height) && (Obj1.y + Obj1.height) <= Obj2.y)
    return true;
  else
    return false;
}

//X coord
bool CollisionX(RectBound Obj1, RectBound Obj2)
{
  if (CollisionLeft(Obj1, Obj2) || CollisionRight(Obj1, Obj2))
     return true;
   else
     return false;
}

bool CollisionLeft(RectBound Obj1, RectBound Obj2)
{
  if (Obj1.x <= (Obj2.x + Obj2.width) && (Obj1.x + Obj1.width) >= Obj2.x)
    return true;
  else
    return false;
}
bool CollisionRight(RectBound Obj1, RectBound Obj2)
{
  if  (Obj1.x >= (Obj2.x + Obj2.width) && (Obj1.x + Obj1.width) <= Obj2.x)
    return true;
  else
    return false;
}

class RectBound //For boundaries (collisions)
{
  public:
    int x; //X coord
    int y; //y coord
    int width; //width for finding the right side of x coord
    int height; //height for finding the bottom of the y coord
};

//Y coords

bool CollisionsGround(RectBound Obj1, RectBound Obj2);
bool CollisionY(RectBound Obj1, RectBound Obj2);
bool CollisionBottom(RectBound Obj1, RectBound Obj2);
bool CollisionTop(RectBound Obj1, RectBound Obj2);

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


//X coords

bool CollisionX(RectBound Obj1, RectBound Obj2);
bool CollisionLeft(RectBound Obj1, RectBound Obj2);
bool CollisionRight(RectBound Obj1, RectBound Obj2);

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

bool Collision(RectBound Obj1, RectBound Obj2);//For Every Collision in one

bool Collision(RectBound Obj1, RectBound Obj2)
{
  if (CollisionX(Obj1, Obj2) || CollisionY(Obj1, Obj2))
    return true;
  else
    return false;
}

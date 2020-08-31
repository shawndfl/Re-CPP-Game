#ifndef COLLISIONS_H
#define COLLISIONS_H

//Classes and functions
class RectBound //For boundaries (collisions)
{
  public:
    int x; //X coord
    int y; //y coord
    int width; //width for finding the right side of x coord
    int height; //height for finding the bottom of the y coord
};

//Every Collision in one
bool Collision(RectBound Obj1, RectBound Obj2);//For Every Collision in one

//Y coords
bool CollisionsGround(RectBound Obj1, RectBound Obj2);
bool CollisionY(RectBound Obj1, RectBound Obj2);
bool CollisionBottom(RectBound Obj1, RectBound Obj2);
bool CollisionTop(RectBound Obj1, RectBound Obj2);

//X coords
bool CollisionX(RectBound Obj1, RectBound Obj2);
bool CollisionLeft(RectBound Obj1, RectBound Obj2);
bool CollisionRight(RectBound Obj1, RectBound Obj2);

#endif

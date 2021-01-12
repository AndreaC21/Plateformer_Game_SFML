#include "Collectable.hpp"

Collectable::Collectable(std::string t,std::string p, int x, int y) : Displayable(t,p,x,y)
{
    type_collectable = t;
    sprite.scale(0.3f, 0.3f);
    speed = 3;

}

std::string Collectable::getType()
{
    return type_collectable;
}
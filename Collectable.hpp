#ifndef DEF_COLLECTABLE
#define DEF_COLLECTABLE

#include "Displayable.hpp"

class Collectable : public Displayable
{
    private:
        std::string  type_collectable;
    
    public :
        Collectable();
        Collectable(std::string t, std::string p, int x, int y);

        std::string getType();
        bool operator ==( const Collectable &c1)
        {
            return c1.position.x == position.x && c1.position.y==position.y;
        }
};

#endif
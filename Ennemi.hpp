#ifndef DEF_ENNEMI
#define DEF_ENNEMI

#include <string>
#include "Animation.hpp"
#include "Displayable.hpp"

class Ennemi : public Displayable
{
    public:

    Ennemi();
    Ennemi(int x, int ground, bool f);
    Ennemi(const Ennemi &p);
    ~Ennemi();
   
    void bouge();
    void go();
    void flipSprite(float f);
    void changeAnim(int i);
    void setVieMoins(int p);
    void setDecalage(int v);
    bool isDead();

    bool operator==(const Ennemi &e)
    {
        return position.x==e.position.x && position.y== e.position.y;
    }
    Ennemi& operator=(const Ennemi &e)
    {
        position.x = e.position.x;
        position.y = e.position.y;
        texture = e.texture;
        sprite = e.sprite;
        borneXmin = e.borneXmin;
        borneXmax = e.borneXmax;

        return *this;
    }
        
    private:

    std::vector<Animation> listAnim;
    bool direction,estMort;
    int currentAnim;
    int vie,borneXmax,borneXmin;
    sf::Thread t_move;
};

#endif
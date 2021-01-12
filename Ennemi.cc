#include "Ennemi.hpp"

Ennemi::Ennemi(int x, int ground, bool f) : Displayable("Dinosaure/Idle (1).png",x,ground,f), t_move(&Ennemi::bouge,this)
{
    vie = 100;
    direction = true;
    currentAnim = 0;
    flipSprite(1);
    height = 120;
    position.y = ground - height;
    sprite.setPosition(position.x, position.y);
    borneXmax = x + 100;
    borneXmin = x - 100;
    estMort = false;


    listAnim.push_back(* new Animation(&this->texture,&this->sprite,"Dinosaure","Run",8));
   
}

Ennemi::Ennemi(const Ennemi &e) : t_move(&Ennemi::bouge,this)
{
    vie = e.vie;
    direction = e.direction;
    currentAnim = e.currentAnim;
    height = e.height;
    position.y = e.position.y;
    position.x = e.position.x;
    sprite = e.sprite;
    texture = e.texture;
    borneXmin = e.borneXmin;
    borneXmax = e.borneXmax;
    estMort = e.estMort;
    listAnim.push_back(* new Animation(&this->texture,&this->sprite,"Dinosaure","Run",8));
}

Ennemi::~Ennemi()
{
    t_move.terminate();
    listAnim[currentAnim].Stop();
}

void Ennemi::setDecalage(int var)
{
    borneXmax-= var*-4;
    borneXmin-= var *-4;
    position.x -= var*-4;
}
void Ennemi::bouge()
{
    while ( vie > 0)
    {
        if ( direction )
        {
            position.x+=3;
            if ( position.x >= borneXmax) {
                direction=false;
                flipSprite(-1);}
        }
        else 
        {
            position.x-=3;
            if ( position.x <= borneXmin ) { direction=true;  flipSprite(1); }
        }
       // std::cout << "px: " << position.x << " bmin: " << borneXmin  << " bmax: " << borneXmax << std::endl;
        sf::sleep(sf::milliseconds(30));
        sprite.setPosition(position.x,position.y);
    }
    estMort = true;
}

void Ennemi::go()
{
    t_move.launch();
    listAnim[currentAnim].Play();
}

void Ennemi::flipSprite(float f)
{
    sprite.setOrigin({ sprite.getLocalBounds().width/2, 0 });
    sprite.setScale({ f * 0.3f,0.3f});
}
void Ennemi::changeAnim(int i)
{
    if ( currentAnim !=i)
    {
        listAnim[currentAnim].Stop();
        currentAnim = i;
        listAnim[currentAnim].Play();
        //std::cout << "changement" << std::endl;
    }
    
}

void Ennemi::setVieMoins(int p)
{
    vie -= p;
}

bool Ennemi::isDead()
{
    return estMort;
}
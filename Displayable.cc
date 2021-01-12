#include "Displayable.hpp"


Displayable::Displayable()
{
    position.x = 0;
    position.y = 0;
}
Displayable::Displayable(int x, int y)
{
    position.x = x;
    position.y = y;
}

Displayable::Displayable(int x, int y,std::string path)
{
    position.x = x;
    position.y = y;

    texture.loadFromFile("Images/Personnage/"+path);
    sprite.setTexture(texture);
    sprite.setPosition(position.x, position.y);
}
Displayable::Displayable(std::string t,int x, int y, int w, int h, int s=0 )
{
    position.x = x;
    position.y = y;
    width = w;
    speed = s;
    isSolid = false;
    
    texture.loadFromFile("Images/"+t);
    texture.setRepeated(true);

    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(x, y, w, h));
    //sprite.setColor(sf::Color::White);
    sprite.setPosition(position.x, position.y);
  
}
// Panneau,Arbre,buisson
// UI element
Displayable::Displayable(std::string path,int x, int ground, bool f)
{
    position.x = x;
    
    speed = 3;
    isSolid = f;
   
    texture.loadFromFile("Images/"+path);
    sprite.setTexture(texture);
    width = sprite.getTextureRect().width;
    position.y = ground - sprite.getTextureRect().height;
    sprite.setPosition(position.x, position.y);

}
// Collectable : Piece
Displayable::Displayable(std::string t,std::string path, int x, int y)
{

    position.x = x;
    position.y = y;

    texture.loadFromFile("Images/Objets/"+path);
    sprite.setTexture(texture);
    sprite.setPosition(position.x, position.y);

}

Displayable::~Displayable()
{

}

void Displayable::move(int variation)
{
    position.x += speed * variation;
    sprite.setPosition(position.x, position.y);
}

void Displayable::setTexture(std::string path)
{
    texture.loadFromFile("Images/"+path);
    sprite.setTexture(texture);
    sprite.setPosition(position.x, position.y);
    sprite.setScale(0.5f,0.5f);
}

int Displayable::getWidth()
{
    return this->width;
}
int Displayable::getHeight()
{
    return this->height;
}
sf::Sprite Displayable::getSprite()
{
    return this->sprite;
}
Vector2 Displayable::getPosition()
{
    return this->position;
}
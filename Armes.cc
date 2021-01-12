#include "Armes.hpp"

Armes::Armes( std::vector<Ennemi> *le,int x, int y) : Displayable(x,y,"Arme.png"),t_lance(&Armes::bouge,this)
{
    listEnnemi = le;
    vitesse = 5;
    borneMax = x +400;
    sprite.scale(0.5f, 0.5f);
    termine = false;

    go();

    //std::cout << "Arme cree" << position.x<<","<<position.y<< std::endl;
}
Armes::Armes( const Armes &a): t_lance(&Armes::bouge,this)
{
    vitesse = a.vitesse;
    listEnnemi = a.listEnnemi;
    position.x = a.position.x;
    position.y = a.position.y;
    texture = a.texture;
    sprite = a.sprite;
    termine = a.termine;
    
    borneMax = a.borneMax;
    go();
    //std::cout << "Arme cree par copie" << position.x<<","<<position.y<< std::endl;
}
Armes::~Armes()
{
    t_lance.terminate();
    //std::cout << "fin" << std::endl;
}

void Armes::collide()
{
    for ( int i=0; i< listEnnemi->size() ; ++i)
    {
        if (sprite.getGlobalBounds().intersects(listEnnemi[0][i].getSprite().getGlobalBounds() ))
        {
            listEnnemi[0][i].setVieMoins(40);
            t_lance.terminate();
            termine = true;
        }
    }
}
void Armes::bouge()
{
    while(position.x <= borneMax)
    {
        position.x+=vitesse;
        sprite.setPosition(position.x,position.y);
        collide();
        sf::sleep(sf::milliseconds(10));
    }
    termine = true;
}

void Armes::go()
{
    t_lance.launch();
}

bool Armes::aDetruire()
{
    return termine;
}
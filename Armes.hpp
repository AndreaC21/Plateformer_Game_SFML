#include "Ennemi.hpp"

class Armes: public Displayable
{

    public:
        Armes();
        Armes( std::vector<Ennemi> *le,int x, int y);
        Armes(const Armes &a);
        ~Armes();

        bool aDetruire();

        bool operator ==( const Armes &a)
        {
            return a.position.x == position.x && a.position.y==position.y;
        }
        Armes& operator=(const Armes &a)
        {
                position.x = a.position.x;
                sprite = a.sprite;
                texture = a.texture;
                return *this;
        }
    
    private:
        int vie,vitesse,borneMax;
        bool termine;
        sf::Thread t_lance;
        std::vector<Ennemi> *listEnnemi;

        void bouge();
        void go();
        void collide();


};
#ifndef DEF_DISPLAYBLE
#define DEF_DISPLAYBLE

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

struct Vector2
{
    int x; 
    int y;
};
class Displayable
{
    public:

        Displayable();
        Displayable(int x, int y);
        Displayable(std::string pathImage,int x, int y,int w, int h,int s);
        Displayable(int x, int y,std::string path);
        Displayable(std::string path,int x, int ground,bool f=false);
        Displayable(std::string type,std::string path, int x, int y);
    
        ~Displayable();

        void move (int variation);
        void setTexture( std::string path);

        int getWidth();
        int getHeight();
        sf::Sprite getSprite();
        Vector2 getPosition();

         sf::Sprite sprite;

    protected :
        Vector2 position;
        sf::Texture texture;
        sf::Text text;
        
        int speed,width,height;
        bool isSolid;

};


#endif
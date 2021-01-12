#ifndef DEF_ANIMATION
#define DEF_ANIMATION

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class Animation
{
    private :
        std::string nom,pathPersonnage;
        bool isPlaying;
        int maxTexture;
        sf::Texture texture;
        std::vector<sf::Texture> listTexture;
        sf::Sprite *spritePerso;
        sf::Thread t_anim;
        void remplitTabTexture(std::string path);
    public:
        Animation(sf::Texture *texture,sf::Sprite *perso,std::string p,std::string t, int i);
        Animation(const Animation& a);
        ~Animation();

        void Play();
        void Stop();
        void lanceAnimation();
};

#endif
       
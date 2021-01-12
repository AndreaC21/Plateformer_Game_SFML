#ifndef DEF_NIVEAU
#define DEF_NIVEAU

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

//#include "Displayable.hpp"
#include "Personnage.hpp"
#include "Ennemi.hpp"

class Niveau
{
private:
    
    void genereNiveau(int i);
    sf::Music music;
    int index;
    
public:
    
    std::vector<Displayable> listDisplayable;
    std::vector<Plateforme> listPlateforme;
    std::vector<Collectable> listCollectable;
    std::vector<Ennemi> listEnnemi;
    
    Niveau(int index);
    ~Niveau();

    void play_background_sound();
    void stop_background_sound();
    void reset_niveau();
    void update_position_displayable(int var);
    void update_element(std::vector<Armes> *l);
};

#endif
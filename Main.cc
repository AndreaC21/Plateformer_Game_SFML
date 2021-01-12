// ++  Main.cc  Personnage.cc Displayable.cc Plateforme.cc Collectable.cc -o out -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Niveau.hpp"
#include <math.h>  

using namespace  std;

sf::RenderWindow window(sf::VideoMode(900, 700), "Plateformer Game");

Niveau n0(0);
Niveau n1(1);
Niveau n2(2);
Niveau n3(3);
Niveau *currentNiveau;

Personnage joueur;

Displayable panel(350,100);

bool onPause = false;
bool onMenu = true;
bool win = false;

sf::Font font;

// CALCUL FPS
float fps;
sf::Clock fps_clock;
sf::Time previousTime = fps_clock.getElapsedTime();
sf::Time currentTime;
//sf::Time currentTime;

void drawDisplayable()
{
    for ( const auto &d : currentNiveau->listDisplayable)
    {
        window.draw(d.sprite);
    }

    for ( const auto &d : currentNiveau->listCollectable)
    {
        window.draw(d.sprite);
    }

    for ( const auto &d : currentNiveau->listPlateforme)
    {
        window.draw(d.sprite);
    }
    if  (currentNiveau == &n3)
    {
        for ( const auto &d : currentNiveau->listEnnemi)
        {
            window.draw(d.sprite);
        }
        for (const auto &a : joueur.listArmes)
        {
            //cout << a.sprite.getPosition().x << endl;
            window.draw(a.sprite);
        }
    }
   
}
void load_niveau(Niveau *n)
{
    currentNiveau = n;
    currentNiveau->reset_niveau();
    joueur.setPtr(&currentNiveau->listPlateforme,&currentNiveau->listCollectable,&currentNiveau->listDisplayable,&currentNiveau->listEnnemi);
    
}
void niveau_suivant()
{
    if ( currentNiveau == &n1)
    {
        load_niveau(&n2);
    } 
    else if (currentNiveau ==&n2)
    { 
        load_niveau(&n3);
        n3.listEnnemi[0].go();
    }
    else if (currentNiveau ==&n3)
    { 
        onMenu = true;
        currentNiveau->stop_background_sound();
        currentNiveau =&n0;
    }

}

void gestion_controle(sf::Event evt)
{
    if ( onMenu)
    {
        switch (evt.key.code)
        {
            case sf::Keyboard::Numpad1:
            {
                onMenu = false;
                load_niveau(&n1);
                currentNiveau->play_background_sound();
                break;
            }  
            case  sf::Keyboard::Numpad2:
            {
                load_niveau(&n2);
                currentNiveau->play_background_sound();
                onMenu = false;
                break;
            }
            case  sf::Keyboard::Numpad3:
            {
                load_niveau(&n3);
                currentNiveau->listEnnemi[0].go();
                currentNiveau->play_background_sound();
                onMenu = false;
                break;
            }
        }
    }
    else if (win)
    {
        switch (evt.key.code)
        {
            case sf::Keyboard::Escape:
            {
                currentNiveau->stop_background_sound();
                currentNiveau = &n0;
                onPause = false;
                onMenu = true;
                win = false;
                break;
            }  
            case sf::Keyboard::N:
            {
                win = false;
                niveau_suivant();
                break;
            }
        }
    }
    // ON GAME
    else
    {
        if (onPause)
        {
            switch (evt.key.code)
            {
                case sf::Keyboard::Escape:
                {
                    currentNiveau->stop_background_sound();
                    currentNiveau = &n0;
                    onPause = false;
                    onMenu = true;
                    break;
                }  
                case sf::Keyboard::Enter:
                {
                    onPause = false;
                    break;
                }  
            }
            return;
        }
        switch (evt.key.code)
        {
            case sf::Keyboard::Escape:
            {
                panel.setTexture("UI/PanelPause.png");
                onPause = true;
                break;
            }  
            case sf::Keyboard::Space:
                joueur.jump();
                break;
            case sf::Keyboard::Up:
                joueur.lanceArme(); 
                break;
            case sf::Keyboard::Right:
            {
                if ( joueur.collisionDetecter()==1) // il y a une collision
                {
                    currentNiveau->update_position_displayable(2);
                } 
                else if (joueur.collisionDetecter()==2) // le joueur atteint la fin du niveau
                {
                    win = true;
                    panel.setTexture("UI/PanelVictoire.png");
                }
                else
                {
                    joueur.flipSprite(1);
                    joueur.changeAnim(1);
                    currentNiveau->update_position_displayable(-1);
                } 
                break;
            }
            case sf::Keyboard::Left:
            {
                if (joueur.collisionDetecter()==1) // il y a une collision avec un objet
                {
                    currentNiveau->update_position_displayable(-2);
                } 
                else if (joueur.collisionDetecter()==2) // le joueur atteint la fin du niveau
                {
                    win = true;
                    panel.setTexture("UI/PanelVictoire.png");
                }
                else
                {
                    joueur.flipSprite(-1);
                    joueur.changeAnim(1);
                    currentNiveau->update_position_displayable(1);
                } 
                break;
            }
            
        }
    }
}

int main()
{
    // Create a text
    sf::Text textPiece("Piece: ", font);
    font.loadFromFile("Font/arial.ttf");
    textPiece.setCharacterSize(24);
    textPiece.setStyle(sf::Text::Italic);
    textPiece.setFillColor(sf::Color::Blue);
    textPiece.setPosition(750,0);

    // Create a text
    sf::Text textFps("FPS: ", font);
    textFps.setCharacterSize(20);
    textFps.setStyle(sf::Text::Bold);
    textFps.setFillColor(sf::Color::Red);
    textFps.setPosition(0,0);

    currentNiveau = &n0;

    window.setFramerateLimit(120);

    while (window.isOpen())
    {
        sf::Event event;
       
        //sf::Time currentTime = f_clock.getElapsedTime();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                { 
                    window.close();
                }
            if (event.type == sf::Event::KeyPressed)
            {
                gestion_controle(event);
            }
            else if (event.type == sf::Event::KeyReleased && !joueur.IsJumping()) joueur.changeAnim(0);
        }

        currentNiveau->update_element(&joueur.listArmes);
        window.clear();
        drawDisplayable();
        
        if ( !onMenu)
        {
            textPiece.setString(joueur.getPiece());
            window.draw(textPiece);
            window.draw(joueur.sprite);
        } 
        if ( onPause || win ) window.draw(panel.sprite);
        
        currentTime = fps_clock.getElapsedTime();
        fps = 1.0f / (currentTime.asSeconds() - previousTime.asSeconds()); // the asSeconds returns a float
        textFps.setString("FPS: "+to_string((int) floor(fps)));
        previousTime = currentTime;

        window.draw(textFps);
        window.display();
     
    }
        return 0;
}
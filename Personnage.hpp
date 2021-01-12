#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <functional>
#include <list>
#include <string>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include "Plateforme.hpp"
#include "Collectable.hpp"
#include "Animation.hpp"
#include "Armes.hpp"

class Personnage : public Displayable
{
    public:

    Personnage();
    Personnage(const Personnage &p);
    ~Personnage();

    void jump();
    void lanceArme();
    void setPtr(std::vector<Plateforme> *l,std::vector<Collectable> *lc,std::vector<Displayable> *ld, std::vector<Ennemi> *le );
    std::string getPiece();

    void flipSprite(float f);
    void changeAnim( int i);
    int collisionDetecter();
    bool collision(sf:: FloatRect hitBoxPlateforme);
    bool IsJumping();

    std::vector<Armes> listArmes;

        
    private:

        sf::SoundBuffer bufferPiece,bufferCollision;
        sf::Sound sound;
        bool isJumping, OnPlateforme;
        std::vector<Plateforme> *listP;
        std::vector<Collectable> *listC;
        std::vector<Displayable> *listD;
        std::vector<Ennemi> *listE;
        std::vector<Animation> listAnim;
        float forceJump;
        int ground,currentAnim;
        int nb_pieces,nb_diamant,nb_piece_max;

        bool collision_Plateforme();
        bool Displayable_Collision();
        void Collectable_Collision();
        void supprArme();
        bool PlateformeCollision(Plateforme p);
        void gravite();
        void lerp();
    
        bool LeftCollision(Plateforme p);
        bool RightCollision(Plateforme p);
        bool DownCollision(Plateforme p);  
    
};

#endif
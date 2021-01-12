#include "Personnage.hpp"

using namespace std;

Personnage::Personnage() : Displayable()
{
    
    width = 90;
    ground = 640-130; // - height
    position.y = ground;
   
    position.x = 450;
    
    forceJump = 200;
    isJumping =false;
    OnPlateforme = false;

    height = 130;//sprite.getTextureRect().height;
   
    sprite.setPosition(position.x, position.y);
   // sprite.setOrigin({ sprite.getLocalBounds().width/2, 0 });

    if (!bufferCollision.loadFromFile("Sons/collision.wav"))
        std::cout << "error loading sound collision" << std::endl;
    if (!bufferPiece.loadFromFile("Sons/piece.wav"))
        std::cout << "error loading sound piece" << std::endl;
    
    nb_pieces = 0;
    nb_diamant = 0;

    listAnim.push_back(* new Animation(&this->texture,&this->sprite,"Personnage","Idle",8)); 
    listAnim.push_back(* new Animation(&this->texture,&this->sprite,"Personnage","Run",8));
    listAnim.push_back(* new Animation(&this->texture,&this->sprite,"Personnage","Jump",10));

    currentAnim = 0;

    
}
/*
Personnage::Personnage(const Personnage &p)
{
    listP = p.listP;
    listC = p.listC;
    width = p.width;
    ground = p.ground;
    position.x = p.position.x;
    position.y = ground;
    forceJump = 200;
    isJumping =false;
    OnPlateforme = false;
    texture = p.texture;
    sprite = p.sprite;
    height = p.height;
   
}
*/


Personnage::~Personnage()
{
    //delete listC;
    //delete listP;

   // std::cout << "Destructeur personnage" << std::endl;

    listArmes.clear();
    listAnim[currentAnim].Stop();
    listAnim.clear();

}

bool Personnage::IsJumping()
{
    return isJumping;
}

void Personnage::setPtr(std::vector<Plateforme> *l,std::vector<Collectable> *lc,std::vector<Displayable> *ld, std::vector<Ennemi> *le)
{
    listP = l;
    listC = lc;
    listD = ld;
    listE = le;

    nb_diamant = 0;
    nb_pieces = 0;
    nb_piece_max = listC->size() -1 ; // -1 car le diamant est aussi dans cette liste

    listAnim[currentAnim].Stop();
    listAnim[0].Play();
}

void Personnage::changeAnim(int i)
{
    if ( currentAnim !=i)
    {
        listAnim[currentAnim].Stop();
        currentAnim = i;
        listAnim[currentAnim].Play();
        //std::cout << "changement" << std::endl;
    }
    
}

void Personnage::flipSprite(float f)
{
    sprite.setOrigin({ sprite.getLocalBounds().width/2, 0 });
    sprite.setScale({ f * 0.25f, 0.25f }); // f=1 -> droite , f=-1 -> gauche
}

void Personnage::lerp() // s->e 600->500
{
    
    float variation = 0;
    float end  = position.y - forceJump;
    
    isJumping = true;
    changeAnim(2);

    // Monte
    while ( position.y != end)
    {
        position.y+=-1;
        sprite.setPosition(position.x, position.y);
        sf::sleep(sf::milliseconds(10));
        Collectable_Collision();
        
    }
    changeAnim(0);
    gravite();
    isJumping = false;

    
}

void Personnage::gravite()
{
    OnPlateforme = false;
    float acceleration = 2;
    while ( position.y <= ground)
    {
        if (collision_Plateforme() )
        {
            // Le personnage est sur une plateforme
            return;
        }
        position.y+=acceleration;
        sprite.setPosition(position.x, position.y);
        sf::sleep(sf::milliseconds(10));
        acceleration+=0.04;
    }
    position.y = ground;
}
void Personnage::jump()
{
    if (!isJumping)
    {
        static sf::Thread t(&Personnage::lerp,this);
        t.launch();
    }
    
}

void Personnage::lanceArme()
{
    if ( listArmes.size() < 5)
    {
        listArmes.push_back(* new Armes(listE,position.x,position.y+(height/2)));
    }
}

void Personnage::supprArme()
{
    for ( int i=0; i < listArmes.size() ; ++i)
    {
        if  (listArmes[i].aDetruire()) listArmes.erase(std::find(listArmes.begin(),listArmes.end(),listArmes[i]));
    }
}

// APPELER dans Personnage::gravite()
bool Personnage::collision_Plateforme()
{
    for (auto const& p : (*listP)) 
    {
        if (PlateformeCollision(p) )
        {
            OnPlateforme = true;
            return true;
        } 
    }
    OnPlateforme = false;
    return false;
}

int Personnage::collisionDetecter()
{
    supprArme();
    Collectable_Collision();
    
    if ( Displayable_Collision())
    {
        if ( nb_diamant==1) return 2;
        return 1;
    } 
   
    for (auto const& p : (*listP)) 
    {
        //collision(p.sprite.getGlobalBounds());
      
        if  (RightCollision(p) || LeftCollision(p))
        {
           //std::cout << "jX: " << position.x+width << " pX:" << p.position.x << std::endl;
           sound.setBuffer(bufferCollision);
           sound.play();
           return 1;
        }
        else if (!PlateformeCollision(p) && OnPlateforme) // n'est plus SurPlateforme et a été sur une plateforme
        {
           static sf::Thread t(&Personnage::gravite,this);
           t.launch();
        }
    }
    return 0;
}

void Personnage::Collectable_Collision()
{
    sf:: FloatRect hitBoxPlateforme;
    for (Collectable &c : (*listC)) 
    {
        hitBoxPlateforme = c.getSprite().getGlobalBounds();
        if (sprite.getGlobalBounds().intersects(hitBoxPlateforme))
        {
                if ( c.getType()=="Piece") nb_pieces++;
                else nb_diamant++;
                sound.setBuffer(bufferPiece);
                sound.play();
                //(*listC).remove(c);
                (*listC).erase(std::find((*listC).begin(), (*listC).end(), c));

                break;
        }
    }
}

bool Personnage::Displayable_Collision()
{
    if (sprite.getGlobalBounds().intersects((*listD)[2].getSprite().getGlobalBounds() ))
    {
       // std::cout << "end niv"<< std::endl;
        return true;
    }
    return false;

}


// Return true si le joueur est sur la plateforme p
bool Personnage::PlateformeCollision(Plateforme p)
{
    //std::cout << "jX: " << position.x << " jY: " << position.y+100 <<" pX:" << p.position.x <<" pY:" << p.position.y << " p: " << p.width << std::endl;
    return ( position.x >= p.getPosition().x && position.x <= (p.getPosition().x + p.getWidth()) && (position.y+height)>=p.getPosition().y); // 100 -> height
}

bool Personnage::LeftCollision(Plateforme p)
{
    return ((position.y == ground) && position.x >= p.getPosition().x && position.x <= p.getPosition().x + p.getWidth());
}

bool Personnage::DownCollision(Plateforme p)
{
    return ((position.y+height)==p.getPosition().y);
}

bool Personnage::RightCollision(Plateforme p)
{
  // std::cout << "jY: " << position.y << " ground: " << ground << " jX: " << position.x << "pX " << p.position.x << std::endl;
   return ((position.y == ground) && (position.x+(width/2)) >= p.getPosition().x && (position.x+(width/2)) <= p.getPosition().x + p.getWidth());
}


std::string Personnage::getPiece()
{
    return "Piece: "+to_string(nb_pieces)+"/"+to_string(nb_piece_max);
}


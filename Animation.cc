#include "Animation.hpp"

void Animation::remplitTabTexture(std::string path)
{
    
    for ( int i=1; i<=maxTexture; ++i)
    {
        texture.loadFromFile("Images/"+path+"/"+nom+" ("+std::to_string(i)+").png");
        listTexture.push_back(texture);
        //tabTexture.push_back("Images/Personnage/"+nom+" ("+std::to_string(i)+").png");
    }
}

void Animation::lanceAnimation()
{
    int i = 0;
   // std::cout << nom <<std::endl;
    while (isPlaying)
    {
        spritePerso->setTexture(listTexture[i]);
        //spritePerso->setOrigin({ spritePerso->getLocalBounds().width/2, 0 });
        sf::sleep(sf::milliseconds(200));
        ++i;
        if ( i == maxTexture) i = 0;
        
    }
}

Animation::Animation(sf::Texture *textPerso,sf::Sprite *perso,std::string p,std::string t, int i) : t_anim(&Animation::lanceAnimation,this)
{ 
    nom =t; // Run "Run (i).png"
    maxTexture = i;
    isPlaying = false;
    spritePerso = perso;
    pathPersonnage = p;
    remplitTabTexture(pathPersonnage);
    
    spritePerso->setTexture(listTexture[1]);
    spritePerso->setScale(0.25f,0.25f);
    //spritePerso->setPosition(0,0);
    spritePerso->setOrigin({ spritePerso->getLocalBounds().width/2, 0 });
} 

Animation::Animation(const Animation& a) : t_anim(&Animation::lanceAnimation,this)
{
    nom = a.nom;
    maxTexture = a.maxTexture;
    spritePerso = a.spritePerso;
    isPlaying = a.isPlaying;
    pathPersonnage = a.pathPersonnage;
    remplitTabTexture(pathPersonnage);

}

Animation::~Animation()
{
    //std::cout << "Destructeur Animation call : " << nom << std::endl;
    listTexture.clear();
}

void Animation::Play()
{
    isPlaying = true;
    t_anim.launch();
    
}
void Animation::Stop()
{
    isPlaying = false;
    t_anim.terminate();
}
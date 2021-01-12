#include "Niveau.hpp"

Niveau::Niveau(int i)
{
    index = i;
    genereNiveau(index);
    if (!music.openFromFile("Sons/fond-niveau.wav"))
        std::cout << "error loadind music " << std::endl;
  
}
Niveau::~Niveau()
{
    listCollectable.clear();
    listDisplayable.clear();
    listEnnemi.clear();
    listPlateforme.clear();
}

void Niveau::play_background_sound()
{
      //music.play();
}
void Niveau::stop_background_sound()
{
     // music.stop();
}

void Niveau::reset_niveau()
{
    genereNiveau(index);
}
void Niveau::genereNiveau(int i)
{
    int taille_max_jeu = 3000;
    int ground = 640;
    listDisplayable.clear();
    listCollectable.clear();
    listPlateforme.clear();
    listEnnemi.clear();
    if ( i==0)
    {
        listDisplayable.push_back( * new Displayable("UI/FondBleu.png",0,700));
        listDisplayable.push_back( * new Displayable("UI/PanelMenu.png",300,600));
        
    }
    if(i==1)
    {
        listDisplayable.push_back( * new Displayable("tile/BG/BG.png",0,0,taille_max_jeu,800,2));
        listDisplayable.push_back( * new Displayable("tile/Object/Tree-House.png",taille_max_jeu-600,ground+5));
        listDisplayable.push_back( * new Displayable("tile/Object/Sign_1.png",taille_max_jeu-500,ground));
        listDisplayable.push_back( * new Displayable("UI/Niveau1.png",350,100));
        listDisplayable.push_back( * new Displayable("tile/Tiles/2.png",0,ground,taille_max_jeu+600,45,4));
        
        listDisplayable.push_back( * new Displayable("tile/Object/Tree_2.png",150,ground));
        listDisplayable.push_back( * new Displayable("tile/Object/Tree_2.png",900,ground));
        listDisplayable.push_back( * new Displayable("tile/Object/Tree_3.png",950,ground));
        listDisplayable.push_back( * new Displayable("tile/Object/Tree_1.png",1200,ground));
        listDisplayable.push_back( * new Displayable("tile/Object/Bush (1).png",1300,ground));
        listDisplayable.push_back( * new Displayable("tile/Object/Bush (4).png",1500,ground));
        listDisplayable.push_back( * new Displayable("tile/Object/Mushroom_1.png",1750,ground));
        listDisplayable.push_back( * new Displayable("tile/Object/Mushroom_1.png",1850,ground));
        listDisplayable.push_back( * new Displayable("tile/Object/Tree_3.png",1950,ground));

        listPlateforme.push_back( * new Plateforme("tile/Object/Sign_2.png",380,ground));
        listPlateforme.push_back( * new Plateforme("tile/Tiles/5.png",700,500,150,150,4));
        listPlateforme.push_back( * new Plateforme("tile/Object/Crate.png",1600,500,150,150,3));

        listCollectable.push_back( * new Collectable("Piece","piece.png",430,350));
        listCollectable.push_back( * new Collectable("Piece","piece.png",900,350));
        listCollectable.push_back( * new Collectable("Diamant","diamant.png",1650,200));
        listCollectable.push_back( * new Collectable("Piece","piece.png",2250,550));

        
    }
    else if (i==2)   
    {
        listDisplayable.push_back( * new Displayable("tile/BG/BG.png",0,0,taille_max_jeu,800,2));
        listDisplayable.push_back( * new Displayable("tile/Object/Tree-House.png",taille_max_jeu-600,ground+5));
        listDisplayable.push_back( * new Displayable("tile/Object/Sign_1.png",taille_max_jeu-500,ground));
        listDisplayable.push_back( * new Displayable("UI/Niveau2.png",350,100));
        listDisplayable.push_back( * new Displayable("tile/Tiles/2.png",0,ground,taille_max_jeu+600,45,4));
        
        listDisplayable.push_back( * new Displayable("tile/Object/Tree_3.png",150,640));
        listDisplayable.push_back( * new Displayable("tile/Object/Tree_3.png",500,640));
        listDisplayable.push_back( * new Displayable("tile/Object/Stone.png",700,640));
        listDisplayable.push_back( * new Displayable("tile/Object/Mushroom_2.png",900,640));
        listDisplayable.push_back( * new Displayable("tile/Object/Tree_2.png",1200,640));
        listDisplayable.push_back( * new Displayable("tile/Object/Bush (2).png",1300,640));
        listDisplayable.push_back( * new Displayable("tile/Object/Tree_1.png",1600,640));
        listDisplayable.push_back( * new Displayable("tile/Object/Bush (3).png",1700,640));
        listDisplayable.push_back( * new Displayable("tile/Object/Stone.png",2000,640));

        listPlateforme.push_back( * new Plateforme("tile/Object/Sign_2.png",380,640));
        listPlateforme.push_back( * new Plateforme("tile/Object/Crate.png",1050,500,150,150,3));
        listPlateforme.push_back( * new Plateforme("tile/Tiles/5.png",1850,500,150,150,3));
        
        listCollectable.push_back( * new Collectable("Diamant","diamant.png",700,550));
        listCollectable.push_back( * new Collectable("Piece","piece.png",1060,200));
        listCollectable.push_back( * new Collectable("Piece","piece.png",1500,550));
        listCollectable.push_back( * new Collectable("Piece","piece.png",2150,400));
    }
    else if ( i==3)
    {
        taille_max_jeu = 2000;
        listDisplayable.push_back( * new Displayable("tile/BG/BG.png",0,0,taille_max_jeu,800,2));
        listDisplayable.push_back( * new Displayable("tile/Object/Tree-House.png",taille_max_jeu-600,ground+5));
        listDisplayable.push_back( * new Displayable("tile/Object/Sign_1.png",taille_max_jeu-500,ground));
        listDisplayable.push_back( * new Displayable("UI/Niveau3.png",350,100));
        listDisplayable.push_back( * new Displayable("tile/Tiles/2.png",0,ground,taille_max_jeu+600,45,4));
        listPlateforme.push_back( * new Plateforme("tile/Object/Sign_2.png",380,640));

        listCollectable.push_back( * new Collectable("Diamant","diamant.png",1300,550));
        listEnnemi.push_back(* new Ennemi(900,ground,true));
    }
   
}

void Niveau::update_position_displayable(int var)
{
    for ( auto &d : listDisplayable)
    {
        d.move(var);
    }
    for ( Collectable &c : listCollectable)
    {
        c.move(var);
    }
    for ( Plateforme &p : listPlateforme)
    {
        p.move(var);
    }
    for ( auto &p : listEnnemi)
    {
        p.setDecalage(var);
    }
}

void Niveau::update_element(std::vector<Armes> *listArmes)
{
    listEnnemi.size();
    for ( int i=0; i < listArmes[0].size() ; ++i)
    {
        if  (listArmes[0][i].aDetruire()) listArmes[0].erase(std::find(listArmes[0].begin(),listArmes[0].end(),listArmes[0][i]));
    }
    for ( int i=0; i < listEnnemi.size() ; ++i)
    {
        if  (listEnnemi[i].isDead()) listEnnemi.erase(std::find(listEnnemi.begin(),listEnnemi.end(),listEnnemi[i]));
    }
}


#include "Plateforme.hpp"

Plateforme::Plateforme(std::string p,int x, int y, int w, int h,int s) : Displayable(p,x,y,w,h,s)
{
        isSolid = true;
        
}

// Panneau
Plateforme::Plateforme(std::string s, int x, int y) : Displayable(s,x,y,true)
{

}

Plateforme::~Plateforme()
{
    
}

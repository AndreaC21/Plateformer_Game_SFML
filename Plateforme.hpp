#ifndef DEF_PlATEFORME
#define DEF_PlATEFORME

#include "Displayable.hpp"

class Plateforme : public Displayable
{
    public:

    Plateforme();
    Plateforme(std::string p,int x, int y, int w, int h,int s);
    Plateforme(std::string, int x, int y);
    ~Plateforme();

};

#endif
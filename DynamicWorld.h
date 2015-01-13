#ifndef _DYNAMICWORLD_H_
#define _DYNAMICWORLD_H_
#include <stdlib.h>
#include <vector>
#include "Spring.h"

class DynamicWorld
{
public:
   DynamicWorld();
   void init(const int dimX, const int dimY);
   void computeOneStep(const float dt);                 // à appeler depus la fonction animate de la class Viewer
   float distance2pts(Particle *point1, Particle *point2) const;                                   // à appeler depuis la fonction draw de la class Viewer

   Particle *getParticl(int x, int y) {return _m_p[(y * _widget) + x];}
   void DrawParticl(Particle *particule);
   Spring getSpring(int x, int y, int direction);
   Spring getSpring(int index){return _m_s[index];}
   void DrawSpring(Spring spring);

protected:
   std::vector<Particle*> _m_p;
   std::vector<Spring> _m_s;
   int _widget;
   int _height;
};
#endif

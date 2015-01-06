#ifndef _SPRING_H_
#define _SPRING_H_
#include "Particle.h"

class Spring
{
public:
   Spring() : _p1(NULL), _p2(NULL), _l0(0.f), _k(0.f) {}
   Spring(Particle* p1, Particle* p2, const float l0, const float k)
          { set(p1,p2,l0,k); }
   void set(Particle* p1, Particle* p2, const float l0, const float k);
   void applyForceToParticles();
protected:
   Particle* _p1;
   Particle* _p2;
   float _l0;
   float _k;
};
#endif

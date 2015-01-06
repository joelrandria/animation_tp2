#ifndef _PARTICLE_H_
#define _PARTICLE_H_
#include "Vec3.h"

class Particle
{
public:
   Particle(const float _mass, const math::Vec3f _p) : _mass(_mass), _p(_p), _v(0,0,0), _f(0,0,0) {}
   void addForce(const math::Vec3f& af);
   void computeOneStep(const float dt);        // mise à jour de la position et de la vitesse en fonction de f et de dt
protected:
   float _mass;
   math::Vec3f _p;
   math::Vec3f _v;
   math::Vec3f _f;
};
#endif

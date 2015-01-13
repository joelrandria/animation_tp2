#ifndef _PARTICLE_H_
#define _PARTICLE_H_
#include "Vec3.h"
#include <iostream>

class Particle
{
public:
   Particle(  math::Vec3f p, bool fixer = true,  float mass =1.5) :
            _p(p), _fixer(fixer), _mass(mass), _v(0,0,0), _f(0,0,0) {}
   void addForce(const math::Vec3f& af);
   void ResetForce();
   void computeOneStep(const float dt);        // mise à jour de la position et de la vitesse en fonction de f et de dt
   math::Vec3f getPosition(){return _p;}
   math::Vec3f getVitesse(){return _v;}
   math::Vec3f getForce(){return _f;}

   void setFixer(bool mode){_fixer = mode;}
protected:
   math::Vec3f _p;
   bool _fixer;
   float _mass;
   math::Vec3f _v;//vitesse
   math::Vec3f _f;//fore


};
#endif

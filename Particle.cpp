#include "Particle.h"
#include <iostream>

using namespace std;
void Particle::addForce(const math::Vec3f& af)
{
  _f +=af;
}

void
Particle::ResetForce ()
{
        _f =  math::Vec3f(0,0,0);
}

void Particle::computeOneStep(const float dt)
{
  if (_fixer ==  false)/*if (! _fixer)*/
    {
//      cout << "LOL"<< endl;
      _v += (dt / _mass) * _f;
      _p += dt * _v;
    }
}


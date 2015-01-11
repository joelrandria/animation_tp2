#ifndef _SPRING_H_
#define _SPRING_H_
#include <stdlib.h>
#include "Particle.h"

class Spring
{
public:
  Spring() : _p1(NULL), _p2(NULL), _l0(0.f), _k(0.f) {}
  Spring(const Spring& instance)
  {
    *this = instance;
  }

  Spring& operator=(const Spring& instance)
  {
    this->_k = instance._k;
    this->_l0 = instance._l0;
    this->_p1 = instance._p1;
    this->_p2 = instance._p2;

    return *this;
  }

  Spring(Particle* p1, Particle* p2, const float l0, const float k) { set(p1,p2,l0,k); }
  void set(Particle* p1, Particle* p2, const float l0, const float k);
  void applyForceToParticles();

  Particle *getP1(){return _p1;}
  Particle *getP2(){return _p2;}

 // bool cree=false;
protected:
  Particle* _p1;
  Particle* _p2;
  float _l0;
  float _k;

};
#endif

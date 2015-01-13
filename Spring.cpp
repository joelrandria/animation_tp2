#include "Spring.h"
#include <iostream>
#include <stdlib.h>
#include "Vec3.h"
using namespace std;

void Spring::set(Particle* p1, Particle* p2, const float l0, const float k)
{
  this->_k = k;
  this->_l0 = l0;
  this->_p1 = p1;
  this->_p2 = p2;
  //  this->cree = true;
  //  cout << "set" << endl;
}

void Spring::applyForceToParticles()
{

  math::Vec3f u = _p2->getPosition() - _p1->getPosition();

  float l = u.norm();
  u.normalize();

  float viscosite = dot((_p2->getPosition() - _p1->getPosition()),u);
  _p1->addForce( (((_k/_l0) * (l - _l0)) + viscosite)* u );
  _p2->addForce( (((-_k/_l0) * (l - _l0)) + viscosite)* u);
//  _p1->addForce ((_k * (l - _l0)) * u);
//  _p2->addForce ((-_k * (l - _l0)) * u);
}

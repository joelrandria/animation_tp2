#ifdef __LINUX__
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#endif
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Particle.h"
#include "Vec3.h"
#include "DynamicWorld.h"
using namespace std;

DynamicWorld::DynamicWorld(){}


void DynamicWorld::init(const int dimX, const int dimY)
{
  _widget = 1;//dimX;
  _height = dimY;

  for(int y = 0; y < dimY; y++)
    {
      _m_p.push_back(new Particle (math::Vec3f(y, y, 0), (/*(y==0)||*/(y==dimY-1))));//x est fixi a 0
    }//Fin de remplissage des points

  //*****01
  for(int y = 0; y < dimY-1; y++)
    {
      _m_s.push_back(Spring (getParticl(0, y), getParticl(0, y+1), 2.f, 10.f));
    }
  //

}

void DynamicWorld::computeOneStep(const float dt)
{
  int p;

  for(p = 0; p < _height; p++)//initialisation de tt les point a la force de gravité
    {
      _m_p[p]->ResetForce();
      //          particles[p]->ResetForce();
      _m_p[p]->addForce(math::Vec3f (0.0, -9.81, 0.0));
    }

  for (p = 0; p < _height-1; p++)//application la force du ressort sur chaque point
    _m_s[p].applyForceToParticles();

  for(p = 0; p < _height; p++)//mettre a jour les la position et la vitesse
    _m_p[p]->computeOneStep(dt);
}
void DynamicWorld::draw() const
{
}




Spring DynamicWorld::getSpring(int x, int y, int direction)
{
  return _m_s[(direction * (_widget * _height)) + ((y * _widget) + x)];
}

void DynamicWorld::DrawParticl(Particle *particule)
{
  glVertex2f(particule->getPosition().x,
             particule->getPosition().y);
}
void DynamicWorld::DrawSpring(Spring spring)
{
  DrawParticl(spring.getP1());
  DrawParticl(spring.getP2());

}

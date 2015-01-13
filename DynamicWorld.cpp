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

//#define D0 0.5
#define K 100.0

using namespace std;

DynamicWorld::DynamicWorld(){}


void DynamicWorld::init(const int dimX, const int dimY)
{
  _widget = dimX;
  _height = dimY;

  for(int y = 0; y < dimY; y++)//Création des points
    {
      for(int x = 0; x < dimX; x++)
        _m_p.push_back(new Particle (math::Vec3f(x, y, 0), (((y==dimY-1)&&(x==0))||((y==dimY-1)&&(x==dimX-1))) ));//x est fixi a 0
    }//Fin de remplissage des points

  float D0 = distance2pts(_m_p[0], _m_p[1]);
  cout << "D0 = "<< D0 << endl;

  //*****Direction Y
  for(int y = 0; y < dimY-1; y++)
    {
      for(int x = 0; x < dimX; x++)
        {
          _m_s.push_back(Spring (getParticl(x, y), getParticl(x, y+1), D0, K));
        }
    }
  //*****Direction X
  for(int y = 0; y < dimY; y++)
    {
      for(int x = 0; x < dimX-1; x++)
        {
          _m_s.push_back(Spring (getParticl(x, y), getParticl(x+1, y), D0, K));
        }
    }

   D0 = distance2pts(_m_p[0], _m_p[6]);
  cout << "D0 = "<< D0 << endl;
  //*****Direction XY
  for(int y = 0; y < dimY-1; y++)
    {
      for(int x = 0; x < dimX-1; x++)
        {
          _m_s.push_back(Spring (getParticl(x, y), getParticl(x+1, y+1), D0, K));
        }
    }
  //******DirectionYX
  for(int y = 1; y < dimY; y++)
    {
      for(int x = 0; x < dimX-1; x++)
        {
          _m_s.push_back(Spring (getParticl(x, y), getParticl(x+1, y-1), D0, K));
        }
    }


}

void DynamicWorld::computeOneStep(const float dt)
{
  int p;

  for(p = 0; p < _height*_widget; p++)//initialisation de tt les point a la force de gravité
    {
      _m_p[p]->ResetForce();
      //          particles[p]->ResetForce();
      _m_p[p]->addForce(math::Vec3f (0.0, -9.81, 0.0));
    }

  for (p = 0; p < (((_height-1)*_widget)*2)+(((_height-1)*(_widget-1))*2); p++)//application la force du ressort sur chaque point
    _m_s[p].applyForceToParticles();

  for(p = 0; p < _height*_widget; p++)//mettre a jour les la position et la vitesse
    _m_p[p]->computeOneStep(dt);
}

float DynamicWorld::distance2pts(Particle *point1, Particle *point2) const
{
  math::Vec3f v = point2->getPosition() - point1->getPosition();
  return v.norm();
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

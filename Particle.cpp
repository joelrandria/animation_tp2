#include "Particle.h"

void Particle::addForce(const math::Vec3f& af)
{
  _f +=af;
}

void Particle::computeOneStep(const float dt)
{

}

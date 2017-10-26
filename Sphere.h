
#include <glm/vec3.hpp>

#ifndef _SPHERE_H_
#define _SPHERE_H_

class Sphere:public _3DObject {
private:
  glm::vec3 _center;
  float _radius;
public:
  Sphere(glm::vec3 center, float radius): _center(center), _radius(radius){ };
  ~Sphere( ){ };
  
}
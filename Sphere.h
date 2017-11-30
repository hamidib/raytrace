
#include <glm/vec3.hpp>
#include "Group.h"
#include "Object.h"
#include "Ray.h"
#include "Hit.h"
#include <vector>
#ifndef _SPHERE_H_
#define _SPHERE_H_

class Sphere: public Object
{
private:
  
public:
	glm::vec3 _center;
    float _radius;
	//Sphere(){};
	Sphere(float r , glm::vec3 c ):Object(), _radius(r), _center(c){};
	//Sphere(_center, _radius): Object3D(_center, _raidus){ };
    //Sphere(glm::vec3 center, float radius): _center(center), _radius(radius){ };
  	~Sphere( ){ };
  	//bool intersect( Ray myRay, Hit h ){};
  	float getRadius(){return _radius;}
  	glm::vec3 getCenter(){return _center;}
  
     Sphere & operator=(Sphere & s)
    {
  		_radius = s._radius; //edit
  		_center = s._center; //edit
  		return *this;
    }


	bool quadratic (float a, float b, float c, float &x0, float &x1) 
	{ 
 
    	float discr = b * b - 4 * a * c; 
    	if (discr < 0) return false; 
    	x0 = (-b + sqrt(discr) / (2 * a));
    	x1 = (-b - sqrt(discr) / (2 * a));
    	if (x0 > x1) std::swap(x0, x1); 
 
    	return true; 

	}

	bool intersect ( Ray &r, Hit &h, float &t ){  //r=radius //ray const
    //float t;
    glm::vec3 tmp = r.getPoint( ) - _center;
    float a = glm::dot(r.getDirection( ), r.getDirection( ));
    float b = 2.0 * glm::dot(tmp, r.getDirection( ));
    float c = glm::dot(tmp, tmp) - (_radius * _radius);
    float discriminant = b * b - 4.0 * a * c;
    if(discriminant < 0.0){
      return false;
    }else{
      float e = std::sqrt(discriminant);
      float denom = 2.0 * a;
      t = (-b - e) / denom;
      if(t > 0.000001){
      	h.normal = (tmp + t * r.getDirection()) / _radius;
      	h.hitPoint = r.getPoint() + t * r.getDirection();
        return true;
      }
      t = (-b + e) / denom;
      if(t > 0.000001){
      	h.normal = (tmp + t * r.getDirection()) / _radius;
      	h.hitPoint = r.getPoint() + t * r.getDirection();
        return true;
      }
    }
    return false;
  }


};
#endif
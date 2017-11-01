
#include <glm/vec3.hpp>
#include "Group.h"
#include "3DObject.h"
#ifndef _SPHERE_H_
#define _SPHERE_H_

class Sphere//:public Object3D 
{
private:
  
public:
	glm::vec3 _center;
    float _radius;
	Sphere(){};
    Sphere(glm::vec3 center, float radius): _center(center), _radius(radius){ };
  	~Sphere( ){ };
  
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
    	x0 = (-b + sqrt(discr) / (2 *a));
    	x1 = (-b - sqrt(discr) / (2 * a));
    	if (x0 > x1) std::swap(x0, x1); 
 
    	return true; 

	}

	bool intercept ( glm::vec3 myRay, glm::vec3 dir, glm::vec3 myCenter, float r, float t){  //r=radius
    
    	glm::vec3 L = myRay - myCenter;
    	float t0, t1;
    	//float mult = -2.0;
    	float R = r * r; 
    	//glm::vec3 L = l * l;                                                    // radius^2
    	float a = glm::dot( dir , dir );                                     //where a = x^2 
    
                                                                    //for element we need to traverse the array of rays to do all these for each ray
       
    	//glm::vec3 b0 = mult * dot(myRay * dir);                                       //where b = bx  
    	float b = 2 * glm::dot(dir, L); 
    
    	float c = pow(L.x, 2) + pow(L.y, 2) + pow(L.z, 2) - R;//glm::dot( L, L ) - R ;                    //where c = c //r = radius //element = ray in vector container  
    
    	if( !quadratic( a, b, c, t0, t1 ) ) return false;
    	if (t0 > t1) {                                       //the intercept that applies is the closest intercept
    	    std::swap( t0, t1);
    	} 
    	if (t0 < 0) {
       		t0 = t1;                                         //if i0 is negative, then use i1
        	if (t0 < 0)                                      //if i1 is also negative, return false 
        	return false;
    	}
    	t= t0;    
    	return true;

	}

};
#endif
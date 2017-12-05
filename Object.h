/* Your Name Here
 * somebody at something dot TLD
 * CS 566
 * September 20XX
 *
 * $Id: 3DObject.h 1961 2010-02-24 08:46:53Z mshafae $
 *
 */

#ifndef _OBJECT_
#define _OBJECT_
#include "glm/glm.hpp"
#include "Ray.h"
#include "Hit.h"

//#include "Sphere.h"
//#include "Group.h"

class Object//: public Group
{
		//float _radius;
		//glm::vec3 _center;

	public:
		//Sphere _s;
		//Object3D(){};
		Object(){};//Object3D(): {}:Group(); //
		//Object3D(Sphere s): _s(s) {}:Group( n, m, o3d);
		virtual ~Object(){};
        //make subclass for circles and put 3dobjects in groups

		//code for quadratic formula

	virtual bool intersect(Ray &r, Hit &h, float &t) = 0; // all intersects take a ray and hit object
	virtual int getMaterialIndex() = 0;
	//virtual float getRadius() ;
	//virtual glm::vec3 getcenter() ;

    Object& operator=(Object& o)
  {
  	//_s = o._s; 
  	return *this;
  }





};

/*
class sphere::_3DObject{
	public:
           glm::vec3 _center;
	   float _radius;
           sphere( ){};

	   sphere( ){};
	   
	   bool intercept(glm::vec3 , glm::vec3 , float , float );

	   ~sphere( ){};


};
*/
#endif

/* Your Name Here
 * somebody at something dot TLD
 * CS 566
 * September 20XX
 *
 * $Id: 3DObject.h 1961 2010-02-24 08:46:53Z mshafae $
 *
 */

#ifndef _OBJECT3D_
#define _OBJECT3D_
#include "Ray.h"
#include "Sphere.h"
#include "Group.h"

class Object3D//:public Group
{
	public:
		Sphere _s;

		Object3D(){};
		Object3D(Sphere s): _s(s) {};
		~Object3D(){};
        //make subclass for circles and put 3dobjects in groups

		//code for quadratic formula

    Object3D& operator=(Object3D& o)
  {
  	_s = o._s; //edit
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

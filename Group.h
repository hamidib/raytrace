/* Your Name Here
 * somebody at something dot TLD
 * CS 566
 * September 20XX
 *
 * $Id: Group.h 1961 2010-02-24 08:46:53Z mshafae $
 *
 */

#ifndef _GROUP_H_
#define _GROUP_H_

#include <vector>
#include "glm/glm.hpp"

class Group{
public:
	float _numObjects;
	float _materialIndex;
	float _radius;
	glm::vec3 _center;//must hold 3d object

	Group(){};
	Group( float n, float m, float r, glm::vec3 c ): _numObjects(n), _materialIndex(m), _radius(r), _center(c) {
		/*numObjects = n;
		materialIndex = m;
		radius = r;
		center = c;*/
	};
	~Group( ){};

  //member functions for intercept---> will have to move to obj class

  
  friend bool quadratic(float a, float b, float c, float x0, float x1);
  bool intercept(glm::vec3 myRay, glm::vec3 dir, glm::vec3 myCenter, float r, float t );

  //bool intercept2(glm::vec3, glm::vec3);

  Group& operator=(Group& g)
  {
  	
  	_numObjects = g._numObjects;
  	_materialIndex = g._materialIndex;
  	_radius = g._radius;
  	_center = g._center;
  	return *this;
  }
};

#endif

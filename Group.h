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

class Group{
	float numObjects;
	float materialIndex;
	float radius;
	glm::vec3 center;//must hold 3d object
public:
	Group(){};
	Group( float n, float m, float r, glm::vec3 c ){
		numObjects = n;
		materialIndex = m;
		radius = r;
		center = c;
	};
	~Group( ){};

  Group& operator=(Group& g)
  {
  	
  	numObjects = g.numObjects;
  	materialIndex = g.materialIndex;
  	radius = g.radius;
  	center = g.center;
  	return *this;
  }
};
#endif
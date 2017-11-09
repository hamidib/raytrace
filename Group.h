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
#include "Ray.h"
#include "Object.h"
#include "glm/glm.hpp"
using namespace std;

class Group{
public:
	float _numObjects;
	float _materialIndex;
  vector<Object*> myObjects;
  //Object3D _o3d;
	//float _radius; //moved to sphere
	//glm::vec3 _center; //moved to sphere

	Group(){};
	Group( float n, float m, vector<Object*> o): _numObjects(n), _materialIndex(m), myObjects(o) {};
  //Group( Object3D o3d): _o3d(o3d) {};
	~Group( ){};

  //member functions for intercept---> will have to move to obj class

  
  //friend bool quadratic(float a, float b, float c, float x0, float x1);
  //bool intercept(glm::vec3 myRay, glm::vec3 dir, glm::vec3 myCenter, float r, float t );
  //bool testIntersection(Ray myRay, Group sphere);

  //bool intercept2(glm::vec3, glm::vec3);

  Group& operator=(Group& g)
  {
  	
  	_numObjects = g._numObjects;
  	_materialIndex = g._materialIndex;
  	myObjects = g.myObjects;
  	return *this;
  }
};

#endif

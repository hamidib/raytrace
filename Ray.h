/* Your Name Here
 * somebody at something dot TLD
 * CS 566
 * September 20XX
 *
 * $Id: Ray.h 1961 2010-02-24 08:46:53Z mshafae $
 *
 */

#ifndef _RAY_H_
#define _RAY_H_

#include <vector>
#include "glm/glm.hpp"

class Ray{
	glm::vec3 _p;
	glm::vec3 _d;

	int _i; //pixel coord
	int _j; //pixel coord
public:
	Ray(glm::vec3 p, glm::vec3 d, int i, int j): _p(p), _d(d), _i(i), _j(j){};//initalize data members without going into constructor

/* //construct this one from previoius - complier cant tell the difference 
	Ray(glm::vec3 p0, glm::vec3 p1): _p(p1){
		_d = (p0 - p1);
		_d = _d / length(_d);
	}
*/
	~Ray( ){};

	glm::vec3 returnPoint()
	{
		return _p;
	}

	int returnX()
	{
		return _i;
	}

	int returnY()
	{
		return _j;
	}


};
#endif
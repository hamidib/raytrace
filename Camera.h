/* Your Name Here
 * somebody at something dot TLD
 * CS 566
 * September 20XX
 *
 * $Id: Camera.h 1961 2010-02-24 08:46:53Z mshafae $
 *
 */

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <vector>
#include "glm/glm.hpp"

class Camera{
public:
	glm::vec3 _center;
 	glm::vec3 _direction;
 	glm::vec3 _up;
 	float _width, _height;
	Camera(){};
 	Camera(glm::vec3 mycenter, glm::vec3 mydirection, glm::vec3 myup, float w, float h ): _center(mycenter), _direction(mydirection), _up(myup), _width(w),_height(h) {
 	/*center = mycenter; 
 	direction = mydirection;
 	up = myup;
 	width = w;
 	height = h; */
	};
 ~Camera( ){};

  Camera& operator=(Camera& c)
  {
  	_center = c._center;
  	_direction = c._direction;
  	_up = c._up;
  	_width = c._width;
  	_height = c._height;
  	return *this;
  }
};
#endif


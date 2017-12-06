/* Bijan Hamidi & Ruth Obidah
 * bhamidi@csu.fullerton.edu, ruthobidah@csu.fullerton.edu
 * CS 599 Independent Study
 * December 2017
 *
 * $Id: Camera.h 1961 2017-12-05 08:46:53Z mshafae $
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
 	int _width, _height;
  float _pixelSize;
	Camera(){};
 	Camera(glm::vec3 mycenter, glm::vec3 mydirection, glm::vec3 myup, 
	float w, float h ): _center(mycenter), _direction(mydirection), 
	_up(myup), _width(w),_height(h) {
 	/*center = mycenter; 
 	direction = mydirection;
 	up = myup;
 	width = w;
 	height = h; */
    _pixelSize = 0.25;
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
  float pixelWidth( ) const {
    return _width / _pixelSize;
     }

  float pixelHeight( ) const {
    return _height / _pixelSize;
     }
};
#endif


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
	glm::vec3 _center;//_position;
 	glm::vec3 _direction;//_lookAt;
 	glm::vec3 _up;
 
	Camera(){};
 	Camera(glm::vec3 c, glm::vec3 d, glm::vec3 myup, 
	float w, float h ): _center(c), _direction(d), 
	_up(myup){
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
  	return *this;
     }
  /*float pixelWidth( ) const {
    return _width / _pixelSize;
     }

  float pixelHeight( ) const {
    return _height / _pixelSize;
     }*/
};
#endif


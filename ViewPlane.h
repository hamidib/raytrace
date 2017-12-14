/* Bijan Hamidi & Ruth Obidah
 * bhamidi@csu.fullerton.edu, ruthobidah@csu.fullerton.edu
 * CS 599 Independent Study
 * December 2017
 *
 * $Id: Camera.h 1961 2017-12-05 08:46:53Z mshafae $
 *
 */

#ifndef _VIEWPLANE_H_
#define _VIEWPLANE_H_

#include <vector>
#include "glm/glm.hpp"

class ViewPlane{
public:

 	int _width, _height, /*_sampleCount */;   //add sample count when what it does is known
  	float _pixelSize;

	ViewPlane(){};
 	ViewPlane(int w, int h, float p ): _center(mycenter), _direction(mydirection), 
	_up(myup), _width(w),_height(h), _pixelsize(p) {}
 	/*center = mycenter; 
 	direction = mydirection;
 	up = myup;
 	width = w;
 	height = h; };*/
 ~ViewPlane( ){};

  ViewPlane& operator=(ViewPlane& v)
     {
  	_width = v._width;
  	_height = v._height;
	_pixelSize = v._pixelSize;
  	return *this;
     }
  float pixelWidth( ) const {
    return _width / _pixelSize;
     }

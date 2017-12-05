#ifndef _RGBCOLOR_H_
#define _RGBCOLOR_H_

#include "glm/vec3.hpp"

class RGBcolor{
	public:
	glm::vec3 _Color;
	//RGBcolor( );
	RGBcolor( glm::vec3 c): _Color(c){};
	~RGBcolor( );

	glm::vec3 getColor() {return _Color;}

	RGBcolor & operator=(RGBcolor & r)
    	    {
  		_Color = r._Color;
  		return *this;
    	    }

};

#endif

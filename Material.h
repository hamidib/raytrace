/* Your Name Here
 * somebody at something dot TLD
 * CS 566
 * September 20XX
 *
 * $Id: Material.h 1961 2010-02-24 08:46:53Z mshafae $
 *
 */
#include "glm/vec3.hpp"
#include "RGBcolor.h"
#include <vector>
using namespace std;

#ifndef _PHONG_MATERIAL_H_
#define _PHONG_MATERIAL_H_

class Material{
public:
	vector<RGBcolor*> myRGBcolors;
	//glm::vec3 _Color;
	Material(){};
	Material( vector<RGBcolor*> c): myRGBcolors(c){};
	~Material(){};

	//glm::vec3 getColor() {return ;}

	Material& operator=(Material& m)
  	  {
  	
  		myRGBcolors = m.myRGBcolors;
  		return *this;
  	  }
};
#endif

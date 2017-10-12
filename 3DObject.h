/* Your Name Here
 * somebody at something dot TLD
 * CS 566
 * September 20XX
 *
 * $Id: 3DObject.h 1961 2010-02-24 08:46:53Z mshafae $
 *
 */

#ifndef _3D_OBJECT_
#define _3D_OBJECT_

 #include "ray.h"

class _3DObject
{
	public:
		_3DObject(void);

		~_3DObject(void);
        //make subclass for circles and put 3dobjects in groups

		//code for quadratic formula

bool quadratic(float &a, float &b, float &c, float &x0, float &x1) 
{ 
    float discr = b * b - 4 * a * c; 
    if (discr < 0) return false; 
    else if (discr == 0) x0 = x1 = - 0.5 * b / a; 
    else { 
        float q = (b > 0) ? 
            -0.5 * (b + sqrt(discr)) : 
            -0.5 * (b - sqrt(discr)); 
        x0 = q / a; 
        x1 = c / q; 
    } 
    if (x0 > x1) std::swap(x0, x1); 
 
    return true; 
}



//code/psuedo code for intersect of ray and sphere either we save the intercept to the depth file here or change the return type
bool intersect ( vector<glm::vec3> myRays, glm::vec3 dir, float rad){
    float i0, i1;
    float R = r * r;                                                     // radius^2
    float a = glm::dot( dir , dir );                                     //where a = x^2 
    
    for(glm::vec3 element : myRays){                          //for element we need to traverse the array of rays to do all these for each ray
        float b = -2 * element * dir;                                       //where b = bx  
        
        float c = (-1* R + glm::dot( element, element );     //where c = c //r = radius //element = ray in vector container
        
        if( !quadratic( a, b, c, i0, i1 ) ) return false;
        if (i0 > i1) {                                       //the intercept that applies is the closest intercept
            std::swap( i0, i1);
        } 
        if (i0 < 0) {
            i0 = i1;                                         //if i0 is negative, then use i1
            if (i0 < 0)                                      //if i1 is also negative, return false 
            return false;
        }
        
        return true;
    }

}

};
#endif
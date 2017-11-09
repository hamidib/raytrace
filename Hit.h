/* Your Name Here
 * somebody at something dot TLD
 * CS 566
 * September 20XX
 *
 * $Id: Hit.h 1961 2010-02-24 08:46:53Z mshafae $
 *
 */

#ifndef _HIT_H_
#define _HIT_H_
#include <glm/vec3.hpp>
#include <vector>
using namespace std;

class Hit{
public:

	vector<glm::vec3> hits;

	Hit( );
	~Hit( );

	void push(glm::vec3 v)
	{
		hits.push_back(v);
	}

	 Hit & operator=(Hit & h)
    {
  		hits = h.hits;
  		return *this;
    }
};
#endif
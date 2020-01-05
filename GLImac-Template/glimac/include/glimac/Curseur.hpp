#pragma once

#include <glm/glm.hpp>
#include "glimac/Cube.hpp"
#include <vector>



namespace glimac {

class Curseur {

	public:
	     Cube curseurCube;
	     glm::vec3 coord;
	     
	     Curseur();
	     ~Curseur();
	     void changeCoord(int axe, int increment);
	     void drawCurseur();
	};
    
}

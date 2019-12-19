/*#pragma once

#include <glm/glm.hpp>
#include "glimac/Cube.hpp"
#include <vector>


namespace glimac {

class Curseur {
    public:
        Curseur();
        ~Curseur();
        Cube cubeCurseur;
        void drawCurseur(Cube &cubeCurseur);
        void liberateCurseur(Cube &cubeCurseur);
        void curseurBuffer(Cube &cubeCurseur);

    private:

};

}
*/


#pragma once

#include <glm/glm.hpp>
#include <vector>
#include <glimac/Cube.hpp>
#include <glimac/common.hpp>

namespace glimac {

	class Cursor:public Cube {

	public:
	    Cursor();
	      glm::vec3 getCurseurPosition();
	      void updatePosX(float direction);
	      void updatePosY(float direction);
	      void updatePosZ(float direction);
	      void updateVertices();
	      void renderCursor();
	};

}

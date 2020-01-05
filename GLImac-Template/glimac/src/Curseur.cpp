#include <glimac/Curseur.hpp>


namespace glimac {

    Curseur::Curseur()
    : coord(0., 0., 0.)
    {
        curseurCube.addCube(coord);
    }

    Curseur::~Curseur(){
    }

    void Curseur::changeCoord(int axe, int increment){
        curseurCube.removeCube(coord);

        if (axe == 0) {
            coord += glm::vec3(increment, 0, 0);
        } 
        else if (axe == 1) {
            coord += glm::vec3(0, increment, 0);
        } 
        else if (axe == 2) {
            coord += glm::vec3(0, 0, increment);
        }

        curseurCube.addCube(coord);
    }

    void Curseur::drawCurseur(){
        curseurCube.drawCubeCurseur();
    }
}
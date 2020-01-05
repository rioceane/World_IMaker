#pragma once
#include <GL/glew.h>
#include "glm.hpp"

namespace glimac {

    class Vertex3DColor
        {    
        public:
            glm::vec3 m_position;
            glm::vec3 m_color;
            Vertex3DColor();
            Vertex3DColor(glm::vec3 position, glm::vec3 color)
                :m_position(position), m_color(color) {}
        };

    struct ShapeVertex {
        glm::vec3 position = glm::vec3(0.f, 0.f, 0.f);
        glm::vec3 normal = glm::vec3(0.f, 0.f, 0.f);
        glm::vec2 texCoords = glm::vec2(0.f, 0.f);

        ShapeVertex() {}
        ShapeVertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 tex) : position(pos), normal(norm), texCoords(tex) {}
        //ShapeVertex(const ShapeVertexHomo &src) : position(glm::vec3(src.position)), normal(glm::vec3(src.normal)), texCoords(src.texCoords) {} //CODER LA SURCHARGE DU EGAL
    };

}
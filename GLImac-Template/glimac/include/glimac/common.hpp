#pragma once

#include <GL/glew.h>
#include "glm.hpp"

namespace glimac {

struct ShapeVertexHomo {
    glm::vec4 position = glm::vec4(0.f, 0.f, 0.f, 1.f);
    glm::vec4 normal = glm::vec4(0.f, 0.f, 0.f, 0.f);
    glm::vec2 texCoords = glm::vec2(0.f, 0.f);

    ShapeVertexHomo(glm::vec4 pos, glm::vec4 norm, glm::vec2 tex) : position(pos), normal(norm), texCoords(tex) {}
};

/*
struct Vertex3DColor
{
    glm::vec3 v_position= glm::vec4(0.f, 0.f, 0.f, 1.f);;
    glm::vec3 v_normal= glm::vec4(0.f, 0.f, 0.f, 0.f);;
    glm::vec2 v_texCoords= glm::vec2(0.f, 0.f);

    Vertex3DColor(glm::vec3 v_position, glm::vec3 v_normal, glm::vec2 v_texCoords) : position(pos), normal(norm), texCoords(tex) {}
};
*/

struct ShapeVertex {
    glm::vec3 position = glm::vec3(0.f, 0.f, 0.f);
    glm::vec3 normal = glm::vec3(0.f, 0.f, 0.f);
    glm::vec2 texCoords = glm::vec2(0.f, 0.f);

    ShapeVertex() {}
    ShapeVertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 tex) : position(pos), normal(norm), texCoords(tex) {}
    ShapeVertex(const ShapeVertexHomo &src) : position(glm::vec3(src.position)), normal(glm::vec3(src.normal)), texCoords(src.texCoords) {} //CODER LA SURCHARGE DU EGAL
};

}

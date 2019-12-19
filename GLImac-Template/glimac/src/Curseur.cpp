/*
#include <iostream>
#include <cassert>
#include "glimac/Curseur.hpp"

namespace glimac {

    Curseur::Curseur()
    {
    }

    Curseur::~Curseur()
    {
    }

    void Curseur::curseurBuffer(Cube &cubeCurseur){
        cubeCurseur.createBuffer();
    }

    void Curseur::drawCurseur(Cube &cubeCurseur) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        cubeCurseur.drawCube();
    }

    void Curseur::liberateCurseur(Cube &cubeCurseur) {
        cubeCurseur.deleteBuffers();
    }

}
*/


#include <vector>
#include <iostream>
#include <glimac/Curseur.hpp>


namespace glimac {

    constexpr int VOLUME = 10

    Curseur::Curseur(){
      position = glm::vec3(0,5,VOLUME-1);
    }

    glm::vec3 Curseur::getCurseurPosition(){
      return position;
    }

    void Curseur::updatePosX(float direction){
      position.x += direction;

      if(position.x < 0){
        position.x = 0;
      }
      else if (position.x >= VOLUME){
         position.x = VOLUME-1;
      }
    }

    void Curseur::updatePosY(float direction){
      position.y += direction;

      if(position.y < 0){
        position.y = 0;
      }
      else if (position.y >= VOLUME){
         position.y = VOLUME-1;
      }
    }

    void Curseur::updatePosZ(float direction){
      position.z += direction;
      
      if(position.z < 0){
        position.z = 0;
      }
      else if (position.z >= VOLUME){
         position.z = VOLUME-1;
      }
    }

    void Curseur::renderCurseur() {
        glBindVertexArray(vao);
        // Bind l'index buffer
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
            // On dessine nos 36 sommets (3 par triangle * 2 triangles par face * 6 faces)
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        // Unbind
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
       

        glBindVertexArray(0);
    }

    void Curseur::updateVertices()
    {
      glBindBuffer(GL_ARRAY_BUFFER, vbo);

      Vertex3DColor vertices[] = {
                      Vertex3DColor(glm::vec3(0.5f, -0.5f, 0.5f)+ position, color), //0
                      Vertex3DColor(glm::vec3(-0.5f, -0.5f, 0.5f)+ position, color), //1
                      Vertex3DColor(glm::vec3(-0.5f, 0.5f, 0.5f)+ position, color), //2
                      Vertex3DColor(glm::vec3(0.5f, 0.5f, 0.5f)+ position, color), //3
                      Vertex3DColor(glm::vec3(0.5f, -0.5f, -0.5f)+ position, color), //4
                      Vertex3DColor(glm::vec3(-0.5f, -0.5f, -0.5f)+ position, color), //5
                      Vertex3DColor(glm::vec3(-0.5f, 0.5f, -0.5f)+ position, color), //6
                      Vertex3DColor(glm::vec3(0.5f, 0.5f, -0.5f)+ position, color) //7
                            };

      glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
      glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

}







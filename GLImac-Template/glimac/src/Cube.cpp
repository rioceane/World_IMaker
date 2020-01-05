#include <iostream>
#include <cassert>
#include <vector>
#include "glimac/Cube.hpp"


namespace glimac {

    // Constructeur
    Cube::Cube() {
        createBuffer();
    }
    //Destructeur
    Cube::~Cube()
    {
    }
                //    v6----- v5
                //   /|      /|
                //  v1------v0|
                //  | |     | |
                //  | |v7---|-|v4
                //  |/      |/
                //  v2------v3

    float _positionsSommets[] = {
                // v0
                 0.5,  0.5,  0.5,
                // v1
                -0.5,  0.5,  0.5,
                // v2
                -0.5, -0.5,  0.5,
                // v3
                 0.5, -0.5,  0.5,
                // v4
                 0.5, -0.5, -0.5,
                // v5
                 0.5,  0.5, -0.5,
                // v6
                -0.5,  0.5, -0.5,
                // v7
                -0.5, -0.5, -0.5,
    };

    int _indexsSommets[] = {
                // face de devant
                0, 1, 2,  0, 2, 3,
                // face de derrière
                4, 7, 6,  4, 6, 5,
                // face de gauche
                1, 6, 7,  1, 7, 2,
                // face de droite
                0, 3, 4,  0, 4, 5,
                // face de dessous
                2, 7, 4,  2, 4, 3,
                // face de dessus
                0, 5, 6,  0, 6, 1
            };

    int _indexsSommetsWireframe[] = {
        // face de devant
        0, 1,   1, 2,   2, 3,   3, 0,
        // face de gauche
        1, 6,   6, 7,   7, 2,
        // face de droite
        0, 5,   5, 4,   4, 3,
        // face de dessous
        7, 4,
        // face de dessus
        6, 5,
    };

    void Cube::createBuffer()
    {
        //VBO
        glGenBuffers(1,&vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, sizeof(_positionsSommets), _positionsSommets, GL_STATIC_DRAW);
        // on unbind par sécurité
        glBindBuffer(GL_ARRAY_BUFFER, 0);

        // IBO
        //crée le buffer
        glGenBuffers(1, &ibo);
        // on le bind 
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        // on envoie toutes nos données au GPU
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indexsSommets), _indexsSommets, GL_STATIC_DRAW);
        // on unbind
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        // IBO_WIREFRAME
        glGenBuffers(1, &ibo_wireframe);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_wireframe);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indexsSommetsWireframe), _indexsSommetsWireframe, GL_STATIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        // vbPositionsCubesID
        glGenBuffers(1, &vbPositionsCubesID);

        // VAO
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glEnableVertexAttribArray(0); 
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
   
        // Et on rajoute la spécification du nouveau buffer ici :
        glBindBuffer(GL_ARRAY_BUFFER, vbPositionsCubesID);
        glEnableVertexAttribArray(3); 
        glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
        // Avec une petite nouveauté :
        // C'est pour dire à OpenGL qu'il ne doit pas avancer dans le buffer à chaque vertex, mais seulement à chaque nouveau cube qu'il commence à dessiner
        glVertexAttribDivisor(3, 1);
        // On unbind
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

   void Cube::drawCube()
    {       
        glBindVertexArray(vao);
        // Bind l'index buffer
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
            // On dessine nos 36 sommets (3 par triangle * 2 triangles par face * 6 faces)
            glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, cubesPositions.size());
        // Unbind
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
        glBindVertexArray(0);
    }

    void Cube::drawCubeCurseur()
    {       
        glBindVertexArray(vao);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo_wireframe);
            glDrawElementsInstanced(GL_LINES, 24, GL_UNSIGNED_INT, 0, cubesPositions.size());
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        glBindVertexArray(0);
    }

    void Cube::deleteBuffers()
    {
        //Libération des ressources pour le vbo
        glDeleteBuffers(1,&vbo);
        //Libération des ressources pour le vao
        glDeleteVertexArrays(1, &vao);
        //Libération des ressources pour les ibo
        glDeleteBuffers(1,&ibo);
        glDeleteBuffers(1,&ibo_wireframe);
    }

    void Cube::updateGPU(){
        glBindBuffer(GL_ARRAY_BUFFER, vbPositionsCubesID); 
        glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * cubesPositions.size(), cubesPositions.size() > 0 ? &cubesPositions[0] : nullptr, GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    int Cube::findCube(glm::vec3 position){
        for( int k = 0; k < cubesPositions.size(); ++k)
        {
            if( glm::length(position-cubesPositions[k]) < 0.1f){
                return k;
            }
        }
        return -1; 
    }
    
    void Cube::addCube(glm::vec3 position){
        removeCube(position);
        cubesPositions.push_back(position);
        updateGPU();
    }

    void Cube::removeCube(glm::vec3 position){
        int index = findCube(position);
        if( index != -1 ){
            // on place l'élément à retirer à la fin
            int lastIndex = cubesPositions.size() - 1;
            std::swap(cubesPositions[index], cubesPositions[lastIndex]);
            // on retire le dernier élément
            cubesPositions.pop_back();
            updateGPU();
        }
    }

    int Cube::digExtrude(glm::vec3 coord, bool digVSextrude)
    {
        if(findCube(coord) == -1){
            std::cout << "Il n'y a pas de colonne de cubes ici." << std::endl;
            return -1;
        }

        glm::vec3 incrementCoord = glm::vec3(0, 1, 0);
        bool find = false;

        while(!find){   
          if(findCube(coord + incrementCoord) == -1){
            find = true;
          } 
          else {
            coord += incrementCoord;
          }
        }

        if(digVSextrude == 0){
            removeCube(coord);
        } else {
            addCube(coord + incrementCoord);
        }

        return 1;
    }
}
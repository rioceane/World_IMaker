#include <iostream>
#include <cassert>
#include "glimac/Cube.hpp"


namespace glimac {

    // Constructeur
    Cube::Cube() 
    : vbo_c(0), vao_c(0), position_c(glm::vec3(0,0,0)), color_c(glm::vec3(0.0,0.0,0.5)) {}
    //Destructeur
    Cube::~Cube()
    {
    }



    void Cube::createBuffer()
    {
        // Initilisation du VBO
        GLuint vbo_c; 
        glGenBuffers(1, &vbo_c);
        //Binder VAO
        glBindBuffer(GL_ARRAY_BUFFER, vbo_c);

            Vertex3DColor vertices[] = {
                        // face devant
                        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0, 0, 1)),
                        Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0, 0, 1)),

                        //face coté gauche
                        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),
                        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(-0.5, 0.5, -1.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),

                        //face coté droite
                        Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),
                        Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),

                        //face dessous
                        Vertex3DColor(glm::vec3(-0.5, -0.5, 0.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),
                        Vertex3DColor(glm::vec3(0.5, -0.5, 0.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(0, 0, 1)),

                        //face dessus
                        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(0.5, 0.5, 0.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1)),
                        Vertex3DColor(glm::vec3(-0.5, 0.5, 0.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(-0.5, 0.5, -1.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1)),

                        //face derrière
                        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(-0.5, 0.5, -1.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1)),
                        Vertex3DColor(glm::vec3(-0.5, -0.5, -1.0), glm::vec3(1, 0, 0)),
                        Vertex3DColor(glm::vec3(0.5, -0.5, -1.0), glm::vec3(0, 1, 0)),
                        Vertex3DColor(glm::vec3(0.5, 0.5, -1.0), glm::vec3(0, 0, 1))
                    };

            glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 
            
        glBindBuffer(GL_ARRAY_BUFFER, 0);


        // Initilisation du VAO
        GLuint vao_c;
        glGenVertexArrays(1, &vao_c);
        //Binder VAO
        glBindVertexArray(vao_c);

            const GLuint VERTEX_ATTR_POSITION = 3;
            const GLuint VERTEX_ATTR_COULEUR = 8;
            glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
            glEnableVertexAttribArray(VERTEX_ATTR_COULEUR);

        glBindBuffer(GL_ARRAY_BUFFER, vbo_c);

            glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*) (offsetof(Vertex3DColor, m_position)));
            glVertexAttribPointer(VERTEX_ATTR_COULEUR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*) (offsetof(Vertex3DColor, m_color)));

        glBindBuffer(GL_ARRAY_BUFFER, 0);

        //Débinder VAO 
        glBindVertexArray(0);
    }


    void Cube::drawCube()
    {       
        glBindVertexArray(vao_c);
            glDrawArrays(GL_TRIANGLES, 0, 6);
        //Débinder VAO 
        glBindVertexArray(0);
    }


    void Cube::deleteBuffers()
    {
        //Libération des ressources pour le vbo
        glDeleteBuffers(1,&vbo_c);
        //Libération des ressources pour le vao
        glDeleteVertexArrays(1, &vao_c);
    }
}
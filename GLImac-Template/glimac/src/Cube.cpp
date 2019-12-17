#include <iostream>
#include <cassert>
#include "glimac/Cube.hpp"

/*
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

*/

namespace glimac {

    // Constructeur
    Cube::Cube() 
    : vbo(0), vao(0), position(glm::vec3(0,0,0)), color(glm::vec3(0.0,0.0,0.5)) {}
   
    //Destructeur
    Cube::~Cube()
    {
    }


    void Cube::createBuffer()
    {
        GLuint vbo; 
        glGenBuffers(1,&vbo);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);


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
                // face de devant : v0, v1, v2 puis v0, v2, v3
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

        glBufferData(GL_ARRAY_BUFFER, sizeof(_positionsSommets), _positionsSommets, GL_STATIC_DRAW);
        // on unbind, ce n'est pas nécessaire mais c'est par sécurité, ça rend les choses plus faciles à débuguer
        glBindBuffer(GL_ARRAY_BUFFER, 0);


        GLuint ibo;
        // on crée le buffer
        glGenBuffers(1, &ibo);
        // on le bind pour que la ligne suivante s'applique bien à ce buffer ci
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
        // on envoie toutes nos données au GPU
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indexsSommets), _indexsSommets, GL_STATIC_DRAW);
        // on unbind, ce n'est pas nécessaire mais c'est par sécurité, ça rend les choses plus faciles à débuguer
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


        GLuint vao;
        // On crée et on bind le vertex array
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);
        // On bind notre vertex buffer de tout à l'heure
        // Ceci aura pour effet de l'attacher au vertex array actuellement bindé
        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        // On choisit un petit nom pour notre attribut, pour l'instant on n'a que des positions (les couleurs viendront plus tard) et on va lui donner le numéro 0.
        glEnableVertexAttribArray(0); 
        // On dit à OpenGL que l'attribut 0 contient trois float
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
        // On unbind par sécurité
        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }



   void Cube::drawCube()
    {       
        glBindVertexArray(vao);
        // Bind l'index buffer
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
            // On dessine nos 36 sommets (3 par triangle * 2 triangles par face * 6 faces)
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        // Unbind
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
       

        glBindVertexArray(0);
    }


    void Cube::deleteBuffers()
    {
        //Libération des ressources pour le vbo
        glDeleteBuffers(1,&vbo);
        //Libération des ressources pour le vao
        glDeleteVertexArrays(1, &vao);
    }


}

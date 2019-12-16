#include <iostream>
#include <cassert>
#include "glimac/Cube.hpp"


namespace glimac {

    void Cube::createBuffer(){

        GLuint vbo; 
        glGenBuffers(1,&vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glBufferData(GL_ARRAY_BUFFER, myCube.getVertexCount() * sizeof(ShapeVertex), myCube.getDataPointer(), GL_STATIC_DRAW);

        glBindBuffer(GL_ARRAY_BUFFER, 0);



        GLuint vao;
        glGenVertexArrays(1, &vao);

        //Binder VAO
        glBindVertexArray(vao);

            const GLuint VERTEX_ATTR_POSITION = 0;
            const GLuint VERTEX_ATTR_NORMAL = 1;
             const GLuint VERTEX_ATTR_TEXTURE = 2;
            //const GLuint VERTEX_ATTR_COULEUR = 1;
            glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
            //glEnableVertexAttribArray(VERTEX_ATTR_COULEUR);
            glEnableVertexAttribArray(VERTEX_ATTR_NORMAL);
            glEnableVertexAttribArray(VERTEX_ATTR_TEXTURE);

            glBindBuffer(GL_ARRAY_BUFFER, vbo);

                glVertexAttribPointer(VERTEX_ATTR_POSITION, 2, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (const GLvoid*) (0*sizeof(GLfloat)));
                //glVertexAttribPointer(VERTEX_ATTR_COULEUR, 3, GL_FLOAT, GL_FALSE, 5*sizeof(GLfloat), (const GLvoid*) (0*sizeof(GLfloat)));
                 glVertexAttribPointer(VERTEX_ATTR_NORMAL, 3, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)(offsetof(ShapeVertex, normal)));
                 glVertexAttribPointer(VERTEX_ATTR_TEXTURE, 2, GL_FLOAT, GL_FALSE, sizeof(ShapeVertex), (const GLvoid*)(offsetof(ShapeVertex, texCoords)));

            glBindBuffer(GL_ARRAY_BUFFER, 0);

        //Débinder VAO 
        glBindVertexArray(0);

    }








    

}
#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <glimac/Cube.hpp>
#include <glimac/Camera.hpp>
#include <glimac/common.hpp>
#include <iostream>
#include <vector>
#include <cstddef>



using namespace glimac;


int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "GLImac");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/triangle.vs.glsl", applicationPath.dirPath() + "shaders/triangle.fs.glsl");
    program.use();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    Cube c;

    c.createBuffer();



    /*
    GLuint vbo; 
    glGenBuffers(1,&vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);

        //Le tableau de vertex
        //GLfloat vertices[]= {-0.5f, -0.5f, 1.f, 0.f, 0.f, 0.5f, -0.5f, 0.f, 1.f, 0.f, 0.0f, 0.5f, 0.f, 0.f, 1.f};

        //Utilisation de notre structure à la place des floats
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


        //sizeof(vertices) ne marche que pour les tableaux statiques
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW); 
        
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint vao;
    glGenVertexArrays(1, &vao);

    //Binder VAO
    glBindVertexArray(vao);

        const GLuint VERTEX_ATTR_POSITION = 3;
        const GLuint VERTEX_ATTR_COULEUR = 8;
        glEnableVertexAttribArray(VERTEX_ATTR_POSITION);
        glEnableVertexAttribArray(VERTEX_ATTR_COULEUR);

        glBindBuffer(GL_ARRAY_BUFFER, vbo);

            glVertexAttribPointer(VERTEX_ATTR_POSITION, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*) (offsetof(Vertex3DColor, m_position)));
            glVertexAttribPointer(VERTEX_ATTR_COULEUR, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex3DColor), (const GLvoid*) (offsetof(Vertex3DColor, m_color)));

        glBindBuffer(GL_ARRAY_BUFFER, 0);

    //Débinder VAO 
    glBindVertexArray(0);

    */

    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }


        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT);
        
        c.drawCube();

        // Update the display
        windowManager.swapBuffers();
    }

    c.deleteBuffers();

    return EXIT_SUCCESS;
}

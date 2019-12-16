#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/Program.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/glm.hpp>
#include <glimac/Image.hpp>
#include <glimac/Cube.hpp>
#include <glimac/Camera.hpp>
#include <iostream>
#include <vector>



using namespace glimac;

struct MainProgram {
    Program m_Program;

    GLuint uMVPMatrix;
    GLuint uMVMatrix;
    GLuint uNormalMatrix;
    GLuint uTexture;


    MainProgram(const FilePath& applicationPath):
        m_Program(loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl",
                                applicationPath.dirPath() + "shaders/3D.fs.glsl")) {
        uMVPMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVPMatrix");
        uMVMatrix = glGetUniformLocation(m_Program.getGLId(), "uMVMatrix");
        uNormalMatrix = glGetUniformLocation(m_Program.getGLId(), "uNormalMatrix");
        uTexture = glGetUniformLocation(m_Program.getGLId(), "uTexture");
    }
};






int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 600, "Word IMaker");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    Camera cam; //initialise la caméra

    FilePath applicationPath(argv[0]);
    MainProgram mainProgram(applicationPath);
    //Program program = loadProgram(applicationPath.dirPath() + "shaders/color2D.vs.glsl", applicationPath.dirPath() + "shaders/color2D.fs.glsl");
    //program.use();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    Cube myCube;

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



    glEnable(GL_DEPTH_TEST);

    glm::mat4 ProjMatrix = glm::perspective(glm::radians(70.f), 600.f/600.f, 0.1f, 100.f);

    glm::ivec2 mouse;

    bool mouseDown = false;




    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }

            switch(e.type) {
                case SDL_KEYDOWN:
                    if(e.key.keysym.sym == SDLK_UP) cam.rotateUp(1);
                    if(e.key.keysym.sym == SDLK_DOWN) cam.rotateUp(-1);
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    mouseDown = true;
                    mouse = windowManager.getMousePosition();
                    break;

                case SDL_MOUSEBUTTONUP:
                    mouseDown = false;
                    break;

                case SDL_MOUSEMOTION:
                    if(mouseDown) {
                        glm::ivec2 offsetMouse = windowManager.getMousePosition() - mouse;
                        mouse = windowManager.getMousePosition();
                        cam.rotateUp(offsetMouse.y/2.f);
                        cam.rotateLeft(offsetMouse.x/2.f);
                    }
                    break;
        }
    }

        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glm::mat4 viewMatrix = cam.getViewMatrix();

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        glBindVertexArray(vao);

            mainProgram.m_Program.use();

                glm::mat4 cubeMVMatrix = viewMatrix;

                //Send matrix to the CG
                glUniformMatrix4fv(mainProgram.uMVMatrix, 1, GL_FALSE, glm::value_ptr(cubeMVMatrix));
                glUniformMatrix4fv(mainProgram.uMVPMatrix, 1, GL_FALSE, glm::value_ptr(ProjMatrix * cubeMVMatrix));
                glUniformMatrix4fv(mainProgram.uNormalMatrix, 1, GL_FALSE, glm::value_ptr(glm::transpose(glm::inverse(cubeMVMatrix))));

                glDrawArrays(GL_TRIANGLES, 0, myCube.getVertexCount()); //cube

        //Débinder VAO 
        glBindVertexArray(0);

        // Update the display
        windowManager.swapBuffers();
    }
    
    return EXIT_SUCCESS;
}
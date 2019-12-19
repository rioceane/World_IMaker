#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include "glimac/Program.hpp"
#include "glimac/FilePath.hpp"
#include "glimac/glm.hpp"
#include "glimac/Image.hpp"
#include "glimac/Cube.hpp"
#include "glimac/FreeflyCamera.hpp"
#include "glimac/common.hpp"
#include "glimac/Curseur.hpp"
#include <glm/gtc/matrix_transform.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"
#include <imgui/imgui_internal.h>

#include <glm/glm.hpp> // la base de glm
#include <iostream>
#include <vector>
#include <cstddef>
//#include "SDL.h"

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 800;

    SDLWindowManager windowManager(WINDOW_WIDTH, WINDOW_HEIGHT, "Word IMaker");

    // couleur fenêtre
    glClearColor(200.0 / 255, 200.0 / 255, 200.0 / 255, 1);

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    //Overlay overlay;

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/3D.fs.glsl");
    program.use();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    //creation caméra
    FreeflyCamera camera;

    GLint uMVPMatrix = glGetUniformLocation(program.getGLId(),"uMVPMatrix");
    GLint uMVMatrix = glGetUniformLocation(program.getGLId(),"uMVMatrix");
    GLint uNormalMatrix = glGetUniformLocation(program.getGLId(),"uNormalMatrix");

    //création cube
    Cube c;
    c.createBuffer();

    //creation du curseur
    Curseur curseur;

    glEnable(GL_DEPTH_TEST);


    //Matrices de projection
    glm::mat4 ProjMatrix = glm::perspective(
        glm::radians(70.f),
        800.f/600.f,
        0.1f,
        100.f);


    // Application loop:
    bool done = false;
    while(!done) {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }

            if(e.type == SDL_KEYDOWN){
                float speed = 1.f;
                switch(e.key.keysym.sym){
                    /*Z key to move forward*/
                    case SDLK_z: camera.moveFront(speed);
                    break;
                    /*S key to move backward*/
                    case SDLK_s: camera.moveFront(-speed);
                    break;
                    /*Q key to move left*/
                    case SDLK_q: camera.moveLeft(speed);
                    break;
                    /*D key to move right*/
                    case SDLK_d: camera.moveLeft(-speed);
                    break;

                    default: break;
                }
            }    

            if(e.type== SDL_MOUSEMOTION){
                float speed = 0.1f;
                  camera.rotateFront( float(-e.motion.xrel) * speed);
                  camera.rotateLeft( float(e.motion.yrel) * speed);
                
            }
        }


        /*********************************
         * HERE SHOULD COME THE RENDERING CODE *
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // changement matrice (caméra)
        glm::mat4 MVMatrix = camera.getViewMatrix();
        glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
        glUniformMatrix4fv(uMVPMatrix,1,GL_FALSE,glm::value_ptr(ProjMatrix*MVMatrix));
        glUniformMatrix4fv(uMVMatrix,1,GL_FALSE,glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix,1,GL_FALSE,glm::value_ptr(NormalMatrix));

        // dessiner le cube
        c.drawCube();

        //curseur.drawCurseur(curseur);

        // Update the display
        windowManager.swapBuffers();
    }

    //liberer les buffers
    c.deleteBuffers();
    //curseur.liberateCurseur(curseur);
    //SDL_GL_DeleteContext(glcontext); 

    return EXIT_SUCCESS;
}
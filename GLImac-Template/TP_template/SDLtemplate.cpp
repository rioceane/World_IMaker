#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include "glimac/Program.hpp"
#include "glimac/FilePath.hpp"
#include "glimac/glm.hpp"
#include "glimac/Image.hpp"
#include "glimac/Cube.hpp"
#include "glimac/FreeflyCamera.hpp"
#include "glimac/Scene.hpp"
#include "glimac/common.hpp"
#include "glimac/Curseur.hpp"
#include <glm/gtc/matrix_transform.hpp>

#include <glm/glm.hpp> // la base de glm
#include <iostream>
#include <cstddef>
//#include "SDL.h"

using namespace glimac;

int main(int argc, char** argv) {

    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 800;
    SDLWindowManager windowManager(WINDOW_WIDTH, WINDOW_HEIGHT, "Word IMaker");

    Scene scene;
    ImGui_ImplSDL2_InitForOpenGL(windowManager.window, windowManager.glContext);

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

    //Lumière (cyrielle)
    GLint uLumiereDirectionelle = glGetUniformLocation(program.getGLId(),"uLumieredirection");
    GLint uLumierePonctuelle = glGetUniformLocation(program.getGLId(),"uLumierepoint");
    GLint uCouleurcube = glGetUniformLocation(program.getGLId(),"uCouleur");

    //création cube
    Cube cube;
    // Etat initial
    cube.addCube(glm::vec3(0.,0.,0.));
    cube.addCube(glm::vec3(-1.,0.,0.));
    cube.addCube(glm::vec3(1.,0.,0.));

    //creation du curseur
    Curseur curseur;
    int axe = 0;

    glEnable(GL_DEPTH_TEST);

    //Matrices de projection
    glm::mat4 ProjMatrix = glm::perspective(
        glm::radians(70.f),
        800.f/600.f,
        0.1f,
        100.f);

    //Lumières
    glm::vec3 LumiereDirectionelle=glm::normalize(glm::vec3(0.0,-0.3,-0.5));
    glm::vec3 LumierePonctuelle=glm::normalize(glm::vec3(-10,-10,-10));
    glm::vec3 CouleurCube=glm::vec3(1,1,1);


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
                    /*G key to move left*/
                    case SDLK_g: camera.moveLeft(speed);
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
            // AXE : x=0 y=1 z=2
            if (e.key.keysym.scancode == SDL_SCANCODE_X) {
                axe = 0;
            } else if (e.key.keysym.scancode == SDL_SCANCODE_Y) {
                 axe = 1;
            } else if (e.key.keysym.scancode == SDL_SCANCODE_W) { // Code W car qwerty
                axe = 2; 
            }

            if (e.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
                curseur.changeCoord(axe, 1);
            } 
            else if (e.key.keysym.scancode == SDL_SCANCODE_LEFT){
                curseur.changeCoord(axe, -1);
            }
            if (e.key.keysym.scancode == SDL_SCANCODE_RETURN) {
                cube.addCube(curseur.coord);
            }
            else if (e.key.keysym.scancode == SDL_SCANCODE_BACKSPACE) {
                cube.removeCube(curseur.coord);
            }
        }


        /*********************************
         * HERE SHOULD COME THE RENDERING CODE *
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // couleur cube + lumière 
        glUniform3f(uCouleurcube,CouleurCube.x,CouleurCube.y,CouleurCube.z);
        
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(windowManager.window);
        ImGui::NewFrame();

        ImGui::Begin("Hello");
        ImGui::Text("Bonjour et bienvenue");
        ImGui::SliderFloat3("Direction lumière", (float*)&LumiereDirectionelle, -1, 1);
        ImGui::SliderFloat3("Point lumière", (float*)&LumierePonctuelle, -10, 10);
        ImGui::Text("Color button only:");

        if (ImGui::Button("Ambiance de jour")){
            LumiereDirectionelle=glm::vec3(0.0,-0.3,-0.5);
            LumierePonctuelle=glm::vec3(-10,-10,-10);
            glClearColor(200.0 / 255, 200.0 / 255, 255.0 / 255, 1);
        }

        if (ImGui::Button("Ambiance de nuit")){
            LumiereDirectionelle=glm::vec3(0.0,0.0,0.0);
            LumierePonctuelle=glm::vec3(1,-0.2,1);
            glClearColor(15.0 /255, 15.0 / 255, 15.0 / 255, 1);
        }
        if (ImGui::Button("Supprimer les lumières")){
            LumiereDirectionelle=glm::vec3(0.0,0.0,0.0);
            LumierePonctuelle=glm::vec3(0,0,0);
        }
        if (ImGui::Button("Bleu")){
            CouleurCube=glm::vec3(15.0/255, 100.0/255, 232.0/255);
        }
        if (ImGui::Button("Rouge")){
            CouleurCube=glm::vec3(1,0,0);
        }
        if (ImGui::Button("Vert")){
            CouleurCube=glm::vec3(0,1,0);
        }
        if (ImGui::Button("Orange")){
            CouleurCube=glm::vec3(1, 0.4, 0.1);
        }
        if (ImGui::Button("Rose")){
            CouleurCube=glm::vec3(1, 0, 0.5);
        }
        if (ImGui::Button("Violet")){
            CouleurCube=glm::vec3(0.5, 0.1, 0.9);
        }
        if (ImGui::Button("Jaune")){
            CouleurCube=glm::vec3(1.0, 0.9, 0.0);
        }
        if (ImGui::Button("Blanc")){
            CouleurCube=glm::vec3(1, 1, 1);
        }
    
        ImGui::End();

        glUniform3f(uLumiereDirectionelle,LumiereDirectionelle.x,LumiereDirectionelle.y,LumiereDirectionelle.z);
        glUniform3f(uLumierePonctuelle,LumierePonctuelle.x,LumierePonctuelle.y,LumierePonctuelle.z);
        
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // changement matrice (caméra)
        glm::mat4 MVMatrix = camera.getViewMatrix();
        glm::mat4 NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
        glUniformMatrix4fv(uMVPMatrix,1,GL_FALSE,glm::value_ptr(ProjMatrix*MVMatrix));
        glUniformMatrix4fv(uMVMatrix,1,GL_FALSE,glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix,1,GL_FALSE,glm::value_ptr(NormalMatrix));

        // dessiner le curseur
        curseur.drawCurseur();

        // dessiner le cube
        cube.drawCube();

        // Update the display
        windowManager.swapBuffers();
    }

    //liberer les buffers
    cube.deleteBuffers();
    SDL_GL_DeleteContext(windowManager.glContext);
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    return EXIT_SUCCESS;
}
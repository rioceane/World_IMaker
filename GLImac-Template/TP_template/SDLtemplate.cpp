#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include "glimac/Program.hpp"
#include "glimac/FilePath.hpp"
#include "glimac/glm.hpp"
#include "glimac/Image.hpp"
#include "glimac/Cube.hpp"
#include "glimac/FreeflyCamera.hpp"
#include "glimac/common.hpp"
#include "glimac/Overlay.hpp"
#include <glm/gtc/matrix_transform.hpp>

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"
#include <imgui/imgui_internal.h>

#include <glm/glm.hpp> // la base de glm
#include <iostream>
#include <vector>
#include <cstddef>
#include "SDL.h"

using namespace glimac;

int main(int argc, char** argv) {
    // Initialize SDL and open a window
    const int WINDOW_WIDTH = 800;
    const int WINDOW_HEIGHT = 800;

    SDLWindowManager windowManager(WINDOW_WIDTH, WINDOW_HEIGHT, "Word IMaker");

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


    //INIT OVERLAY
    SDL_Window* window;
    SDL_GLContext* glcontext = SDL_GL_CreateContext(window);
    //ImGuiContext* cl_context = SDL_CreateCond(window);
    
    //SDL_cond *cond;
    //cond = SDL_CreateCond();


    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    // Setup Platform/Renderer bindings
    ImGui_ImplSDL2_InitForOpenGL(window, glcontext);
    ImGui_ImplOpenGL3_Init("#version 330 core");
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();


    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/
    Cube c;
    c.createBuffer();

    // Créer la matrice
    //glm::mat4 matriceDeProjection = glm::infinitePerspective(1.0f, 1, 0.1f); // 1 = rapport largeur/hauteur de la fenetre
    // L'envoyer au shader (une fois de plus la ligne suivante n'est valable qu'avec notre template)
   // monShader.setUniformMat4f("u_projMat", matriceDeProjection);

    //Freeflycamera camera;


    //application loop
    bool done = false;
    while(!done) {
        SDL_Event e;
        while (windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }


        /*********************************
         * HERE SHOULD COME THE RENDERING CODE *
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        c.drawCube();

        // Update the display
        windowManager.swapBuffers();
    }

    
    c.deleteBuffers();
    SDL_GL_DeleteContext(glcontext);
    //SDL_GL_UpdateRects(cond);  

    return EXIT_SUCCESS;
}
#ifndef GLIMAC_Overlay
#define GLIMAC_Overlay

#include <iostream>
#include <string>
#include <GL/glew.h>
#include "imgui/imgui.h"
#include "imgui/imgui_impl_opengl3.h"
#include "imgui/imgui_impl_sdl.h"
#include "glm.hpp"

namespace glimac
{

    class Overlay
    {
        public:
            // Constructor
            Overlay(){};
            //Destructor
            ~Overlay();
            void beginFrame(SDL_Window* window) const;
            void drawOverlay(int &action) const;
            void endFrame(SDL_Window* window) const;
            void clean(SDL_Window* window) const;
    };
}

#endif //GLIMAC_Overlay

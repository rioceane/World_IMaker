#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include "glimac/glm.hpp"
#include "glimac/common.hpp"
#include "Cube.hpp"
#include "glimac/RadialBasisFunction.hpp"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_sdl.h"
#include "imgui/imgui_impl_opengl3.h"
#include <imgui/imgui_internal.h>
#include <eigen3/Eigen/Dense>

#include <glm/glm.hpp> 
#include <iostream>
#include <cstddef>

namespace glimac
{
    class Scene
    {
        public:
            Scene();
            ~Scene();
            int createScene();
            void initializeImgui();
            void RadialBasisFunctionScene(Cube* cube);
    };
};
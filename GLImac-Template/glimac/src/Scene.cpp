#include "glimac/Scene.hpp"    

namespace glimac {
    // Constructeur
    Scene::Scene() {
        createScene();
        initializeImgui();
    }
    //Destructeur
    Scene::~Scene()
    {
    }

    int Scene::createScene(){
	    // couleur fenêtre
	    glClearColor(200.0 / 255, 200.0 / 255, 255.0 / 255, 1);
	    // Initialize glew for OpenGL3+ support
	    GLenum glewInitError = glewInit();
	    if(GLEW_OK != glewInitError) {
	        std::cerr << glewGetErrorString(glewInitError) << std::endl;
	        return EXIT_FAILURE;
	    }

	    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
	    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;
    }

	void Scene::initializeImgui(){
	    IMGUI_CHECKVERSION();
	    ImGui::CreateContext();
	    ImGuiIO &io = ImGui::GetIO();(void)io;
	    // Setup Platform/Renderer bindings#
	    #if __APPLE__
	        const char* glslVersion = "#version 330 core";
	    #else
	        const char* glslVersion = "#version 330";
	    #endif
	    ImGui_ImplOpenGL3_Init(glslVersion);
	    // Setup Dear ImGui style
	    ImGui::StyleColorsDark();
	}
}
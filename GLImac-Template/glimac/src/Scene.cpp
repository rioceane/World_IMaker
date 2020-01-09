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

	void Scene::RadialBasisFunctionScene(Cube* cube){
	 	const int nbPoint = 1;
        Eigen::MatrixXd world = Eigen::MatrixXd::Zero(21,21);
        Eigen::MatrixXf ptControl(nbPoint, 2);
        ptControl << 0,0;
        Eigen::VectorXf value(nbPoint);
        value << 15;

        world = generateWorld(ptControl, value);

        for (int x = 0; x < 11; x++){
            for (int z = 0; z < 11; z++){
                for (int y = -10; y < world(x,z); y++){
                    cube->addCube(glm::vec3(x-(10/2),y,z-(10/2)));
                }
            }
        }
	}
}
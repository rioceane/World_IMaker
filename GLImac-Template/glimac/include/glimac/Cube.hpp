#pragma once

#include <vector>
#include <glimac/common.hpp>
#include <glimac/glm.hpp> 
#include <glimac/Program.hpp>
#include <GL/glew.h>
//#include "glimac/FreeflyCamera.hpp"


namespace glimac
{

	class Cube
	{
		private:
			GLuint vao;
			GLuint vbo;
			GLuint ibo;
			glm::vec3 position; 
			glm::vec3 color; 
	
		public:
			GLuint uMVPLoc; //Location
			GLuint uMVLoc;
			GLuint uNormalLoc;	

			Cube();
			~Cube();

			void createBuffer();
			void deleteBuffers();
			void drawCube();
	};
	
};


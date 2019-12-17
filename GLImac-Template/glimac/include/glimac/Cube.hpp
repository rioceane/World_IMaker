#pragma once

#include <vector>
#include <glimac/common.hpp>

#include <glimac/glm.hpp> 
#include <glimac/Program.hpp>
#include <GL/glew.h>
//#include <glimac/Camera.hpp>

/*
namespace glimac
{

	class Cube
	{
		private:
			GLuint vao_c;
			GLuint vbo_c;
			glm::vec3 position_c; 
			glm::vec3 color_c; 
			//FreeflyCamera camera;	
	
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
*/


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




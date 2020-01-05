#pragma once
#include <vector>
#include "glimac/common.hpp"
#include "glimac/glm.hpp" 
#include "glimac/Program.hpp"
#include <GL/glew.h>

namespace glimac
{
	class Cube
	{
		protected:
			GLuint vao;
			GLuint vbo;
			GLuint ibo;
			GLuint ibo_wireframe;
			GLuint vbPositionsCubesID;
			glm::vec3 position; 
			std::vector<glm::vec3> cubesPositions;
	
		public:
			Cube();
			~Cube();

			void createBuffer();
			void deleteBuffers();
			void drawCube();
			void drawCubeCurseur();
			void updateGPU();
			void addCube(glm::vec3 position);
			int findCube(glm::vec3 position);
			void removeCube(glm::vec3 position);
			int digExtrude(glm::vec3 coord, bool digVSextrude);
	};
};
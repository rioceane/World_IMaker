#pragma once

#include <vector>
#include "common.hpp"

#include <glimac/glm.hpp> 
#include <glimac/Program.hpp>
#include <GL/glew.h>
#include <glimac/Camera.hpp>

namespace glimac
{

	//actually, the position of the cube is due to its vertex
	class Cube
	{
		private:
			GLuint vao_c;
			GLuint vbo_c;
			glm::vec3 position_c; 
			glm::vec3 color_c; 
			Camera cam;	
	
		public:

			GLuint uMVPLoc; //Location
			GLuint uMVLoc;
			GLuint uNormalLoc;	
		  	Cube();
    		Cube(glm::vec3 position, glm::vec3 color);
			~Cube();
			/*inline glm::vec3 getPosition(){ return m_position; };
			inline glm::vec3 getColor(){ return m_color; };
			inline GLuint getVAO(){ return m_vao; };
			inline GLuint getIBO(){ return m_ibo; };
			inline float setPositionX(float positionX){return m_position.x = positionX;};
			inline float setPositionY(float positionY){return m_position.y = positionY;};
			inline float setPositionZ(float positionZ){return m_position.z = positionZ;};
			void create_uniform_matrices(Program &program);
			void initBuffer();
			void draw();
			*/
	};
};





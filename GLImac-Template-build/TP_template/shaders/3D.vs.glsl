#version 330

layout (location = 0) in vec3 aPositionSommet; 
//uniform mat4 u_projMat = glm::infinitePerspective(1.0f, 1, 0.1f);

void main() {
	// gl_Position est une variable d'OpenGL que le vertexShader doit remplir pour expliquer où va le sommet
	//gl_Position = u_projMat*vec4(aPositionSommet, 1.0);
	gl_Position = vec4(aPositionSommet, 1.0);
}

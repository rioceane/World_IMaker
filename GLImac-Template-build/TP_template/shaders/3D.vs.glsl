#version 330

layout (location = 0) in vec3 aPositionSommet; 

void main() {
	// gl_Position est une variable d'OpenGL que le vertexShader doit remplir pour expliquer où va le sommet
	gl_Position = vec4(aPositionSommet, 1.0);
}

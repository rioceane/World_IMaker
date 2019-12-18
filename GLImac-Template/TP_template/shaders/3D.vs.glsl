/*#version 330

layout (location = 0) in vec3 aPositionSommet; 
//uniform mat4 u_projMat = glm::infinitePerspective(1.0f, 1, 0.1f);

void main() {
	// gl_Position est une variable d'OpenGL que le vertexShader doit remplir pour expliquer où va le sommet
	//gl_Position = u_projMat*vec4(aPositionSommet, 1.0);
	gl_Position = vec4(aPositionSommet, 1.0);
}
*/

#version 330

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aTexCoord;

out vec3 vPosition;
out vec3 vNormale;
out vec2 vtexCoords;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

void main() {
	vPosition = vec3(uMVMatrix*vec4(aVertexPosition, 1));
	vNormale = vec3(uNormalMatrix*vec4(aVertexNormal, 0));
	vtexCoords = aTexCoord;

    gl_Position = uMVPMatrix * vec4(aVertexPosition, 1);
}
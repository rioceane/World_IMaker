#version 330

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aTexCoord;
//ajouter plusieurs cubes
layout(location = 3) in vec3 aPositionSommet;

out vec3 vPosition;
out vec3 vNormale;
out vec2 vtexCoords;

uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

//cyrielle
uniform mat4 uModelMatrix;

void main() {
	//calculs des valeurs de sortie
	vPosition = vec3(uMVMatrix*vec4(aVertexPosition, 1));
	vNormale = vec3(uNormalMatrix*vec4(aVertexNormal, 0));
	vtexCoords = aTexCoord;
	//calcul de la position projetée
    gl_Position = uMVPMatrix * vec4(aPositionSommet + aVertexPosition, 1);
}
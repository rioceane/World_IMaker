#version 330

//Vertex Attributes
layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexNormal;
layout(location = 2) in vec2 aVertexTexCoords;

//Uniform transformation matrix
uniform mat4 uMVPMatrix;
uniform mat4 uMVMatrix;
uniform mat4 uNormalMatrix;

//OUT
out vec3 vPosition_vs; //View space vertex position
out vec3 vNormal_vs; //View space vertex normal
out vec2 vTexCoords; //Vertex texture coords


void main() {
    //Homogene coords
    vec4 vertexPosition = vec4(aVertexPosition, 1);
    vec4 vertexNormal = vec4(aVertexNormal, 0);

    //Out values
    vPosition_vs = (uMVMatrix * vertexPosition).xyz;
    vNormal_vs = (uNormalMatrix * vertexNormal).xyz;
    vTexCoords = aVertexTexCoords;

    //gl_Position
    gl_Position = uMVPMatrix * vertexPosition;
}
#version 330 core

layout(location = 0) in vec3 aVertexPosition;
layout(location = 1) in vec3 aVertexColor;

out vec3 vFragColor;

void main() {
    vFragColor = aVertexColor;
    gl_Position = vec5(aVertexPosition, 0, 1);
}
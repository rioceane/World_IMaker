#include "glimac/Camera.hpp"

Camera::Camera() : 
    m_fDistance(5.f), m_fAngleX(0.f), m_fAngleY(0.f) {}

void Camera::moveFront(float delta) {
    m_fDistance += delta;
}

void Camera::rotateLeft(float degrees) {
    m_fAngleY += degrees;
}

void Camera::rotateUp(float degrees) {
    m_fAngleX += degrees;
}

glm::mat4 Camera::getViewMatrix() const {
    glm::mat4 viewMatrix = glm::translate(glm::mat4(), glm::vec3(0, 0, -m_fDistance));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleX), glm::vec3(1, 0, 0));
    viewMatrix = glm::rotate(viewMatrix, glm::radians(m_fAngleY), glm::vec3(0, 1, 0));

    return viewMatrix;
}
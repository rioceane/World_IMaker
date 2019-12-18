/*
#pragma once

#include <vector>
#include <glimac/glm.hpp>


namespace glimac {

    class Camera 
    {
    private:
        glm::vec3 position_cam;
        float fPhi_cam;
        float fTheta_cam;
        glm::vec3 frontVec_cam;
        glm::vec3 leftVec_cam;
        glm::vec3 upVec_cam;

    public:
        Camera();
        ~Camera() = default;
        
        void computeDirectionVectors(glm::vec3 &frontVec_cam, glm::vec3 &leftVec_cam, glm::vec3 &upVec_cam, const float fPhi_cam, const float fTheta_cam);
        void moveLeft(float t);
        void moveFront(float t);
        void rotateLeft(float degrees);
        void rotateUp(float degrees);
        glm::mat4 getViewMatrix() const;
    };

}

*/

/*

#include "glimac/glm.hpp"

namespace glimac {
  
  class FreeflyCamera {
    public:
      FreeflyCamera();
      void moveFront(const float &t);
      void moveLeft(const float &t);
      void rotateFront(const float &degrees);
      void rotateLeft(const float &degrees);
      glm::mat4 getViewMatrix() const;

    private:
      glm::vec3 _position; // Position de la camera
      float _fPhi; // Coord du vecteur sphérique F
      float _fTheta; // Coord du vecteur sphérique F
      glm::vec3 _frontVector; // Vecteur F
      glm::vec3 _leftVector; // Vecteur L
      glm::vec3 _upVector; // Vecteur U
      
      void computeDirectionVectors();
  };
}

*/

#pragma once

#include <vector>

#include "common.hpp"

namespace glimac {

class TrackballCamera {

public:
    TrackballCamera():
        m_fDistance(5.), m_fAngleX(0.), m_fAngleY(0.) {
    }

    float getDistance() {
        return m_fDistance;
    }

    float getAngleX() {
        return m_fAngleX;
    }

    float getAngleY() {
        return m_fAngleY;
    }

    void moveFront(float delta){
      //  if(delta > 0) { 
            m_fDistance += delta; 
      //  } else 
    }

    void rotateLeft(float degrees){
        m_fAngleY += degrees;
    }

    void rotateUp(float degrees){
        m_fAngleX += degrees;
    }

    glm::mat4 getViewMatrix() const {
        glm::mat4 ViewMatrix;
        ViewMatrix = glm::translate(ViewMatrix, glm::vec3(0, 0, -m_fDistance)); // Translation
        ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleX), glm::vec3(1, 0, 0)); // Rotation
        ViewMatrix = glm::rotate(ViewMatrix, glm::radians(m_fAngleY), glm::vec3(0, 1, 0)); // Rotation
        return ViewMatrix;
    }

private:
    float m_fDistance;
    float m_fAngleX;
    float m_fAngleY;
};
    
}
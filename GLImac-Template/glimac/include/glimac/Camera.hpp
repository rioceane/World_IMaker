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
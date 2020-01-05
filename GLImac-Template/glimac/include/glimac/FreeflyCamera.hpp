#include "glimac/glm.hpp"
#include <cmath>
#include <glm/glm.hpp> 
#include <iostream>

namespace glimac {
  
  class FreeflyCamera {

    public:
      FreeflyCamera();
      ~FreeflyCamera();
      void moveFront(const float &t);
      void moveLeft(const float &t);
      void rotateFront(const float &degrees);
      void rotateLeft(const float &degrees);
      glm::mat4 getViewMatrix() const;

    private:
      glm::vec3 _position; // Position camera
      float _fPhi; // Coordonnées du vecteur sphérique _frontVector
      float _fTheta; // Coordonnées du vecteur sphérique _frontVector
      glm::vec3 _frontVector; 
      glm::vec3 _leftVector; 
      glm::vec3 _upVector; 
      float zoom = 0.1f;
      
      void computeDirectionVectors();
  };
}
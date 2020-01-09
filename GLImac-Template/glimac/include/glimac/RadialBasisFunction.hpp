#pragma once
#include <vector>
#include <iostream>
#include <eigen3/Eigen/Dense>

namespace glimac {

    float phi(const float a);
    int findValue(const int i, const int j, const Eigen::MatrixXf ptControl, const Eigen::VectorXf w);
    Eigen::VectorXf findOmega(const Eigen::MatrixXf ptControl, const Eigen::VectorXf value);
    Eigen::MatrixXd generateWorld(const Eigen::MatrixXf ptControl, const Eigen::VectorXf value); 
}
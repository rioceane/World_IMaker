#include "glimac/RadialBasisFunction.hpp"


namespace glimac {

    float radialFunction(const float a){return exp(-0.1*a*a);}
    //{return exp(-0.1*a*a);} = gaussienne
    //{return sqrt(1+(-0.1*a)(-0.1*a));} = multiquadratique
    //{return (1/(1+(-0.1*a)(-0.1*a)));} = inverse quadratique

    int findValue(const int i, const int j, const Eigen::MatrixXf ptControl, const Eigen::VectorXf w){
        float value = 0;
        Eigen::VectorXf coordPoint(2);
        coordPoint << i, j;
        for (int index = 0; index < ptControl.rows(); index++){
            value += w(index)*radialFunction((coordPoint.transpose()-ptControl.row(index)).norm());
        }
        return round(value);
    }

    Eigen::VectorXf findOmega(const Eigen::MatrixXf ptControl, const Eigen::VectorXf value){ //ptControl = points de contrôle
        Eigen::MatrixXf Om = Eigen::MatrixXf::Zero(ptControl.rows(), ptControl.rows());
        for (int i = 0; i < Om.rows(); i++){
            for (int j = 0; j < Om.cols(); j++){
                Om(i,j)= radialFunction((ptControl.row(i)-ptControl.row(j)).norm());
            }
        }
        return Om.inverse() * value;
    }

    Eigen::MatrixXd generateWorld(const Eigen::MatrixXf ptControl, const Eigen::VectorXf value){
        Eigen::VectorXf w = findOmega(ptControl, value);
        Eigen::MatrixXd world = Eigen::MatrixXd::Zero(21,21);
        for (int i = 0; i < world.rows(); i++){
            for (int j = 0; j < world.cols(); j++){
                world(i,j) = findValue(i, j, ptControl, w);
            }
        }
        return world;
    }
}
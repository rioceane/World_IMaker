#include <cmath>
#include <vector>
#include <iostream>
#include "glimac/common.hpp"
#include "glimac/Cone.hpp"

namespace glimac {

void Cube::build(GLfloat side) {
    // Equation paramétrique en (r, phi, h) du cone
    // avec r >= 0, -PI / 2 <= theta <= PI / 2, 0 <= h <= height
    //
    // x(r, phi, h) = r (height - h) sin(phi) / height
    // y(r, phi, h) = h
    // z(r, phi, h) = r (height - h) cos(phi) / height
    //
    // Discrétisation:
    // dPhi = 2PI / discLat, dH = height / discHeight
    //
    // x(r, i, j) = r * (height - j * dH) * sin(i * dPhi) / height
    // y(r, i, j) = j * dH
    // z(r, i, j) = r * (height - j * dH) * cos(i * dPhi) / height

    /* 
    équation paramètrique d'un cube = 6 inéquations 



    Soient A,B,C,D,E,F,G,H les sommets du cube (ABCD et EFGH sont deux faces parallèles du cube et AE en est un côté), M le milieu de AB, et N le milieu de AD.
    On cherche l’intersection du cube avec le plan MNP avec P le milieu de l’un des 10 autres côtés.
    Au cube on associe le repère orthonormé AM,AN,AE/2

    P milieu de BC ou DC

    Ici la solution est évidente car P se trouve dans le plan ABCD.
    L’intersection du cube avec le plan MNP est donc le carré ABCD Le plan MNP a pour équation z=0
    On note P0 le milieu de BC et P1 le milieu de DC.
    P milieu de AE

    L’intersection du cube avec le plan MNP est donc le triangle MNP.
    Le plan MNP a pour équation x+y+z=1.
    On note P2 le milieu de AE.
    P milieu de EF ou EH

    Si P3 est le milieu de EF et si P4 est le milieu de EH, les segments MP3 et NP4 sont parallèles, donc M,N,P3,P4 sont dans le même plan.
    Les segments MP3 et NP4 se trouvent chacun sur une des faces du cube et dans le plan MNP3P4.
    Donc, le plan MNP3 (resp MNP4) contient P4 (resp P3) et coupe le cube selon le rectangle MP3P4N.
    Le plan MNP a pour équation x+y=1.
    P milieu de BF ou FG ou GH ou DH

    Si P5 est le milieu de BF, si P6 est le milieu de FG, si P7 est le milieu de GH et si P8 est le milieu de DH, les segments P5P8, P6P7 BD et MN sont parallèles. Le milieu de P5P8 est le centre du cube et c’est aussi le milieu de MP7 et de NP6. Donc N,M,P5,P6,P7,P8 sont dans un même plan. L’intersection du cube avec le plan MNP est donc l’hexagone NMP5P6P7P8.
    Le plan MNP a pour équation x+y−z=1.
    P milieu de CG

    Si MN coupe BC en I et DC en J.
    PI coupe BF en Q et PJ coupe DH en R.
    On a BQ=BF/6 et DR=DH/6.
    Les segments MN,MQ,QP,PR,RN se trouvent chacun sur une des faces du cube et dans le plan MNP.
    L’intersection du cube avec le plan MNP est donc le pentagone NMQPR.
    Le plan MNP a pour équation x+y−3z=1.
    On note P9 le milieu de CG. 

    */


    
    std::vector<ShapeVertex> data;
    
    // Construit l'ensemble des vertex
    for(GLsizei j = 0; j <= side; ++j) {
        for(GLsizei i = 0; i < side; ++i) {
            ShapeVertex vertex;
            
            vertex.texCoords.x = i * side;
            vertex.texCoords.y = j * side;
            
            vertex.normal = sin(i * dPhi);
            
          //  vertex.position = side * (side - j);
            //vertex.position = side * vertex.normal;

            data.push_back(vertex);
        }
    }

    m_nVertexCount = side * side * 6;
    
    GLuint idx = 0;
    // Construit les vertex finaux en regroupant les données en triangles:
    // Pour une longitude donnée, les deux triangles formant une face sont de la forme:
    // (i, i + 1, i + discLat + 1), (i, i + discLat + 1, i + discLat)
    // avec i sur la bande correspondant à la longitude
    for(GLsizei j = 0; j < discHeight; ++j) {
        GLsizei offset = j * discLat;
        for(GLsizei i = 0; i < discLat; ++i) {
            m_Vertices.push_back(data[offset + i]);
            m_Vertices.push_back(data[offset + (i + 1) % discLat]);
            m_Vertices.push_back(data[offset + discLat + (i + 1) % discLat]);
            m_Vertices.push_back(data[offset + i]);
            m_Vertices.push_back(data[offset + discLat + (i + 1) % discLat]);
            m_Vertices.push_back(data[offset + i + discLat]);
        }
    }
    
}

}



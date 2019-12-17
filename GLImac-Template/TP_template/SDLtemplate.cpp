#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <glimac/Cube.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp> // la base de glm
#include <iostream>
#include <vector>



using namespace glimac;


int main(int argc, char** argv) {
    // Initialize SDL and open a window
    SDLWindowManager windowManager(800, 800, "Word IMaker");

    // Initialize glew for OpenGL3+ support
    GLenum glewInitError = glewInit();
    if(GLEW_OK != glewInitError) {
        std::cerr << glewGetErrorString(glewInitError) << std::endl;
        return EXIT_FAILURE;
    }

    std::cout << "OpenGL Version : " << glGetString(GL_VERSION) << std::endl;
    std::cout << "GLEW Version : " << glewGetString(GLEW_VERSION) << std::endl;

    FilePath applicationPath(argv[0]);
    Program program = loadProgram(applicationPath.dirPath() + "shaders/3D.vs.glsl", applicationPath.dirPath() + "shaders/3D.fs.glsl");
    program.use();

    /*********************************
     * HERE SHOULD COME THE INITIALIZATION CODE
     *********************************/

    Cube c;

    c.createBuffer();



    /*
    GLuint vbo; 
    glGenBuffers(1,&vbo);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);


         //    v6----- v5
            //   /|      /|
            //  v1------v0|
            //  | |     | |
            //  | |v7---|-|v4
            //  |/      |/
            //  v2------v3
        float _positionsSommets[] = {
            // v0
             0.5,  0.5,  0.5,
            // v1
            -0.5,  0.5,  0.5,
            // v2
            -0.5, -0.5,  0.5,
            // v3
             0.5, -0.5,  0.5,
            // v4
             0.5, -0.5, -0.5,
            // v5
             0.5,  0.5, -0.5,
            // v6
            -0.5,  0.5, -0.5,
            // v7
            -0.5, -0.5, -0.5,
        };


            //    v6----- v5
            //   /|      /|
            //  v1------v0|
            //  | |     | |
            //  | |v7---|-|v4
            //  |/      |/
            //  v2------v3
        int _indexsSommets[] = {
            // face de devant : v0, v1, v2 puis v0, v2, v3
            0, 1, 2,  0, 2, 3,
            // face de derrière
            4, 7, 6,  4, 6, 5,
            // face de gauche
            1, 6, 7,  1, 7, 2,
            // face de droite
            0, 3, 4,  0, 4, 5,
            // face de dessous
            2, 7, 4,  2, 4, 3,
            // face de dessus
            0, 5, 6,  0, 6, 1
        };





    glBufferData(GL_ARRAY_BUFFER, sizeof(_positionsSommets), _positionsSommets, GL_STATIC_DRAW);
    // on unbind, ce n'est pas nécessaire mais c'est par sécurité, ça rend les choses plus faciles à débuguer
    glBindBuffer(GL_ARRAY_BUFFER, 0);


    GLuint ibo;
    // on crée le buffer
    glGenBuffers(1, &ibo);
    // on le bind pour que la ligne suivante s'applique bien à ce buffer ci
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    // on envoie toutes nos données au GPU
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(_indexsSommets), _indexsSommets, GL_STATIC_DRAW);
    // on unbind, ce n'est pas nécessaire mais c'est par sécurité, ça rend les choses plus faciles à débuguer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);


    GLuint vao;
    // On crée et on bind le vertex array
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    // On bind notre vertex buffer de tout à l'heure
    // Ceci aura pour effet de l'attacher au vertex array actuellement bindé
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // On choisit un petit nom pour notre attribut, pour l'instant on n'a que des positions (les couleurs viendront plus tard) et on va lui donner le numéro 0.
    glEnableVertexAttribArray(0); 
    // On dit à OpenGL que l'attribut 0 contient trois float
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), 0);
    // On unbind par sécurité
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

*/


    //application loop
    bool done = false;
    while(!done) {
        SDL_Event e;
        while (windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }


        /*********************************
         * HERE SHOULD COME THE RENDERING CODE
         *********************************/
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*

        // Bind le vertex array, et donc le vertex buffer qu'on lui a attaché
        glBindVertexArray(vao);
        // Bind l'index buffer
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
            // On dessine nos 36 sommets (3 par triangle * 2 triangles par face * 6 faces)
            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        // Unbind
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
       

        glBindVertexArray(0);

        */

        c.drawCube();

        // Update the display
        windowManager.swapBuffers();
    }

    /*
    //Libération des ressources pour le vbo
    glDeleteBuffers(1,&vbo);
    //Libération des ressources pour le vao
    glDeleteVertexArrays(1, &vao);
    */

    c.deleteBuffers();

    return EXIT_SUCCESS;
}

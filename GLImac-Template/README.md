# World IMaker

3D field and scene viewer editor. 
It uses C++, OpenGL 3.3 and SDL2.
This is a school project for the engineer school IMAC (Paris).

## Table of Contents

+ [Getting started](#Getting-started)
+ [Build project](#Build-project)
+ [Run project](#Run-project)
+ [Guide of the editor](#Guide-of-the-editor)


## Getting started :

### Librairies :

#### On Linux :

CMAKE : 

```bash
sudo apt-get install g++ cmake
```

SDL2 : 
```bash
sudo apt-get install libsdl2-dev
```

OpenGL : 

```bash
sudo apt-get install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

GLEW :

```bash
sudo apt-get install glew
```

DOXYGEN : 

```bash
sudo apt install graphviz doxygen
```


## Build project

Go to the folder GLImac-Template-build in the project and :


IF IT IS NOT EMPTY :
	delete everything inside the folder


IF IT IS EMPTY :
```bash
cmake ../GLImac-Template
make
```
Make sure you're still in your build folder and :
```bash
	./TP_template/TP_template_SDLtemplate
```

## Guide of the editor
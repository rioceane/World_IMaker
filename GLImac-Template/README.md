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
IF YOU ARE ONE APPLE:
	```bash
		./TP_template/TP_template_SDLtemplate
	```
ELSE:
	```bash
		./TP_template/TP_template_SDLtemplate
	```

## Guide of the editor

Camera :
	To rotate in every sens the camera, deplace your computer mouse on the window in the wanted direction.
	If you pressed :
		Z => You have a forward view
		S => You have a backward view
		G => You have a left view
		D => You have a right view

Cursor :
	To move the cursor on the x axe :
		1. Pressed the X keyboard. 
		2. To go left, pressed the keyboard left arrow.
		3. To go right, pressed the keyboard right arrow.
	To move the cursor on the y axe :
		1. Pressed the Y keyboard. 
		2. To go up, pressed the keyboard left arrow.
		3. To go down, pressed the keyboard right arrow.
	To move the cursor on the z axe :
		1. Pressed the Z keyboard. 
		2. To go front, pressed the keyboard left arrow.
		3. To go back, pressed the keyboard right arrow.

Cube :
	To add a cube, pressed the RETURN keyboard.
	To remove a cube, pressed the BACKSPACE keyboard.
	To dig a column, pressed the D keyboard.
	To extrude a column, pressed th E keyboard.

Color :
	To modify the color, click on the color of your choice in the menu (on the left of the window).

Lights : 
	To add daylight, you can click on "Ambience de jour", this will generate a light with default values. You can fix the position of your light by adjusting the corresponding x, y, z position.

	To add nightlight, you can click on "Ambiance de nuit", this will generate a light with default values. You can fix the position of your light by adjusting the corresponding x, y, z position.

	You can also add both lights at the same time and adjust their position as you wish.














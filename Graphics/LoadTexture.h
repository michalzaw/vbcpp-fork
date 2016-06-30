#ifndef LOADTEXTURE_H_INCLUDED
#define LOADTEXTURE_H_INCLUDED


#include <iostream>

#include <GLEW/glew.h>
#include <SOIL/SOIL.h>


// U�ycie SOIL jedynie do wczytania pliku graficznego
// Tworzenie tekstury wykonywane recznie, gdyz wbudowane funkcje SOILa powoduja crash na Windowsie
GLuint LoadTexture(const char* FileName, bool Mipmaping = true);


#endif // LOADTEXTURE_H_INCLUDED

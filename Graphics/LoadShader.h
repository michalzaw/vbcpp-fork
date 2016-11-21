#ifndef LOADSHADER_H_INCLUDED
#define LOADSHADER_H_INCLUDED


#include <vector>
#include <fstream>
#include <iostream>

#include <GLEW/glew.h>


GLuint loadShader(const char* VertexShaderFileName, const char* FragmentShaderFileName);


#endif // LOADSHADER_H_INCLUDED

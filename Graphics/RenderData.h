#ifndef RENDERDATA_H_INCLUDED
#define RENDERDATA_H_INCLUDED


#include <list>

#include "Model.h"
#include "CameraStatic.hpp"
#include "Light.h"
#include "Transform.h"
#include "RenderObject.h"
#include "../Utils/RStaticModel.h"
#include "../Scene/SceneObject.h"


enum RenderElementType
{
    RET_SINGLE,
    RET_GRASS
};


struct RenderListElement
{
    RenderElementType   type;

    RStaticModel*       model;
    StaticModelMesh*    mesh;

    float               distanceFromCamera;

    SceneObject*        object;
    RenderObject*       renderObject;

    RenderListElement();

};


struct RenderData
{
    std::list<RenderListElement> renderList;
    CameraStatic* camera;
    Framebuffer* framebuffer;
    glm::mat4 MVMatrix;

};


#endif // RENDERDATA_H_INCLUDED

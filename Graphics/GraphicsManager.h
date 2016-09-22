#ifndef GRAPHICSMANAGER_H_INCLUDED
#define GRAPHICSMANAGER_H_INCLUDED


#include <list>
#include <vector>

#include <glm/glm.hpp>

#include "RenderObject.h"
#include "RenderData.h"
#include "Camera.h"
//#include "OGLDriver.h"
#include "Light.h"
#include "../Utils/RModel.h"

#include "CameraStatic.hpp"
#include "CameraFPS.hpp"

#include <memory>

class GraphicsManager
{
    private:
        std::list<RenderObject*>    _renderObjects;
        std::vector<CameraStatic*>  _cameras;
        std::list<Light*>           _lights;

        GraphicsManager();

    public:
        ~GraphicsManager();

        static GraphicsManager& getInstance();


        //RenderObject*   AddRenderObject(RModel* model = NULL/*, glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f),
        //                                glm::vec3 rotation = glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3 scale = glm::vec3(1.0f, 1.0f, 1.0f)*/);

        RenderObject*   AddRenderObject(RenderObject* object); //Model* model = NULL);

        CameraStatic*   AddCameraStatic(int width, int height, GLfloat viewAngle, GLfloat nearValue, GLfloat farValue);
        CameraFPS*      AddCameraFPS(int width, int height, GLfloat viewAngle, GLfloat nearValue, GLfloat farValue);
        Light*          AddDirectionalLight(glm::vec3 color, float ambientIntensity, float diffuseIntensity);
        Light*          AddPointLight(glm::vec3 color, float ambientIntensity, float diffuseIntensity, LightAttenuation attenuation = LightAttenuation());


        // Funkcje wywolywana przez SceneObject, nie wywolywac recznie
        void removeRenderObject(RenderObject* object);
        void removeCamera(CameraStatic* camera);
        void removeLight(Light* light);


        RenderData* GetRenderData();
};


#endif // GRAPHICSMANAGER_H_INCLUDED

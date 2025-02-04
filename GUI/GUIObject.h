#ifndef GUIOBJECT_H_INCLUDED
#define GUIOBJECT_H_INCLUDED


#include <vector>

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "../Graphics/OGLDriver.h"
#include "../Graphics/VBO.h"

#include "GUIRenderListElement.h"


struct GUIVertex
{
    glm::vec3 position;
    glm::vec2 texCoord;

};


class GUIObject
{
    private:
        glm::mat4 _identityTransformMatrix;

    protected:
        glm::vec3   _position;
        glm::vec2   _scale;
        float       _rotation;

        glm::vec4   _color;

        bool _isActive;

        std::vector<VBO*> _vbos;


        inline virtual void changedVerticesTransformMatrixParameters() {}
        inline virtual void changedTexCoordTransformMatrixParameters() {}

    public:
        GUIObject();
        ~GUIObject();

        void setPosition(glm::vec3 position);
        void setPosition(glm::vec2 position);
        void setPosition(float x, float y, float z = 0.0f);
        void setScale(glm::vec2 scale);
        void setScale(float scaleX, float scaleY);
        void setRotation(float angle);          // Radians

        void move(glm::vec3 delta);
        void move(glm::vec2 delta);
        void move(float x, float y, float z = 0.0f);
        void scale(glm::vec2 delta);
        void scale(float x, float y);
        void rotate(float angle);

        glm::vec3   getPosition();
        glm::vec2   getScale();
        float       getRotation();


        void setIsActive(bool isActive);
        bool isActive();


        void            setColor(glm::vec4 color);
        glm::vec4       getColor();


        VBO*            getVBO(unsigned int index = 0);
        unsigned int    getQuantumOfVBO();

        virtual glm::mat4& getVerticesTransformMatrix(unsigned int vboIndex = 0) { return _identityTransformMatrix; }
        virtual glm::mat4& getTexCoordTransformMatrix(unsigned int vboIndex = 0) { return _identityTransformMatrix; }

        virtual void addDataToRenderList(GUIRenderList* renderList) = 0;

};


#endif // GUIOBJECT_H_INCLUDED

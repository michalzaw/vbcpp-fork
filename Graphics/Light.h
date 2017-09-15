#ifndef LIGHT_H_INCLUDED
#define LIGHT_H_INCLUDED

#include <cstdio>
#include <cmath>

#include <glm/glm.hpp>

#include "Framebuffer.h"
#include "OGLDriver.h"
#include "CameraStatic.hpp"

#include "../Scene/Component.h"


enum LightType
{
    LT_DIRECTIONAL,
    LT_POINT,
    LT_SPOT

};


struct LightAttenuation
{
    float constant;
    float linear;
    float exp;

    LightAttenuation(float c = 0.0f, float l = 0.0f, float e = 0.0f)
        : constant(c), linear(l), exp(e) {}

};


class Light : public Component
{
    static const int CASCADE_COUNT = 3;

    private:
        LightType   _lightType;

        glm::vec3   _color;
        float       _ambientIntensity;
        float       _diffuseIntensity;

        LightAttenuation _attenuation;

        float _cutoff;          // Radians
        float _cutoffCos;

        bool            _isShadowMapping;
        Framebuffer*    _shadowMap[CASCADE_COUNT];
        CameraStatic*   _cameraForShadowMap[CASCADE_COUNT];

    public:
        Light(LightType type);
        Light(LightType type, glm::vec3 color, float ambientIntensity, float diffuseIntensity);
        virtual ~Light();

        void setColor(glm::vec3 color);
        void setAmbientIntensity(float intensity);
        void setDiffuseIntensity(float intensity);
        void setAttenuation(float constant, float linear, float exp);
        void setAttenuation(LightAttenuation attenuation);
        void setCutoff(float cutoff); // Kat w radianach
        void setShadowMapping(bool isEnable);

        LightType           getLightType();
        glm::vec3           getColor();
        float               getAmbientIntensity();
        float               getDiffiseIntenisty();
        glm::vec3           getDirection();
        glm::vec3           getPosition();
        LightAttenuation&   getAttenuation();
        float               getCutoff();
        float               getCutoffCos();
        bool                isShadowMapping();
        Framebuffer*        getShadowMap(int index = 0);
        CameraStatic*       getCameraForShadowMap(int index = 0);

};


#endif // LIGHT_H_INCLUDED

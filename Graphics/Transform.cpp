#include "Transform.h"

#include "../Scene/SceneObject.h"

#include <cstdio>
#include <iostream>

void Transform::updateTransformMatrix()
{
    glm::mat4 pos = glm::translate(_position);

    /*
    _transformMatrix = glm::translate(_position) *
                       glm::rotate(_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f)) *
                       glm::rotate(_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f)) *
                       glm::rotate(_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f)) *
                       glm::scale(_scale);
    */

    glm::mat4 rot = glm::rotate(_rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
             rot *= glm::rotate(_rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
             rot *= glm::rotate(_rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 s = glm::scale(_scale);

    _transformMatrix = pos * rot * s;

    _transformMatrixIs = true;
}

void Transform::update()
{
    // Wyglada na to, ze i tak po wywolaniu 'setPosition' albo 'setRotation' obie matryce sa ustawiana na 'false' wiec i tak obie musza byc przeliczone
    // Do tego NormalMatrix to transponowana matryca Tranformacji, wiec praktycznie za kazdym razem trzeba przeliczac obie
    _transformMatrixIs = false;
    _normalMatrixIs = false;

    _object->updateComponents();
    //changed = true;
}


Transform::Transform(SceneObject* object)
    : _position(0.0f, 0.0f, 0.0f),
    _rotation(0.0f, 0.0f, 0.0f),
    _scale(1.0f, 1.0f, 1.0f),
    _object(object),
    changed(true)
{
    update();
}


Transform::Transform(const Transform& t)
{
    _position = t._position;
    _rotation = t._rotation;
    _scale = t._scale;

    _object = t._object;

    update();
}


Transform::~Transform()
{

}


void Transform::setPosition(glm::vec3 position)
{
    _position = position;

    update();
}


void Transform::setRotation(glm::vec3 rotation)
{
    _rotation = rotation;

    update();
}


void Transform::setRotation(float x, float y, float z, float w)
{
    glm::quat q;
    q.x = x;
    q.y = y;
    q.z = z;
    q.w = w;
    glm::mat4 rot = glm::mat4_cast(q);

    _transformMatrix = glm::translate(_position) * rot * glm::scale(_scale);

    _transformMatrixIs = true;
}


void Transform::setScale(glm::vec3 scale)
{
    _scale = scale;

    update();
}


glm::vec3 Transform::getPosition()
{
    return _position;
}


glm::vec3 Transform::getRotation()
{
    return _rotation;
}


glm::vec3 Transform::getScale()
{
    return _scale;
}


glm::mat4& Transform::getTransformMatrix()
{

    if (!_transformMatrixIs)
    {
        updateTransformMatrix();
    }

    return _transformMatrix;
}


glm::mat4& Transform::getNormalMatrix()
{

    if (!_normalMatrixIs)
    {
        _normalMatrix = glm::transpose(glm::inverse(getTransformMatrix()));

        _normalMatrixIs = true;
    }

    return _normalMatrix;
}


Transform& Transform::operator=(const Transform& t)
{
    _position = t._position;
    _rotation = t._rotation;
    _scale = t._scale;

    _object = t._object;

    update();

    return *this;
}

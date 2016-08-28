#ifndef SCENEOBJECT_H_INCLUDED
#define SCENEOBJECT_H_INCLUDED


#include <vector>

#include "Component.h"


class SceneManager;


class SceneObject
{
    private:
        std::vector<Component*> _components;

        unsigned int _id;
        Transform _transform;
        bool _isActive;

        SceneManager* _sceneManager;

    public:
        SceneObject(unsigned int id, SceneManager* sceneManager);
        ~SceneObject();

        void addComponent(Component* component);
        void removeComponent(Component* component);

        void            setIsActive(bool is);

        unsigned int    getId();
        Transform*      getTransform();
        bool            isActive();

        Component*      getComponent(unsigned int index);
        unsigned int    getComponentsCount();

        SceneManager* getSceneManager();

        void changedTransform();

};


#endif // SCENEOBJECT_H_INCLUDED

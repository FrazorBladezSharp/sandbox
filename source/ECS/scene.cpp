#include "scene.h"

namespace Night
{

    Scene::Scene()
    {
        m_Entity = new Entity();
        m_Registry = new QVector<Object*>();
    }

    Scene::~Scene()
    {
        m_Registry->clear();
        delete m_Registry;

        delete m_Entity;
    }

    void Scene::Initialize()
    {
        for (int index = 0; index < NIGHT_MAX_ENTITIES; index++)
        {
            m_Entity->Entities[index] = NIGHT_UNUSED;

            for(int comps = 0; comps < (int)Night::Component::COMP_TOTAL; comps++)
            {
                m_Entity->Has_Component[index][comps] = NIGHT_UNUSED;
            }

        }
    }

    int Scene::AddEntity()
    {
        static int entity_ID = 0;

        m_Entity->Entities[entity_ID] = entity_ID;

        entity_ID++;

        return entity_ID;
    }



    void Scene::BaseComponents(int entity_id)
    {
        m_Entity->Has_Component[entity_id][(int)Night::Component::COMP_POSITION] = 1;
        Position_Component *position = new Position_Component();


        Object *object = new Object();

        object->entity_ID = entity_id;
        object->components.push_back(position);

        m_Registry->push_back(object);
    }

}

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
        static int entity_ID = NIGHT_UNUSED;
        entity_ID++;

        m_Entity->Entities[entity_ID] = entity_ID;

        BaseComponents(entity_ID);

        return entity_ID;
    }

    const QVector<Scene::Object *> &Scene::ViewRegistry()
    {
        return *m_Registry;
    }



    void Scene::BaseComponents(int entity_id)
    {

        m_Entity->Has_Component[entity_id][(int)Night::Component::COMP_POSITION] = 1;
        Position_Component *position = new Position_Component();

        Object *object = new Object();

        object->entity_ID = entity_id;
        object->uuid = QUuid::createUuid();
        object->components.push_back(position);

        m_Registry->push_back(object);

    }

}

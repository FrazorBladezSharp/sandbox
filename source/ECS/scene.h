#ifndef SCENE_H
#define SCENE_H

#include "ECS.h"
#include "components.h"
#include <QVector>
#include <QUuid>


namespace Night
{

    class Scene
    {

        struct Entity
        {

            int Entities[NIGHT_MAX_ENTITIES];

            int Has_Component[NIGHT_MAX_ENTITIES][(unsigned long)Night::Component::COMP_TOTAL];

        };

    public:

        typedef struct
        {

            int entity_ID;
            QUuid uuid;
            QVector <void*> components;

        } Object;


        Scene();
        ~Scene();

        void Initialize();

        int AddEntity();

        const QVector <Object*>& ViewRegistry();

    private:
        void BaseComponents(int entity_id);

        Entity *m_Entity;

        QVector <Object*> *m_Registry;

    };

}
#endif // SCENE_H

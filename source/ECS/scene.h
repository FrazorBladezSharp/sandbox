#ifndef SCENE_H
#define SCENE_H

#include "ECS.h"
#include "components.h"
#include <QVector>


namespace Night
{

    class Scene
    {

        typedef struct
        {

            int entity_ID;
            QVector <void*> components;

        } Object;


        struct Entity
        {

            int Entities[NIGHT_MAX_ENTITIES];

            int Has_Component[NIGHT_MAX_ENTITIES][(unsigned long)Night::Component::COMP_TOTAL];

        };

        Entity *m_Entity;

        QVector <Object*> *m_Registry;



    public:
        Scene();
        ~Scene();

        void Initialize();

        int AddEntity();

    private:
        void BaseComponents(int entity_id);

    };

}
#endif // SCENE_H

#ifndef SCENE_H
#define SCENE_H

#include "source/night_common.h"

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

        };

    public:

        typedef struct
        {

            int entity_ID;
            QUuid uuid;
            void* components[(unsigned)Night::Component::COMP_TOTAL];

        } Object;


        Scene();
        ~Scene();

        void Initialize();

        int AddEntity();

        const QVector <Object*>& ViewRegistry();

    private:
        void BaseComponents(int entity_id);

        // needs to be kept in sync with Entity.
        Ref<Entity> m_Entity = CreateRef<Entity>();

        QVector <Object*> *m_Registry;

    };

}
#endif // SCENE_H

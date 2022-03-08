#include "midnight.h"

#include <QDebug>

namespace Night
{
    Midnight::Midnight(QObject *parent)
        : QObject{parent}
        , m_Scene(CreateRef<Scene>())
        , m_Output(CreateRef<TextOutput>(nullptr))
    {
        m_Scene->Initialize();

    }

    void Midnight::Initialize()
    {
        camera = m_Scene->AddEntity();
        player = m_Scene->AddEntity();
    }

    void Midnight::OnUpdate()
    {
        m_Output->OnUpdate(m_TextView);
    }

    bool Midnight::RegisterOutput(TextOutput *output)
    {
        bool result = true;

        m_Output.reset(output);
        m_TextView = m_Output->Initialize();

        result = !(m_Output == nullptr);

        return result;
    }

    void Midnight::setPlayerPosition(int x, int y)
    {
        Position_Component* player_position = nullptr;

        auto registry = m_Scene->ViewRegistry();

        Scene::Object* object = registry[player];

        player_position = static_cast<Position_Component*>(object->components[(int)Component::COMP_POSITION]);

        player_position->x = x;
        player_position->y = y;

        m_TextView = m_Output->setPosition(x, y, "P");
    }

    void Midnight::movePlayer(QKeyEvent *event)
    {
        Position_Component* player_position = nullptr;
        int x = 0;
        int y = 0;

        auto registry = m_Scene->ViewRegistry();

        Scene::Object* object = registry[player];

        player_position = static_cast<Position_Component*>(object->components[(int)Component::COMP_POSITION]);

        int m_PosX = player_position->x;
        int m_PosY = player_position->y;

        x += ((event->key() == Qt::Key::Key_D) * 1);
        x -= ((event->key() == Qt::Key::Key_A) * 1);
        y += ((event->key() == Qt::Key::Key_S) * 1);
        y -= ((event->key() == Qt::Key::Key_W) * 1);

        x = (x * ((m_PosX + x >= 0) && (m_PosX + x < 79)));
        y = (y * ((m_PosY + y >= 0) && (m_PosY + y < 20)));
        m_PosX += x;
        m_PosY += y;

        m_TextView = m_Output->Move(x, y, m_PosX, m_PosY, "P");
        setPlayerPosition(m_PosX, m_PosY);
    }

}
/*
    m_Scene->Initialize();

    int entity1 = m_Scene->AddEntity();
    int entity2 = m_Scene->AddEntity();

    std::cout
           << "Entity 1 ID: "
           << entity1
           << "    Entity 2 ID: "
           << entity2
           << std::endl;

    auto registry = m_Scene->ViewRegistry();

    for (Night::Scene::Object* object : registry)
    {
        std::cout
                << "Object ID: "
                << object->entity_ID
                << "    Position x:"
                << static_cast<Night::Position_Component*>(object->components[0])->x
                << "    Uuid :"
                << object->uuid.toString().toStdString()
                << std::endl;

    }
*/

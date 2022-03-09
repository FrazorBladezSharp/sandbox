#include "midnight.h"

#include <QDebug>

namespace Night
{
    Midnight::Midnight(QObject *parent)
        : QObject{parent}
        , m_Scene(CreateRef<Scene>())
        , m_Output(CreateRef<TextOutput>(nullptr))
        , m_Camera(CreateRef<Camera>(m_Scene->AddEntity(), m_Scene))
        , m_Player(CreateRef<Player>(m_Scene->AddEntity(), m_Scene))
    {
        m_Scene->Initialize();
    }

    void Midnight::Initialize()
    {
        // Empty
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
        Position_Component* player_position =
                m_Player->getPosition();

        player_position->x = x;
        player_position->y = y;

        m_TextView = m_Output->setPosition(x, y, "P");
    }

    void Midnight::movePlayer(QKeyEvent *event)
    {
        Position_Component* player_position =
                m_Player->getPosition();

        int x = 0;
        int y = 0;

        int posX = player_position->x;
        int posY = player_position->y;

        x += ((event->key() == Qt::Key::Key_D) * 1);
        x -= ((event->key() == Qt::Key::Key_A) * 1);
        y += ((event->key() == Qt::Key::Key_S) * 1);
        y -= ((event->key() == Qt::Key::Key_W) * 1);

        x = (x * ((posX + x >= 0) && (posX + x < 79)));
        y = (y * ((posY + y >= 0) && (posY + y < 20)));
        posX += x;
        posY += y;

        m_TextView = m_Output->Move(x, y, posX, posY, "P");
        setPlayerPosition(posX, posY);
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

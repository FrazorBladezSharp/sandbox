#ifndef MAINENGINE_H
#define MAINENGINE_H

#include "source/night_common.h"

#include "source/core/midnight.h"

#include "source/systems/Movement/basicmovement.h"
#include "source/systems/Rendering/basicrendering.h"

#include "source/ECS/scene.h"
#include "source/implementation/mobile/mobiles.h"
#include "source/implementation/output/textoutput.h"



namespace Night
{
    class MainEngine : public Midnight
    {

        Q_OBJECT

    public:
        MainEngine(QWidget *parent);

        virtual void OnUpdate() override;

        virtual bool RegisterOutput(TextOutput* output) override;

        virtual void SetPlayerPosition(int x, int y) override;

        virtual void MovePlayer(QKeyEvent *event) override;


    private:
        Ref<BasicMovement> m_MovementSystem;
        Ref<BasicRendering> m_RenderingSystem;

        Ref<Scene> m_Scene;
        Ref<TextOutput> m_Output;
        Ref<Camera> m_Camera;
        Ref<Player> m_Player;
        QString m_TextView;

    };
}

#endif // MAINENGINE_H

#ifndef MIDNIGHT_H
#define MIDNIGHT_H

#include "source/night_common.h"
#include <QObject>

#include "source/ECS/scene.h"
#include "source/implementation/output/textoutput.h"

namespace Night
{
    class Midnight : public QObject
    {
        Q_OBJECT

    public:
        explicit Midnight(QObject *parent = nullptr);

        void Initialize();

        void OnUpdate();

        bool RegisterOutput(TextOutput* output);

        void setPlayerPosition(int x, int y);

        void movePlayer(QKeyEvent *event);

    signals:

    private:
        Ref<Scene> m_Scene;
        Ref<TextOutput> m_Output;
        int camera = NIGHT_UNUSED;
        int player = NIGHT_UNUSED;
        QString m_TextView;

    };
}

#endif // MIDNIGHT_H

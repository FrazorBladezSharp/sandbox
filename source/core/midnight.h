#ifndef MIDNIGHT_H
#define MIDNIGHT_H

#include "source/night_common.h"

#include <QWidget>

#include "source/implementation/output/textoutput.h"

namespace Night
{
    class Midnight : public QWidget
    {
        Q_OBJECT

    public:
        Midnight(QWidget *parent)
            : QWidget(parent) {}

        virtual void OnUpdate() = 0;

        virtual bool RegisterOutput(TextOutput* output) = 0;

        virtual void SetPlayerPosition(int x, int y) = 0;

        virtual void MovePlayer(QKeyEvent *event) = 0;
    };
}

#endif // MIDNIGHT_H

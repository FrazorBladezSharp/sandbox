#ifndef TEXTOUTPUT_H
#define TEXTOUTPUT_H

#include <QPlainTextEdit>

namespace Night
{
    class TextOutput : public QPlainTextEdit
    {
        Q_OBJECT
    public:
        TextOutput(QWidget *parent = nullptr);

        // this is a simple renderer : should be a system
        void OnUpdate(QString view);
        // part of the renderer
        void setText(const QString text);


        // move to a system (movement)
        QString setPosition(int x, int y, QString symbol);

        // move to a system (movement)
        QString Move(int dir_x, int dir_y, int current_x, int current_y, QString symbol);

    private:
        // move to a system (movement)
        QString ReconstructOutput();

        QString scene[40][20];
    };
}

#endif // TEXTOUTPUT_H

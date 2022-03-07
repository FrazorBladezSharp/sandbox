#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "source/ECS/scene.h"


QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationWindow; }
QT_END_NAMESPACE


class ApplicationWindow : public QMainWindow
{
    Q_OBJECT

public:
    ApplicationWindow(QWidget *parent = nullptr);
    ~ApplicationWindow();

    void Run();
    void OnUpdate();

protected:
    virtual void keyPressEvent(QKeyEvent *event) override;

private slots:
    void on_exitButton_clicked();

private:
    Ui::ApplicationWindow *ui;
    Night::Scene *m_Scene;
    QTimer *m_Timer;

    QString m_TextView;
    int m_PosX;
    int m_PosY;

};
#endif // APPLICATIONWINDOW_H

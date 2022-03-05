#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QMainWindow>
#include "source/ECS/ECS.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ApplicationWindow; }
QT_END_NAMESPACE

class ApplicationWindow : public QMainWindow
{
    Q_OBJECT

public:
    ApplicationWindow(QWidget *parent = nullptr);
    ~ApplicationWindow();

private slots:
    void on_exitButton_clicked();

private:
    Ui::ApplicationWindow *ui;
    Night::Scene *m_Scene;
};
#endif // APPLICATIONWINDOW_H

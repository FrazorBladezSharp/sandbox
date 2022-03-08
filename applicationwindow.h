#ifndef APPLICATIONWINDOW_H
#define APPLICATIONWINDOW_H

#include <QMainWindow>
#include <QTimer>

#include "source/core/midnight.h"


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
    void InitializeEngine();

    Ui::ApplicationWindow *ui;
    Night::Midnight *m_Midnight;
    QTimer *m_Timer;
};
#endif // APPLICATIONWINDOW_H

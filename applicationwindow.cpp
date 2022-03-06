#include "applicationwindow.h"
#include "ui_applicationwindow.h"

#include <QVector>
//#include <QDebug>

ApplicationWindow::ApplicationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ApplicationWindow)
    , m_Scene(new Night::Scene())
    , m_Timer(new QTimer(this))
{
    ui->setupUi(this);

    m_Scene->Initialize();

    m_Timer->setTimerType(Qt::PreciseTimer);

    connect(m_Timer, &QTimer::timeout, this, &ApplicationWindow::OnUpdate);

}

ApplicationWindow::~ApplicationWindow()
{
    delete m_Timer;
    delete m_Scene;
    delete ui;
}

void ApplicationWindow::Run()
{
    m_Timer->start(15);
}

void ApplicationWindow::OnUpdate()
{
    m_Timer->stop();



    m_Timer->start(15);
}


void ApplicationWindow::on_exitButton_clicked()
{
    this->close();
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

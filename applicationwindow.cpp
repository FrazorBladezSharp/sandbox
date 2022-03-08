#include "applicationwindow.h"
#include "ui_applicationwindow.h"

#include <QVector>
#include <QDebug>

ApplicationWindow::ApplicationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ApplicationWindow)
    , m_Scene(new Night::Scene())
    , m_Timer(new QTimer(this))
{
    ui->setupUi(this);

    // move to engine interface
    m_Scene->Initialize();

    ui->display_layers->setCurrentWidget(ui->intro);
    ui->display_layers->setFocus();

    m_Timer->setTimerType(Qt::PreciseTimer);

    connect(m_Timer, &QTimer::timeout, this, &ApplicationWindow::OnUpdate);

    // interface to initialize main engine and add systems.
}

ApplicationWindow::~ApplicationWindow()
{
    delete m_Timer;
    delete m_Scene;
    delete ui;
}

void ApplicationWindow::Run()
{
    m_PosX = 10;
    m_PosY = 5;
    // the @ = player entity
    m_TextView = ui->text_display->setPosition(m_PosX, m_PosY, "@");
    m_Timer->start(15);
}

void ApplicationWindow::OnUpdate()
{
    m_Timer->stop();

    // update main engine - our first interface
    ui->text_display->OnUpdate(m_TextView);

    m_Timer->start(15);
}

void ApplicationWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key::Key_Any && ui->display_layers->currentWidget() == ui->intro)
        ui->display_layers->setCurrentWidget(ui->output_text_display);

    // this is a system
    if(ui->display_layers->currentWidget() == ui->output_text_display)
    {
        int x = 0;
        int y = 0;

        x += ((event->key() == Qt::Key::Key_D) * 1);
        x -= ((event->key() == Qt::Key::Key_A) * 1);
        y += ((event->key() == Qt::Key::Key_S) * 1);
        y -= ((event->key() == Qt::Key::Key_W) * 1);

        x = (x * ((m_PosX + x > 0) && (m_PosX + x < 39)));
        y = (y * ((m_PosY + y > 0) && (m_PosY + y < 20)));
        m_PosX += x;
        m_PosY += y;

        m_TextView = ui->text_display->Move(x, y, m_PosX, m_PosY, "@");
    }
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

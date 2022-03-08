#include "applicationwindow.h"
#include "ui_applicationwindow.h"

#include <QVector>
#include <QDebug>

ApplicationWindow::ApplicationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ApplicationWindow)
    , m_Midnight(new Night::Midnight())
    , m_Timer(new QTimer(this))
{
    ui->setupUi(this);

    ui->display_layers->setCurrentWidget(ui->intro);
    ui->display_layers->setFocus();

    InitializeEngine();

    m_Timer->setTimerType(Qt::PreciseTimer);

    connect(m_Timer, &QTimer::timeout, this, &ApplicationWindow::OnUpdate);

    qDebug() << "Welcome to the Midnight Sandbox.";
}

ApplicationWindow::~ApplicationWindow()
{
    delete m_Timer;
    delete m_Midnight;
    delete ui;
}

void ApplicationWindow::Run()
{
    m_Timer->start(15);
}

void ApplicationWindow::OnUpdate()
{
    m_Timer->stop();

    // update main engine - our first interface
    m_Midnight->OnUpdate();

    m_Timer->start(15);
}

void ApplicationWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key::Key_Any && ui->display_layers->currentWidget() == ui->intro)
        ui->display_layers->setCurrentWidget(ui->output_text_display);

    if(ui->display_layers->currentWidget() == ui->output_text_display)
        m_Midnight->movePlayer(event);
}


void ApplicationWindow::on_exitButton_clicked()
{
    this->close();
}

void ApplicationWindow::InitializeEngine()
{
    m_Midnight->Initialize();
    bool result = m_Midnight->RegisterOutput(ui->text_display);
    qDebug() << "Registry of Output = " << result;

    m_Midnight->setPlayerPosition(10, 5);
}

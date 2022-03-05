#include "applicationwindow.h"
#include "ui_applicationwindow.h"

#include <iostream>

ApplicationWindow::ApplicationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ApplicationWindow)
    , m_Scene(new Night::Scene())
{
    ui->setupUi(this);

    m_Scene->Initialize();

    int entity1 = m_Scene->AddEntity();
    int entity2 = m_Scene->AddEntity();

    std::cout
           << "Entity 1 ID: "
           << entity1
           << "    Entity 2 ID: "
           << entity2
           << std::endl;

}

ApplicationWindow::~ApplicationWindow()
{
    delete m_Scene;
    delete ui;
}


void ApplicationWindow::on_exitButton_clicked()
{
    this->close();
}


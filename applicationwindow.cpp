#include "applicationwindow.h"
#include "ui_applicationwindow.h"

ApplicationWindow::ApplicationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ApplicationWindow)
    , m_Scene(new Night::Scene())
{
    ui->setupUi(this);
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


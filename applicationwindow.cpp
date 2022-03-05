#include "applicationwindow.h"
#include "ui_applicationwindow.h"

ApplicationWindow::ApplicationWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ApplicationWindow)
{
    ui->setupUi(this);
}

ApplicationWindow::~ApplicationWindow()
{
    delete ui;
}


void ApplicationWindow::on_exitButton_clicked()
{
    this->close();
}


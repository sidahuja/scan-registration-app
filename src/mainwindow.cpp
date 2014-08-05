#include "../include/mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();
    createMenus();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::about()
 {
     QMessageBox::about(this, tr("About Scan Registration App"),
             tr("Scan Registration App <br/> (c) Siddhant Ahuja 2014"));
 }

void MainWindow::createActions()
 {
     aboutAct = new QAction(tr("&About"), this);
     aboutAct->setStatusTip(tr("Show the application's About box"));
     connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
 }

void MainWindow::createMenus()
 {
     helpMenu = menuBar()->addMenu(tr("&Help"));
     helpMenu->addAction(aboutAct);

 }

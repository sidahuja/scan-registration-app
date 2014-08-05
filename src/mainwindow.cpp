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

void MainWindow::openPCD()
{
	QString fileName = QFileDialog::getOpenFileName(this,
     tr("Open PCD"), "../data/", tr("PCD Files (*.pcd)"));
	if (!fileName.isNull() || !fileName.isEmpty())
	{
		QMessageBox::question(this, tr("File Name"),
		     fileName, QMessageBox::Ok);
	}
}

void MainWindow::about()
{
	QMessageBox::about(this, tr("About Scan Registration App"),
		     tr("Scan Registration App <br/> (c) Siddhant Ahuja 2014"));
}

void MainWindow::createActions()
{
	openAct = new QAction(tr("&Open PCD"), this);
	openAct->setStatusTip(tr("Open point cloud data (PCD) file"));
	connect(openAct, SIGNAL(triggered()), this, SLOT(openPCD()));

	aboutAct = new QAction(tr("&About"), this);
	aboutAct->setStatusTip(tr("About Scan Registration App"));
	connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::createMenus()
{
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(openAct);

	helpMenu = menuBar()->addMenu(tr("&Help"));
	helpMenu->addAction(aboutAct);
}

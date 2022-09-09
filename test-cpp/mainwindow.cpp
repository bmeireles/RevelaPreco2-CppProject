#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSettings, &QAction::triggered, this, &MainWindow::onSettings);
    connect(ui->actionMain, &QAction::triggered, this, &MainWindow::onMainView);
    connect(ui->actionScan, &QAction::triggered, this, &MainWindow::onScanView);
    connect(ui->actionCart, &QAction::triggered, this, &MainWindow::onCartView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onSettings()
{
    qDebug() << "Settings clicked";

    // Pop up a settings dialog
}

void MainWindow::onMainView()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::onScanView()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::onCartView()
{
    ui->stackedWidget->setCurrentIndex(2);
}


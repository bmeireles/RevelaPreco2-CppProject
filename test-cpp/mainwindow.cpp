#include "mainwindow.h"
#include "ui_mainwindow.h"


#include <QDebug>
#include <QDialog>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionSettings, &QAction::triggered, this, &MainWindow::onSettings);
    connect(ui->actionMain, &QAction::triggered, this, &MainWindow::onMainView);
    connect(ui->actionScan, &QAction::triggered, this, &MainWindow::onScanView);
    connect(ui->actionCart, &QAction::triggered, this, &MainWindow::onCartView);
    connect(ui->actionWishlist, &QAction::triggered, this, &MainWindow::onWishlistView);
    connect(ui->actionCompanies, &QAction::triggered, this, &MainWindow::onCompaniesView);

    model = new ListModel(this);
    ui->listView->setModel(model);
    ui->listView->setModelColumn(0);
    ui->listView->setFlow(QListView::Flow::TopToBottom);

    connect(ui->listView, &QListView::clicked, this, &MainWindow::onListViewClicked);

    settingsDlg = new SettingsDialog;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onListViewClicked(const QModelIndex &index) {
    if (index.row() <  5)
        ui->stackedWidget->setCurrentIndex(index.row());
    else if (index.row()  == 5) { //changed settings button to index 5
        onSettings();
    } else if (index.row() == 6) { //changed quit button to index 6
        close();
    }
}

void MainWindow::onSettings()
{
    // Pop up a settings dialog
//    SettingsDialog dlg;
//    dlg.exec();

    settingsDlg->show();
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

void MainWindow::onWishlistView()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::onCompaniesView()
{
    ui->stackedWidget->setCurrentIndex(4);
}


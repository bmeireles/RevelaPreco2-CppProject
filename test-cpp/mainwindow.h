#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include "settingsdialog.h"
#include "listmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void onSettings();
    void onMainView();
    void onScanView();
    void onCartView();
    void onWishlistView();
    void onCompaniesView();
    void onListViewClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;

    ListModel *model;
    SettingsDialog* settingsDlg;
};
#endif // MAINWINDOW_H

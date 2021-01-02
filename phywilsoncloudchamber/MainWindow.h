#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "WilsonCloudChamberController.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

using namespace phywilsoncloudchamber;

class MainWindow : public QMainWindow
{
    Q_OBJECT

  public:
    MainWindow( QWidget* parent = nullptr );
    ~MainWindow();

  private slots:
    void restart();

  private:
    void startNewMagnetron();
    void configureMenu();

    Ui::MainWindow* ui;
    QMenu* menu;
    WilsonCloudChamberControllerPtr coubController_;
};
#endif // MAINWINDOW_H

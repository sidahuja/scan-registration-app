#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

class QAction;
class QActionGroup;
class QLabel;
class QMenu;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
     void about();

private:
    Ui::MainWindow *ui;
    void createActions();
    void createMenus();
    QMenu *helpMenu;
    QAction *aboutAct;
};

#endif // MAINWINDOW_H

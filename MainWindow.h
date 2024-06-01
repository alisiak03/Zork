//
// Created by Alisia Kazimierek on 01/06/2024.
//

#ifndef ZORK_MAINWINDOW_H
#define ZORK_MAINWINDOW_H

#include <QMainWindow>
#include "RoomNav.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow() override;

private slots:
    void handleButton1Clicked();
    void handleButton2Clicked();
private:
    Ui::MainWindow *ui;
    RoomNav *roomNav;
    void updateRoom();
    void updateButtons();
};


#endif //ZORK_MAINWINDOW_H

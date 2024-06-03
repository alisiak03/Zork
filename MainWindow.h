//
// Created by Alisia Kazimierek on 01/06/2024.
//

#ifndef ZORK_MAINWINDOW_H
#define ZORK_MAINWINDOW_H

#include <QMainWindow>
#include "RoomNav.h"
#include "TextAnimation.h"
#include "Quiz.h"
#include "ClickableLabel.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    virtual ~MainWindow(); //destructor virtual for inheritance

private slots:
    void handleButton1Clicked();
    void handleButton2Clicked();
    void handleStartButtonClicked();
    void handleQuizButtonClicked();

protected:
    Ui::MainWindow *ui;
    RoomNav *roomNav;
    TextAnimation *textAnimator;
    Quiz *quiz;

    virtual void updateRoom();
    virtual void updateButtons();
    virtual void initialiseIntro();

};


#endif //ZORK_MAINWINDOW_H

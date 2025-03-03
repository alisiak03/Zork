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
#include "ButtonStyling.h"
#include "FutureFeature.h"
#include "GameUtilities.h"
#include "Exeception.h"
#include "DerviedFutureFeature.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

extern int globalButtonClickCount;

class MainWindow : public QMainWindow, public ButtonStyling{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    virtual ~MainWindow(); //destructor virtual for inheritance

private slots:
    void handleButton1Clicked();
    void handleButton2Clicked();
    void handleStartButtonClicked();
    void handleQuizButtonClicked();
    void handleExitButtonClicked();

protected:
    Ui::MainWindow *ui;
    RoomNav *roomNav;
    TextAnimation *textAnimator;
    Quiz *quiz;
    QPushButton *exitButton;

    virtual void updateRoom();
    virtual void updateButtons();
    virtual void initialiseIntro();

};


#endif //ZORK_MAINWINDOW_H
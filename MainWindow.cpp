//
// Created by Alisia Kazimierek on 01/06/2024.
//

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow), roomNav(new RoomNav), textAnimator(new TextAnimation(this))
{ qDebug() << "MainWindow constructor called";

    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("background-color: #C19F6F ");
    ui->button1->setStyleSheet(
            "QPushButton {"
            "background-color: #FFD700;"
            "border: 2px solid #000;"
            "border-radius: 15px;"
            "}"
    );
    ui->button2->setStyleSheet(
            "QPushButton {"
            "background-color: #FFD700;"
            "border: 2px solid #000;"
            "border-radius: 15px;"
            "}"
    );

    initialiseIntro();
    qDebug() << "Connecting buttons";
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::handleButton1Clicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::handleButton2Clicked);

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::handleStartButtonClicked);
}

MainWindow::~MainWindow() {
    delete ui;
    delete roomNav;
}

void MainWindow::initialiseIntro() {
    QPixmap introPixmap("/Users/alisiakazimierek/MyRepos/Zork/Intro.png");
    ui->introImageLabel->setPixmap(introPixmap.scaled(ui->introImageLabel->width(),ui->introImageLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->introTextLabel->setText("Welcome to your Pirate Adventure!! Prepare yourself!!");

    ui->introTextLabel->setStyleSheet(
            "QLabel {"
            "font-size: 24px;"
            "font-family: Papyrus;"
            "}"
            );
    ui->roomLabel->hide();
    ui->button1->hide();
    ui->button2->hide();

    ui->introImageLabel->show();
    ui->introTextLabel->show();
    ui->startButton->show();
}

void MainWindow::handleStartButtonClicked() {

    qDebug() << "Start button clicked";

    ui->introImageLabel->hide();
    ui->introTextLabel->hide();
    ui->startButton->hide();

    ui->roomLabel->show();
    ui->button1->show();
    ui->button2->show();

    updateRoom();
}

void MainWindow::updateRoom() {

    qDebug() << "Updating room";
    QPixmap pixmap(roomNav->getCurrentRoom()->getImagePath());
    ui->roomLabel->setPixmap(pixmap.scaled(ui->roomLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    updateButtons();
    if (roomNav->getCurrentRoom()->getName() == "start") {
       textAnimator->startAnimation(ui->animatedTextLabel, "You want to become part of a pirate crew. \n You are locked in the ships prison as part of a test. \nTo get out of prison, pass the quiz ");
    }else{
        textAnimator->stopAnimation();
    }
}

void MainWindow::updateButtons() {
    qDebug() << "Updating buttons";
    QString currentRoom = roomNav->getCurrentRoom()->getImagePath();

    if (currentRoom == "/Users/alisiakazimierek/MyRepos/Zork/Jail.png") {
        ui->button1->setText("Go to Treasure Room");
        ui->button2->setText("Go to Captain's Room");
        disconnect(ui->button1, nullptr, nullptr, nullptr);
        disconnect(ui->button2, nullptr, nullptr, nullptr);
        connect(ui->button1, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("treasureRoom"); updateRoom(); });
        connect(ui->button2, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("captainRoom"); updateRoom(); });
    } else if (currentRoom == "/Users/alisiakazimierek/MyRepos/Zork/TreasureRoom.png") {
        ui->button1->setText("Go to Captain's Room");
        ui->button2->setText("Go to Ships Prison");
        disconnect(ui->button1, nullptr, nullptr, nullptr);
        disconnect(ui->button2, nullptr, nullptr, nullptr);
        connect(ui->button1, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("captainRoom"); updateRoom(); });
        connect(ui->button2, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("start"); updateRoom(); });
    } else if (currentRoom == "/Users/alisiakazimierek/MyRepos/Zork/CaptainsRoom.png") {
        ui->button1->setText("Go to Treasure Room");
        ui->button2->setText("Go to Ships Prison");
        disconnect(ui->button1, nullptr, nullptr, nullptr);
        disconnect(ui->button2, nullptr, nullptr, nullptr);
        connect(ui->button1, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("treasureRoom"); updateRoom(); });
        connect(ui->button2, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("start"); updateRoom(); });
    }
}

void MainWindow::handleButton1Clicked() {
    qDebug() << "Button 1 clicked";
}

void MainWindow::handleButton2Clicked() {
    qDebug() << "Button 2 clicked";
}
//
// Created by Alisia Kazimierek on 01/06/2024.
//

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QStringList>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow), roomNav(new RoomNav), textAnimator(new TextAnimation(this)), exitButton(new QPushButton("Exit Game", this))
{ qDebug() << "MainWindow constructor called";

    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("background-color: #C19F6F ");
    ui->button1->setStyleSheet(getButton1Style());
    ui->button2->setStyleSheet(getButton2Style());

    ui->quizButton->setStyleSheet(getQuizButtonStyle());

    initialiseIntro();
    qDebug() << "Connecting buttons";
    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::handleButton1Clicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::handleButton2Clicked);
    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::handleStartButtonClicked);
    connect(ui->quizButton, &QPushButton::clicked, this, &MainWindow::handleQuizButtonClicked);
    connect(exitButton, &QPushButton::clicked, this, &MainWindow::handleExitButtonClicked);
    exitButton->hide();
}

MainWindow::~MainWindow() {
    delete ui;
    delete roomNav;
    delete exitButton;
}

void MainWindow::initialiseIntro() {
    QPixmap introPixmap("/Users/alisiakazimierek/MyRepos/Zork/Intro.png");
    ui->introImageLabel->setPixmap(introPixmap.scaled(ui->introImageLabel->width(),ui->introImageLabel->height(), Qt::KeepAspectRatio, Qt::SmoothTransformation));

    ui->introTextLabel->setText(GameUtilities::getFormattedText("Welcome to your Pirate Adventure!! Prepare yourself!!"));

    ui->roomLabel->hide();
    ui->button1->hide();
    ui->button2->hide();
    ui->quizButton->hide();

    ui->introImageLabel->show();
    ui->introTextLabel->show();
    ui->startButton->show();
    someFutureFeature();
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

void MainWindow::handleQuizButtonClicked() {
    qDebug() << "Quiz button clicked";
    QString question = "Who is the best captain of the sea?";
    QStringList answers = {"Blackbeard" , "Jack Sparrow", "Hector Barboosa"};
    int correctIndex = 1;

    quiz = new Quiz(question, answers, correctIndex, this);
    connect(quiz, &Quiz::accepted, this, [this](){
        ui->button1->setEnabled(true);
        ui->button2->setEnabled(true);
    });
    quiz->exec();
    delete quiz; //deleting dialog to free memory (tryna think of memory management)
}

void MainWindow::handleExitButtonClicked() {
    QApplication::quit();
}

void MainWindow::updateRoom() {

    qDebug() << "Updating room";
    QPixmap pixmap(roomNav->getCurrentRoom()->getImagePath());
    ui->roomLabel->setPixmap(pixmap.scaled(ui->roomLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    updateButtons();
    if (roomNav->getCurrentRoom()->getName() == "start") {
        ui->quizButton->show();
        ui->quizButton->setEnabled(true);
        textAnimator->startAnimation(ui->animatedTextLabel, "You want to become part of a pirate crew. \n You are locked in the ships prison as part of a test. \nTo get out of prison, pass the quiz ");
    }else{
        ui->quizButton->hide();
        textAnimator->stopAnimation();
    }
    if(roomNav->getCurrentRoom()->getName() =="Won"){
        exitButton->setGeometry(300,400,100,50);
        exitButton->show();
        GameUtilities::showMessage("Congratulations! You're part of the crew");
    }else{
        exitButton->hide();
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
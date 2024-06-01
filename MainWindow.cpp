//
// Created by Alisia Kazimierek on 01/06/2024.
//

// You may need to build the project (run Qt uic code generator) to get "ui_MainWindow.h" resolved

#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow), roomNav(new RoomNav) {
    ui->setupUi(this);

    ui->button1->setStyleSheet(
            "QPushButton {"
            "background-color: #FFD700;"
            "border: 2px solid #000;"
            "}"
            );
    ui->button2->setStyleSheet(
            "QPushButton {"
            "background-color: #FFD700;"
            "border: 2px solid #000;"
            "}"
    );
    updateRoom();

    connect(ui->button1, &QPushButton::clicked, this, &MainWindow::handleButton1Clicked);
    connect(ui->button2, &QPushButton::clicked, this, &MainWindow::handleButton2Clicked);
}

MainWindow::~MainWindow() {
    delete ui;
    delete roomNav;
}

void MainWindow::updateRoom() {
    QPixmap pixmap(roomNav->getCurrentRoom()->getImagePath());
    ui->roomLabel->setPixmap(pixmap.scaled(ui->roomLabel->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
    updateButtons();
}

void MainWindow::updateButtons() {
    QString currentRoom = roomNav->getCurrentRoom()->getImagePath();

    if (currentRoom == "/Users/alisiakazimierek/MyRepos/Zork/Jail.png") {
        ui->button1->setText("Treasure Room");
        ui->button2->setText("Captain's Room");
        disconnect(ui->button1, nullptr, nullptr, nullptr);
        disconnect(ui->button2, nullptr, nullptr, nullptr);
        connect(ui->button1, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("treasureRoom"); updateRoom(); });
        connect(ui->button2, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("captainRoom"); updateRoom(); });
    } else if (currentRoom == "/Users/alisiakazimierek/MyRepos/Zork/TreasureRoom.png") {
        ui->button1->setText("Captain's Room");
        ui->button2->setText("Ships Prison");
        disconnect(ui->button1, nullptr, nullptr, nullptr);
        disconnect(ui->button2, nullptr, nullptr, nullptr);
        connect(ui->button1, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("captainRoom"); updateRoom(); });
        connect(ui->button2, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("start"); updateRoom(); });
    } else if (currentRoom == "/Users/alisiakazimierek/MyRepos/Zork/CaptainsRoom.png") {
        ui->button1->setText("Treasure Room");
        ui->button2->setText("Ships Prison");
        disconnect(ui->button1, nullptr, nullptr, nullptr);
        disconnect(ui->button2, nullptr, nullptr, nullptr);
        connect(ui->button1, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("treasureRoom"); updateRoom(); });
        connect(ui->button2, &QPushButton::clicked, this, [this]() { roomNav->goToRoom("start"); updateRoom(); });
    }
}

void MainWindow::handleButton1Clicked() {}

void MainWindow::handleButton2Clicked() {}
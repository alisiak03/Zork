#include "Treasure.h"

Treasure::Treasure(QWidget *parent)
        : MainWindow(parent), treasureChestLabel(new ClickableLabel(this)) {
    treasureChestLabel->setGeometry(380, 250, 100, 100);
    treasureChestLabel->setPixmap(QPixmap("/Users/alisiakazimierek/MyRepos/Zork/TreasureChest.png").scaled(100, 100, Qt::KeepAspectRatio));
    treasureChestLabel->hide();

    connect(treasureChestLabel, &ClickableLabel::clicked, this, &Treasure::handleTreasureChestClicked);
}

Treasure::~Treasure() {
    delete treasureChestLabel;
}

void Treasure::handleTreasureChestClicked() {
    QMessageBox::information(this, "Treasure Chest", "You need a key to open this!");
}

void Treasure::updateRoom() {
    MainWindow::updateRoom();

    // Shows the treasure chest in treasure room
    if (roomNav->getCurrentRoom()->getName() == "treasureRoom") {
        treasureChestLabel->show();
    } else {
        treasureChestLabel->hide();
    }
}
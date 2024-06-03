#include "Treasure.h"

Treasure::Treasure(QWidget *parent)
        : MainWindow(parent), treasureChestLabel(new ClickableLabel(this)), keyLabel(new ClickableLabel(this)) {
    treasureChestLabel->setGeometry(380, 250, 100, 100);
    treasureChestLabel->setPixmap(QPixmap("/Users/alisiakazimierek/MyRepos/Zork/TreasureChest.png").scaled(100, 100, Qt::KeepAspectRatio));
    treasureChestLabel->hide();

    keyLabel->setGeometry(540,180,80,80);
    keyLabel->setPixmap(QPixmap("/Users/alisiakazimierek/MyRepos/Zork/Key.png").scaled(80,80, Qt::KeepAspectRatio));
    keyLabel->hide();

    connect(treasureChestLabel, &ClickableLabel::clicked, this, &Treasure::handleTreasureChestClicked);
    connect(keyLabel, &ClickableLabel::clicked, this, &Treasure::handleKeyClicked);
}

Treasure::~Treasure() {
    delete treasureChestLabel;
    delete keyLabel;
}

void Treasure::handleTreasureChestClicked() {
    QMessageBox::information(this, "Treasure Chest", "You need a key to open this!");
}
void Treasure::handleKeyClicked() {
    QMessageBox::information(this, "Key", "You found a key... I wonder what its for");
}

void Treasure::updateRoom() {
    MainWindow::updateRoom();

    // Shows the treasure chest in treasure room
    if (roomNav->getCurrentRoom()->getName() == "treasureRoom") {
        treasureChestLabel->show();
    } else {
        treasureChestLabel->hide();
    }

    if(roomNav->getCurrentRoom()->getName() == "captainRoom"){
        keyLabel->show();
    }else{
        keyLabel->hide();
    }
}
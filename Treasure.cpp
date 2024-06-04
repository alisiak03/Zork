#include "Treasure.h"

Treasure::Treasure(QWidget *parent)
        : MainWindow(parent), treasureChestLabel(new ClickableLabel(this)), keyLabel(new ClickableLabel(this)), bagLabel(new ClickableLabel(this)) {
    treasureChestLabel->setGeometry(380, 250, 100, 100);
    treasureChestLabel->setPixmap(QPixmap("/Users/alisiakazimierek/MyRepos/Zork/TreasureChest.png").scaled(100, 100, Qt::KeepAspectRatio));
    treasureChestLabel->hide();

    keyLabel->setGeometry(540,180,80,80);
    keyLabel->setPixmap(QPixmap("/Users/alisiakazimierek/MyRepos/Zork/Key.png").scaled(80,80, Qt::KeepAspectRatio));
    keyLabel->hide();


    bagLabel->setGeometry(680,320,80,80);
    QPixmap bagPixmap("/Users/alisiakazimierek/MyRepos/Zork/bag.png");

        bagLabel->setPixmap(bagPixmap.scaled(80, 80, Qt::KeepAspectRatio));
        bagLabel->hide();

    connect(treasureChestLabel, &ClickableLabel::clicked, this, &Treasure::handleTreasureChestClicked);
    connect(keyLabel, &ClickableLabel::clicked, this, &Treasure::handleKeyClicked);
    connect(bagLabel, &ClickableLabel::clicked, this, &Treasure::handleBagClicked);

    resetInventory();
}

Treasure::~Treasure() {
    delete treasureChestLabel;
    delete keyLabel;
    delete bagLabel;

}

void Treasure::handleTreasureChestClicked() {
    if(inventory.hasItem("key")){
    QMessageBox::information(this, "Treasure Chest", "You opened the treasure chest!");
    roomNav->goToRoom("Won");
    updateRoom();
    }else{
    QMessageBox::information(this, "Treasure Chest", "You need a key to open this! ");
    }
}


void Treasure::handleKeyClicked() {
    inventory.addItem("key");
    QMessageBox::information(this, "Key", "You found a key... I wonder what its for");
    keyLabel->hide();
    saveInventory();
}

void Treasure::handleBagClicked() {
    QStringList items;
    if(inventory.hasItem("key")){
        items << "key";
    }
    if(items.isEmpty()){
        QMessageBox::information(this,"Inventory", "Your bag is empty");
    }else{
        QMessageBox::information(this, "Inventory", "You have the following items in your bag: \n" + items.join(","));
    }
}

void Treasure::updateRoom() {
    MainWindow::updateRoom();

    // Shows the treasure chest in treasure room
    if (roomNav->getCurrentRoom()->getName() == "treasureRoom") {
        treasureChestLabel->show();
        bagLabel->show();
    } else {
        treasureChestLabel->hide();
    }

    if(roomNav->getCurrentRoom()->getName() == "captainRoom"){
        keyLabel->show();
        bagLabel->show();
    }else{
        keyLabel->hide();
    }
    if(roomNav->getCurrentRoom()->getName() != "treasureRoom" && roomNav->getCurrentRoom()->getName() != "captainRoom"){
        bagLabel->hide();
    }

}

void Treasure::resetInventory() {
    inventory = Inventory<QString>();
    saveInventory();
}

void Treasure::saveInventory() {
    inventory.saveToFile("/Users/alisiakazimierek/MyRepos/Zork/InventoryBag.txt");
}

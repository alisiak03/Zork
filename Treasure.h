//
// Created by Alisia Kazimierek on 03/06/2024.
//

#ifndef ZORK_TREASURE_H
#define ZORK_TREASURE_H
#include "MainWindow.h"
#include <QMessageBox>
#include "ClickableLabel.h"
#include "Inventory.h"

class Treasure : public MainWindow {
    Q_OBJECT

public:
    explicit Treasure(QWidget *parent = nullptr);
    ~Treasure();

private slots:
    void handleTreasureChestClicked();
    void handleKeyClicked();
    void handleBagClicked();

protected:
    void updateRoom() override; //to add treasure chest

private:
    ClickableLabel* treasureChestLabel;
    ClickableLabel* keyLabel;
    ClickableLabel* bagLabel;
    Inventory<QString> inventory;

    void saveInventory();
    void loadInventory();
    void resetInventory();

};


#endif //ZORK_TREASURE_H

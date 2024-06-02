//
// Created by Alisia Kazimierek on 09/05/2024.
//

#include "Room.h"
Room::Room(const QString &name, const QString &imagePath) : name(name), imagePath(imagePath){}


QString Room::getImagePath() const {
    return imagePath;
}

QString Room::getName() const {
    return name;
}

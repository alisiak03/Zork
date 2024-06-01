//
// Created by Alisia Kazimierek on 09/05/2024.
//

#include "Room.h"
Room::Room(const QString &imagePath) : imagePath(imagePath){}

QString Room::getImagePath() const {
    return imagePath;
}

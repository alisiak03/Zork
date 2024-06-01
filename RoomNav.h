//
// Created by Alisia Kazimierek on 14/05/2024.
//

#ifndef ZORK_ROOMNAV_H
#define ZORK_ROOMNAV_H
#include "Room.h"
#include <QMap>
#include<QString>

class RoomNav {
public:
    RoomNav();
    Room* getCurrentRoom() const;
    void goToRoom(const QString &direction);

private:
    QMap<QString, Room*> rooms;
    Room* currentRoom;
};


#endif //ZORK_ROOMNAV_H

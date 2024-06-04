#ifndef ZORK_ROOMNAV_H
#define ZORK_ROOMNAV_H

#include "Room.h"
#include <QMap>
#include <QString>

class RoomNav {
public:
    RoomNav(); // Default constructor
    Room* getCurrentRoom() const;
    void goToRoom(const QString &direction);

private:
    QMap<QString, Room*> rooms;
    Room* currentRoom;
};

#endif // ZORK_ROOMNAV_H
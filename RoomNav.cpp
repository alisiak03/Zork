//
// Created by Alisia Kazimierek on 14/05/2024.
//

#include "RoomNav.h"
RoomNav::RoomNav() {
    rooms["start"] = new Room("/Users/alisiakazimierek/MyRepos/Zork/Jail.png");
    rooms["treasureRoom"] = new Room("/Users/alisiakazimierek/MyRepos/Zork/TreasureRoom.png");
    rooms["captainRoom"] = new Room("/Users/alisiakazimierek/MyRepos/Zork/CaptainsRoom.png");
    rooms["Won"] = new Room("/Users/alisiakazimierek/MyRepos/Zork/Won.png");

    currentRoom = rooms["start"];
}
    Room* RoomNav::getCurrentRoom() const {
        return currentRoom;
    }

    void RoomNav::goToRoom(const QString &direction){
        if(rooms.contains(direction)){
            currentRoom = rooms[direction];
        }
    }



//
// Created by Alisia Kazimierek on 09/05/2024.
//

#ifndef ZORK_ROOM_H
#define ZORK_ROOM_H

#include <QtWidgets>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <memory>


using namespace std;
class room;
typedef unique_ptr<room> RoomPtr;
class Room {
public:
    Room(QString name , QString description) : name(name) , description(description){}
    QString name;
    QString description;
    map<QString, Room*> exits;
    ;
};

//Parsing data for rooms from a text file
array<RoomPtr, 10>


#endif //ZORK_ROOM_H

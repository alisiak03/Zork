//
// Created by Alisia Kazimierek on 09/05/2024.
//

#ifndef ZORK_ROOM_H
#define ZORK_ROOM_H
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Room {
private :
    string name;
    string description;
    vector<string> exits;

public:
    void roomInfo();
    static vector<string> roomNames;
};
#endif //ZORK_ROOM_H

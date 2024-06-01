//
// Created by Alisia Kazimierek on 09/05/2024.
//

#include "Room.h"


//void Room :: roomInfo(){
//    const int size = 8;
//    Room arr[size];
//
//    ifstream infile("/Users/alisiakazimierek/MyRepos/Zork/RoomData.txt");
//    if (!infile.is_open()) {
//        cerr << "Failed to open file for reading.\n";
//        return ;
//    }
//    for (int i = 0; i < size; ++i) {
//        //rooms
//        getline(infile >> ws, arr[i].name, ':');
//        getline(infile >> ws, arr[i].description, ':');
//
//        string exitsLine;
//        getline(infile >> ws, exitsLine);
//        stringstream ss(exitsLine);
//        string exit;
//        while (getline(ss, exit, ',')) {
//            arr[i].exits.push_back(exit);
//
//            }
//        }
//
//
//        infile.close();// Close the file
//
//
//        cout << "Room Data:\n";
//        for (int i = 0; i < size; ++i) {
//            cout << "Room Name: " << arr[i].name << endl;
//            cout << "Description: " << arr[i].description << endl;
//            cout << "Exits:";
//            for (const auto &exit : arr[i].exits) {
//                cout << " " << exit;
//            }
//            cout << endl << endl;
//        }
//    }
//

void Room::roomInfo() {
    const int size = 8;
    rooms.clear(); // Clear existing rooms before populating

    std::ifstream infile("/Users/alisiakazimierek/MyRepos/Zork/RoomData.txt");
    if (!infile.is_open()) {
        std::cerr << "Failed to open file for reading.\n";
        return;
    }

    for (int i = 0; i < size; ++i) {
        Room room;
        // Read room data
        getline(infile >> std::ws, room.name, ':');
        getline(infile >> std::ws, room.description, ':');

        std::string exitsLine;
        getline(infile >> std::ws, exitsLine);
        std::stringstream ss(exitsLine);
        std::string exit;
        while (getline(ss, exit, ',')) {
            room.exits.push_back(exit);
        }

        rooms.push_back(room); // Add room to the vector
    }

    infile.close();
}

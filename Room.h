//
// Created by Alisia Kazimierek on 09/05/2024.
//

#ifndef ZORK_ROOM_H
#define ZORK_ROOM_H
#include <QString>
using namespace std;

class Room {
private :
    QString imagePath;
    QString name;

public:
    Room(const QString &name, const QString& imagePath);
    QString getImagePath() const;
    QString getName() const;
};
#endif //ZORK_ROOM_H

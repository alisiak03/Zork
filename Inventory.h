//
// Created by Alisia Kazimierek on 03/06/2024.
//

#ifndef ZORK_INVENTORY_H
#define ZORK_INVENTORY_H

#include <set>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDebug>

template<typename T>
class Inventory {
public:
    Inventory() = default;
    void addItem(const T &item);
    bool hasItem(const T &item) const;
    bool saveToFile(const QString &filename) const;
private:
    std::set<T> items;

};
template<typename T>
void Inventory<T>::addItem(const T &item) {
        items.insert(item);
}

template<typename T>
bool Inventory<T>::hasItem(const T &item) const{
    return items.find(item) != items.end();
}

template<typename T>
bool Inventory<T>::saveToFile(const QString &filename) const {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file for writing:" << filename;
        return false;
    }

    QTextStream out(&file);
    for (const auto &item : items) {
        out << item << "\n";
    }

    file.close();
    qDebug() << "Inventory saved to file:" << filename;
    return true;
}




#endif //ZORK_INVENTORY_H

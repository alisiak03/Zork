#ifndef ITEM_H
#define ITEM_H

#include <iostream>

// future implements , maybe adding money to the game with value, also give the key a value
union ItemValue {
    int intValue;
    float floatValue;

    ItemValue() {}
    ~ItemValue() {}
};
class Item {
public:
    enum ItemType {
        INT, FLOAT
    } type;
    ItemValue value;

    Item(int val) : type(INT) { value.intValue = val; }

    Item(float val) : type(FLOAT) { value.floatValue = val; }

    friend std::ostream &operator<<(std::ostream &os, const Item &item);
};
std::ostream &operator<<(std::ostream &os, const Item &item) {
    os << "Item(";
    if (item.type == Item::INT) os << "intValue: " << item.value.intValue;
    if (item.type == Item::FLOAT) os << "floatValue: " << item.value.floatValue;
    os << ")";
    return os;
}


#endif // ITEM_H
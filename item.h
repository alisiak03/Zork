#ifndef ITEM_H
#define ITEM_H



// future implements , maybe adding money to the game with value, also give the key a value
union ItemValue {
    int intValue;
    float floatValue;

    ItemValue() {}
    ~ItemValue() {}
};



#endif // ITEM_H
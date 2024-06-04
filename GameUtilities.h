//
// Created by Alisia Kazimierek on 04/06/2024.
//

#ifndef ZORK_GAMEUTILITIES_H
#define ZORK_GAMEUTILITIES_H
#include <QString>

namespace GameUtilities {
    void showMessage(const QString& message);
    QString getFormattedText(const QString& text);
    const QString gameTitle = "Pirate Adventure";
};


#endif //ZORK_GAMEUTILITIES_H

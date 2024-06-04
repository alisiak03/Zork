//
// Created by Alisia Kazimierek on 04/06/2024.
//

#ifndef ZORK_BUTTONSTYLING_H
#define ZORK_BUTTONSTYLING_H

#include <QString>
class ButtonStyling {
public:
    ButtonStyling() = default;
    virtual ~ButtonStyling() = default;

    QString getButton1Style() const;
    QString getButton2Style() const;
    QString getQuizButtonStyle() const;
};


#endif //ZORK_BUTTONSTYLING_H

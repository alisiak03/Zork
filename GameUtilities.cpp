//
// Created by Alisia Kazimierek on 04/06/2024.
//

#include "GameUtilities.h"
#include <QMessageBox>

namespace GameUtilities{
    void showMessage(const QString& message){
        QMessageBox::information(nullptr, "Message", message);
    }

    QString getFormattedText(const QString& text){
        QString formattedText = QString("<div style='font-size: 24px; font-family: Papyrus;'>** ") + text + QString(" **</div");
        return formattedText;
    }
}
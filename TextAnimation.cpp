//
// Created by Alisia Kazimierek on 02/06/2024.
//

#include "TextAnimation.h"

TextAnimation::TextAnimation(QObject *parent)
        : QObject(parent), targetLabel(nullptr), currentCharIndex(0){
    connect(&TextAnimationTimer, &QTimer::timeout, this, &TextAnimation::updateAnimatedText);
}

void TextAnimation::startAnimation(QLabel *label, const QString &text, int interval) {
    targetLabel = label;
    fulltext = text;
    currentCharIndex = 0;
    targetLabel->clear();
    TextAnimationTimer.start(interval);
}
void TextAnimation::updateAnimatedText() {
    if (currentCharIndex < fulltext.length()) {
        targetLabel->setText(fulltext.left(currentCharIndex));
        currentCharIndex++;
    } else {
        TextAnimationTimer.stop();
    }
}

void TextAnimation::stopAnimation() {
    TextAnimationTimer.stop();
    if(targetLabel){
        targetLabel->clear();
    }
}
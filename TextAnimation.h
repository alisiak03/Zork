//
// Created by Alisia Kazimierek on 02/06/2024.
//

#ifndef ZORK_TEXTANIMATION_H
#define ZORK_TEXTANIMATION_H
#include <QObject>
#include <QLabel>
#include <QTimer>

class TextAnimation : public QObject {
    Q_OBJECT

public:
    explicit TextAnimation(QObject *parent = nullptr);
    void startAnimation(QLabel *label, const QString &text, int interval = 50 );
    void stopAnimation();

private slots:
    void updateAnimatedText();

private:
    QLabel *targetLabel;
    QString fulltext;
    int currentCharIndex;
    QTimer TextAnimationTimer;
};


#endif //ZORK_TEXTANIMATION_H

//
// Created by Alisia Kazimierek on 03/06/2024.
//
#include "ClickableLabel.h"

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent) {}

ClickableLabel::~ClickableLabel() {}

void ClickableLabel::mousePressEvent(QMouseEvent *event) {
    emit clicked();
    QLabel::mousePressEvent(event);
}